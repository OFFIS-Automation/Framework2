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

TARGET = visionFilter
DESTDIR = $${targetDir}/plugins

TEMPLATE = lib
CONFIG += dll

DEFINES += FILTER_LIBRARY

INCLUDEPATH += $$PWD/../../include

SOURCES += src/BasePort.cpp \
    src/Filter.cpp \
    src/InputPortPrivate.cpp \
    src/OutputPortPrivate.cpp \
    src/Port.cpp \
    src/SrcFilter.cpp \
    src/TypeInfoHelper.cpp \
    src/UserFilter.cpp

HEADERS += src/BasePort.h \
    src/InputPortPrivate.h \
    src/OutputPortPrivate.h \
    src/PortData.h \
    src/UserFilterPrivate.h \
    ../../include/core/Filter.h \
    ../../include/core/FilterTypeInfo.h \
    ../../include/core/InputPort.h \
    ../../include/core/OutputPort.h \
    ../../include/core/PortInfo.h \
    ../../include/core/PortListener.h \
    ../../include/core/ProcessorInfo.h \
    ../../include/core/SrcFilter.h \
    ../../include/filter/FilterTypeInfoHelper.h \
    ../../include/filter/InputPortMode.h \
    ../../include/filter/Port.h \
    ../../include/filter/UserFilter.h \
    ../../include/filter/FilterGlobal.h
