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

#ifndef VISIONGUIPLUGIN_H
#define VISIONGUIPLUGIN_H

#include <GuiPluginInterface.h>

class FilterSearchWidget;
class FilterInfoWidget;
class FilterConnectWidget;
class ProcessorsWidget;

class VisionToolbar;
class VisionInterface;

class QXmlStreamWriter;
class QXmlStreamReader;

class VisionGuiPlugin : public QObject, public GuiPluginInterface
{
public:
    VisionGuiPlugin();
    virtual QString getName() const { return "VisionGuiInterface"; }
    virtual void setModelInterface(const QString& name, QObject* modelInterface);
    virtual bool requirementsMet();
    virtual void initialize(const QString& pluginDir);
    virtual void deinitialize();
    virtual void addElements(MainWindowInterface* mainWindow);
    virtual QObject* getConnectObject() { return this; }
    virtual void setGuiInterface(const QString &name, QObject *guiInterface);
    virtual void loadProject(const QString &projectFile);
    virtual void closeProject();

protected slots:
    virtual void writeXmlConfig(QXmlStreamWriter &writer);
    virtual void readXmlConfig(const QString &reader);
    void reloadPlugins();

signals:
    void saveGraphString(QString& string);
    void loadGraphString(const QString& string);
    void filterSelected(int filterId);
    void portSelected(int filterId, const QString& portId);

private:
    VisionInterface* mInterface;
    Q_OBJECT
    Q_INTERFACES(GuiPluginInterface)
    Q_PLUGIN_METADATA(IID GuiPluginInterface_iid)

    FilterSearchWidget* search;
    FilterConnectWidget* connections;
    ProcessorsWidget* processors;
    FilterInfoWidget* info;

    VisionToolbar* toolbar;
};

#endif // VISIONGUIPLUGIN_H
