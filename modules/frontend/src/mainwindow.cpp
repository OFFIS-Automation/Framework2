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

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralwidget->hide();

    setWindowTitle("OFFIS Automation Framework");
    setWindowIcon(QIcon(":/img/icon.ico"));
    setDockNestingEnabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addDockWidget(Qt::DockWidgetArea area, QDockWidget *dockwidget, const QString& group)
{
    QMainWindow::addDockWidget(area, dockwidget);
    updateDockWidget(dockwidget);
}

void MainWindow::addDockWidget(Qt::DockWidgetArea area, QDockWidget *dockwidget, Qt::Orientation orientation, const QString& group)
{
    QMainWindow::addDockWidget(area, dockwidget, orientation);
    updateDockWidget(dockwidget);
}

void MainWindow::removeDockWidget(QDockWidget *dockwidget)
{
    QMainWindow::removeDockWidget(dockwidget);
}

QMenu &MainWindow::getMenu(QString name, QStringList subMenuList)
{
    QMenuBar *bar = menuBar();
    QMenu* menu = 0;
    foreach(QAction* action, bar->actions()){
        if(action->text() == name && action->menu() != 0){
            menu = action->menu();
        }
    }

    if(menu == 0){
        // Menu with given name not found, create a new one
        menu = new QMenu(name);
        bar->insertMenu(ui->menuHelp->menuAction(), menu);
    }

    // Search submenu
    foreach(QString subMenuName, subMenuList){
        bool found = false;
        foreach(QAction* action, menu->actions()){
            if(action->text() == subMenuName && action->menu() != 0){
                found = true;
                menu = action->menu();
                break;
            }
        }
        if(!found){
            // Submenu with given name not found, create a new one
            menu = menu->addMenu(subMenuName);
        }
    }
    return *menu;
}

void MainWindow::addToolBar(Qt::ToolBarArea area, QToolBar *toolbar, const QString &group)
{
    QMainWindow::addToolBar(area, toolbar);
}

void MainWindow::addToolBar(QToolBar *toolbar, const QString& group)
{
    QMainWindow::addToolBar(toolbar);
}

void MainWindow::updateDockWidget(QDockWidget *dockwidget)
{
    dockwidget->setAllowedAreas(Qt::AllDockWidgetAreas);
    dockwidget->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetClosable);
}
