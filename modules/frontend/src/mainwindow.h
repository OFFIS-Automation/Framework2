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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDockWidget>

#include <GuiPluginInterface.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public MainWindowInterface
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void addDockWidget(Qt::DockWidgetArea area, QDockWidget *dockwidget, const QString& group);
    void addDockWidget(Qt::DockWidgetArea area, QDockWidget *dockwidget, Qt::Orientation orientation, const QString& group);
    void removeDockWidget(QDockWidget *dockwidget);
    void addToolBar(Qt::ToolBarArea area, QToolBar *toolbar, const QString& group);
    void addToolBar(QToolBar *toolbar, const QString& group);
    QMenu &getMenu(QString name, QStringList subMenuList = QStringList());

private:
    void updateDockWidget(QDockWidget *dockwidget);
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
