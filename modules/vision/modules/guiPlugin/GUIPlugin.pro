# OFFIS Automation Framework
# Copyright (C) 2013-2016 OFFIS e.V.
# 
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http:#www.gnu.org/licenses/>.

#-------------------------------------------------
#
# Project created by QtCreator 2011-03-01T15:35:22
#
#-------------------------------------------------

include(../../../../shared/pathes.pro)
include(../../../../shared/opencv.pro)

TARGET = visionGUIPlugin
DESTDIR = $${targetDir}/plugins

TEMPLATE = lib
CONFIG += dll

QT += core gui widgets

INCLUDEPATH += $$PWD/../../include
INCLUDEPATH += $$PWD/../../../frontend/include

include.path    = $${DESTDIR}/vision/include
include.files  += $$PWD/../../include/filter
include.files  += $$PWD/../../include/ports
INSTALLS       += include

opencv.path     = $${DESTDIR}/vision/opencv
opencv.files   += $$CVINCLUDEDIR
opencv.files   += $$CVLIBDIR
opencv.files   += $$CVBINDIR
INSTALLS       += opencv

SOURCES += src/PluginContainer.cpp \
    src/VisionGuiPlugin.cpp \
    src/VisionSingleton.cpp \
    src/VisionToolbar.cpp \
    src/CreatePlugin/CreatePluginDialog.cpp \
    src/FilterConnect/FilterConnectWidget.cpp \
    src/FilterConnect/FilterHeaderWidget.cpp \
    src/FilterConnect/FilterInputPortWidget.cpp \
    src/FilterConnect/FilterOutputPortWidget.cpp \
    src/FilterConnect/FilterPortWidget.cpp \
    src/FilterConnect/FilterSortingArea.cpp \
    src/FilterConnect/FilterWidget.cpp \
    src/FilterConnect/ProcessorInputPortWidget.cpp \
    src/FilterConnect/ProcessorInputsWidget.cpp \
    src/FilterConnect/ProcessorOutputPortWidget.cpp \
    src/FilterConnect/ProcessorOutputsWidget.cpp \
    src/FilterInfo/FilterInfoPortEditWidget.cpp \
    src/FilterInfo/FilterInfoWidget.cpp \
    src/FilterSearch/CreateMakroFilterDialog.cpp \
    src/FilterSearch/FilterSearchFlowLayout.cpp \
    src/FilterSearch/FilterSearchTree.cpp \
    src/FilterSearch/FilterSearchTreeItem.cpp \
    src/FilterSearch/FilterSearchWidget.cpp \
    src/ProcessorConnect/Arrow.cpp \
    src/ProcessorConnect/ChangeProcessorDialog.cpp \
    src/ProcessorConnect/DiagramScene.cpp \
    src/ProcessorConnect/NameDialog.cpp \
    src/ProcessorConnect/ProcessorItem.cpp \
    src/ProcessorConnect/ProcessorsWidget.cpp

HEADERS +=  src/PluginContainer.h \
    src/VisionGuiPlugin.h \
    src/VisionSingleton.h \
    src/VisionToolbar.h \
    src/CreatePlugin/CreatePluginDialog.h \
    src/FilterConnect/FilterConnectWidget.h \
    src/FilterConnect/FilterHeaderWidget.h \
    src/FilterConnect/FilterInputPortWidget.h \
    src/FilterConnect/FilterOutputPortWidget.h \
    src/FilterConnect/FilterPortWidget.h \
    src/FilterConnect/FilterSortingArea.h \
    src/FilterConnect/FilterWidget.h \
    src/FilterConnect/ProcessorInputPortWidget.h \
    src/FilterConnect/ProcessorInputsWidget.h \
    src/FilterConnect/ProcessorOutputPortWidget.h \
    src/FilterConnect/ProcessorOutputsWidget.h \
    src/FilterInfo/FilterInfoPortEditWidget.h \
    src/FilterInfo/FilterInfoWidget.h \
    src/FilterSearch/CreateMakroFilterDialog.h \
    src/FilterSearch/FilterSearchFlowLayout.h \
    src/FilterSearch/FilterSearchTree.h \
    src/FilterSearch/FilterSearchTreeItem.h \
    src/FilterSearch/FilterSearchWidget.h \
    src/ProcessorConnect/Arrow.h \
    src/ProcessorConnect/ChangeProcessorDialog.h \
    src/ProcessorConnect/DiagramScene.h \
    src/ProcessorConnect/NameDialog.h \
    src/ProcessorConnect/ProcessorItem.h \
    src/ProcessorConnect/ProcessorsWidget.h

FORMS += src/VisionToolbar.ui \
    src/CreatePlugin/CreatePluginDialog.ui \
    src/FilterConnect/FilterConnectWidget.ui \
    src/FilterConnect/FilterPortWidget.ui \
    src/FilterConnect/FilterSortingArea.ui \
    src/FilterConnect/FilterWidget.ui \
    src/FilterInfo/FilterInfoPortEditWidget.ui \
    src/FilterInfo/FilterInfoWidget.ui \
    src/FilterSearch/CreateMakroFilterDialog.ui \
    src/FilterSearch/FilterSearchWidget.ui \
    src/ProcessorConnect/ChangeProcessorDialog.ui \
    src/ProcessorConnect/ProcessorsWidget.ui

