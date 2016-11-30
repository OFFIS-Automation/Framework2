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

#ifndef GUIPLUGININTERFACE_H
#define GUIPLUGININTERFACE_H

class GuiPluginInterface
{
public:
    virtual QString getName() const = 0;
    virtual void initialize(const QString& pluginDir) = 0;
    virtual void deinitialize() = 0;
    virtual void addElements(MainWindowInterface* mainWindow) = 0;
    virtual void loadProject(const QString& projectFile) { Q_UNUSED(projectFile); }
    virtual void closeProject() {}
};
#define GuiPluginInterface_iid "com.offis.framework.GuiPluginInterface/1.1"
Q_DECLARE_INTERFACE(GuiPluginInterface, GuiPluginInterface_iid)

#endif // GUIPLUGININTERFACE_H
