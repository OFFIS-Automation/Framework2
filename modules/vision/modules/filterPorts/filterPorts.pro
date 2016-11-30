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

include(../../../../shared/pathes.pro)
include(../../../../shared/opencv.pro)

TARGET = visionFilterPorts
DESTDIR = $${targetDir}/plugins

TEMPLATE = lib
CONFIG += dll

DEFINES += FILTER_PORTS_LIBRARY

INCLUDEPATH += $$PWD/../../include

LIBS += -L$${targetDir}/plugins -lvisionFilter

SOURCES += src/BooleanPort.cpp \
    src/ColorPort.cpp \
    src/DateTimePort.cpp \
    src/DepthMap.cpp \
    src/DepthMapPort.cpp \
    src/DirectoryPort.cpp \
    src/FilePort.cpp \
    src/GrayImage.cpp \
    src/Histogram.cpp \
    src/HistogramPort.cpp \
    src/ImagePort.cpp \
    src/IntegerPort.cpp \
    src/LinePort.cpp \
    src/PhysicalSizePort.cpp \
    src/PointPort.cpp \
    src/PolygonPort.cpp \
    src/Pose2d.cpp \
    src/PosePort.cpp \
    src/RealPort.cpp \
    src/RectPort.cpp \
    src/RgbaImage.cpp \
    src/RgbImage.cpp \
    src/StringPort.cpp

HEADERS += ../../include/ports/BooleanPort.h \
    ../../include/ports/ColorPort.h \
    ../../include/ports/DateTimePort.h \
    ../../include/ports/DepthMap.h \
    ../../include/ports/DepthMapPort.h \
    ../../include/ports/DirectoryPort.h \
    ../../include/ports/FilePort.h \
    ../../include/ports/GrayImage.h \
    ../../include/ports/Histogram.h \
    ../../include/ports/HistogramPort.h \
    ../../include/ports/ImagePort.h \
    ../../include/ports/IntegerPort.h \
    ../../include/ports/LinePort.h \
    ../../include/ports/OverlayPort.h \
    ../../include/ports/PhysicalSizePort.h \
    ../../include/ports/PointPort.h \
    ../../include/ports/PolygonPort.h \
    ../../include/ports/Pose2d.h \
    ../../include/ports/PosePort.h \
    ../../include/ports/RealPort.h \
    ../../include/ports/RectPort.h \
    ../../include/ports/RgbaImage.h \
    ../../include/ports/RgbImage.h \
    ../../include/ports/StringPort.h \
    ../../include/ports/FilterPortsGlobal.h

