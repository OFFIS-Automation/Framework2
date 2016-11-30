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

#include "CreateMakroFilterDialog.h"
#include "ui_CreateMakroFilterDialog.h"

CreateMakroFilterDialog::CreateMakroFilterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateMakroFilterDialog)
{
    ui->setupUi(this);

    // Hide help button
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

CreateMakroFilterDialog::~CreateMakroFilterDialog()
{
    delete ui;
}

QString CreateMakroFilterDialog::name() const
{
    return ui->name->text();
}