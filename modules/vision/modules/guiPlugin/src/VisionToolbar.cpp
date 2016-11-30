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

#include "VisionToolbar.h"
#include "ui_VisionToolbar.h"

#include "VisionSingleton.h"
#include <QFileDialog>

#include "CreatePlugin/CreatePluginDialog.h"
VisionToolbar::VisionToolbar(QWidget *parent) :
    QToolBar(parent),
    ui(new Ui::VisionToolbar)
{
    ui->setupUi(this);
    connect(&VisionSingleton::instance(), SIGNAL(executionStarted()), SLOT(onExecutionStarted()));
    connect(&VisionSingleton::instance(), SIGNAL(executionFinished()), SLOT(onExecutionFinished()));
}

void VisionToolbar::initMenu(QMenu *visionMenu)
{
    if(visionMenu->actions().size() > 0)
    {
        visionMenu->addSeparator();
    }
    visionMenu->addAction(ui->actionCreatePlugin);
    visionMenu->addAction(ui->actionReloadPlugins);
}

VisionToolbar::~VisionToolbar()
{
    delete ui;
}

void VisionToolbar::on_actionCreatePlugin_triggered()
{
    CreatePluginDialog dialog;
    if(dialog.exec() == QDialog::Accepted)
        dialog.createPlugin();
}

void VisionToolbar::on_actionReloadPlugins_triggered()
{
    emit reloadPlugins();
}

void VisionToolbar::onExecutionStarted()
{
    ui->actionReloadPlugins->setEnabled(false);
}

void VisionToolbar::onExecutionFinished()
{
    ui->actionReloadPlugins->setEnabled(true);
}
