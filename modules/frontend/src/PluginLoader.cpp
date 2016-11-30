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

#include "PluginLoader.h"

#include <GuiPluginInterface.h>

#include <QDir>
#include <QPluginLoader>
#include <QApplication>

PluginLoader::PluginLoader(const QString &path)
{
    mPath = path;
}

PluginLoader::~PluginLoader()
{
    unload();
}

void PluginLoader::load()
{
    // Change to plugin directory
    QDir current = QDir::current();
    QDir pluginDir(mPath);
    QDir::setCurrent(pluginDir.canonicalPath());

    QStringList pluginFiles = pluginDir.entryList(QStringList("*.dll") << "*.dylib" << "*.so", QDir::Files | QDir::NoDotAndDotDot | QDir::NoSymLinks);
    foreach(QString pluginFile, pluginFiles)
    {
        QPluginLoader loader(pluginDir.absoluteFilePath(pluginFile));
        loader.setLoadHints(QLibrary::ResolveAllSymbolsHint);
        QObject *instance = loader.instance();
        if(!instance)
        {
            qDebug() << loader.errorString();
            continue;
        }
        GuiPluginInterface *guiPlugin = qobject_cast<GuiPluginInterface*>(instance);
        if(guiPlugin)
        {
            QString name = guiPlugin->getName();
            mGuiPlugins[name] = guiPlugin;
            mLoadedPlugins.append(pluginDir.absoluteFilePath(pluginFile));
        }
        else
        {
            loader.unload();
        }
    }

    QMapIterator<QString, GuiPluginInterface*> guiPlugins(mGuiPlugins);
    while(guiPlugins.hasNext())
    {
        GuiPluginInterface* guiPlugin = guiPlugins.next().value();
        guiPlugin->initialize(mPath);
    }
    guiPlugins.toFront();

    // Back to previous directory
    QDir::setCurrent(current.canonicalPath());
}

void PluginLoader::configure(MainWindowInterface *mainWindow)
{
    QMapIterator<QString, GuiPluginInterface*> guiPlugins(mGuiPlugins);
    while(guiPlugins.hasNext())
    {
         GuiPluginInterface* guiPlugin = guiPlugins.next().value();
         guiPlugin->addElements(mainWindow);
    }
}

void PluginLoader::unload()
{

}
