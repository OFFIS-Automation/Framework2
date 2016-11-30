// OFFIS Automation Framework
// Copyright (C) 2013-2016 OFFIS e.V.
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <QDir>
#include <QPluginLoader>
#include <QtPlugin>
#include <QSettings>
#include <QApplication>
#include <QXmlStreamWriter>

#include <core/VisionInterface.h>
#include <core/ProcessorInfo.h>
#include <gui/VisionGuiPluginInterface.h>

#include "FilterSearch/FilterSearchWidget.h"
#include "FilterInfo/FilterInfoWidget.h"
#include "FilterConnect/FilterConnectWidget.h"
#include "ProcessorConnect/ProcessorsWidget.h"

#include "VisionGuiPlugin.h"
#include "VisionSingleton.h"
#include "VisionToolbar.h"
#include "PluginContainer.h"

VisionGuiPlugin::VisionGuiPlugin()
{
    mInterface = 0;
}

void VisionGuiPlugin::setModelInterface(const QString& name, QObject* object)
{
    if(mInterface || name != "OlvisCore")
        return;
    mInterface= reinterpret_cast<VisionInterface*>(object);
}

bool VisionGuiPlugin::requirementsMet()
{
    return mInterface != 0;
}

void VisionGuiPlugin::initialize(const QString& pluginDir)
{
    VisionSingleton::setInstance(*mInterface);
    PluginContainer& plugins = PluginContainer::getInstance();
    plugins.loadPlugins(pluginDir + "/VisionGuiPlugins");

    // only const references for models
    const VisionInterface& model = *mInterface;
    connections = new FilterConnectWidget(model);
    search = new FilterSearchWidget(model, connections);
    processors = new ProcessorsWidget();
    info = new FilterInfoWidget(model);
    toolbar = new VisionToolbar();

    // conect inter-gui signals
    connect(connections, SIGNAL(filterSelected(int)), info, SLOT(showFilter(int)));
    connect(connections, SIGNAL(filterSelected(int)), SIGNAL(filterSelected(int)));
    connect(connections, SIGNAL(portSelected(int,QString)), SIGNAL(portSelected(int,QString)));

    connect(processors, SIGNAL(processorSelected(int)), connections, SLOT(selectProcessor(int)));
    connect(toolbar, SIGNAL(reloadPlugins()), SLOT(reloadPlugins()));
    closeProject();
}

void VisionGuiPlugin::deinitialize()
{
}

void VisionGuiPlugin::addElements(MainWindowInterface *mainWindow)
{
    mainWindow->addDockWidget(Qt::LeftDockWidgetArea, search, Qt::Horizontal, tr("Vision"));
    mainWindow->addDockWidget(Qt::LeftDockWidgetArea, connections, Qt::Horizontal, tr("Vision"));
    mainWindow->addDockWidget(Qt::RightDockWidgetArea, info, Qt::Vertical, tr("Vision"));
    mainWindow->addDockWidget(Qt::TopDockWidgetArea, processors, Qt::Horizontal, tr("Vision"));

    toolbar->initMenu(&mainWindow->getMenu("Vision"));
}

void VisionGuiPlugin::setGuiInterface(const QString &name, QObject *guiPlugin)
{
    if(name == "OlvisExecGuiInterface")
    {
        connect(guiPlugin, SIGNAL(pluginsWriteConfigReq(QXmlStreamWriter&)), SLOT(writeXmlConfig(QXmlStreamWriter&)), Qt::DirectConnection);
        connect(guiPlugin, SIGNAL(pluginsReadConfigReq(QString)), SLOT(readXmlConfig(QString)), Qt::DirectConnection);

        connect(this, SIGNAL(saveGraphString(QString&)), guiPlugin, SLOT(saveGraphString(QString&)), Qt::DirectConnection);
        connect(this, SIGNAL(loadGraphString(QString)), guiPlugin, SLOT(loadGraphString(QString)), Qt::DirectConnection);
    }
}

void VisionGuiPlugin::loadProject(const QString & projectFile)
{
    Q_UNUSED(projectFile)

    connections->setEnabled(true);
    search->setEnabled(true);
    processors->setEnabled(true);
    info->setEnabled(true);
    toolbar->setEnabled(true);
}

void VisionGuiPlugin::closeProject()
{
    connections->setEnabled(false);
    search->setEnabled(false);
    processors->setEnabled(false);
    info->setEnabled(false);
    toolbar->setEnabled(false);
}

void VisionGuiPlugin::readXmlConfig(const QString& data)
{
    QXmlStreamReader reader(data);
    reader.readNextStartElement();
    while(reader.readNextStartElement())
    {
        if(reader.name() == getName())
        {
            while (reader.readNextStartElement()) {
                if (reader.name() == "processorsWidget")
                    processors->restoreState(reader);
                else
                    reader.skipCurrentElement();
            }
            break;
        } else {
            reader.skipCurrentElement();
        }
    }
}

void VisionGuiPlugin::reloadPlugins()
{
    QString data;
    emit saveGraphString(data);
    mInterface->clear();
    mInterface->scanPluginDir();
    emit loadGraphString(data);
}

void VisionGuiPlugin::writeXmlConfig(QXmlStreamWriter &writer)
{
    writer.writeStartElement(getName());
    writer.writeStartElement("processorsWidget");
    processors->saveCurrentState(writer);
    writer.writeEndElement();
    writer.writeEndElement();
}
