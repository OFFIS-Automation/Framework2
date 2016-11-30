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

QT       += core gui widgets

TARGET = Framework
TEMPLATE = app

include(../../shared/pathes.pro)

BUILD_NUMBER_EXISTS=$$(BUILD_NUMBER)
isEmpty(BUILD_NUMBER_EXISTS){
    DEFINES += BUILD_VERSION=0
} else {
    DEFINES += BUILD_VERSION=$$(BUILD_NUMBER)
}

RC_FILE = appIcon.rc

DESTDIR = $${targetDir}

INCLUDEPATH += $$(OFFIS_DEVELOPMENT_ENVIRONMENT)/winSparkle/include

CONFIG(debug, debug|release) {
    LIBS += -L$$(OFFIS_DEVELOPMENT_ENVIRONMENT)/winSparkle/lib/debug -lWinSparkle
} else {
    LIBS += -L$$(OFFIS_DEVELOPMENT_ENVIRONMENT)/winSparkle/lib/release -lWinSparkle
}

SOURCES += src/main.cpp\
    src/mainwindow.cpp\
    src/application.cpp

HEADERS += includes/GuiPluginInterface.h \
    src/mainwindow.h\
    src/application.h\
    src/version.h

FORMS   += src/mainwindow.ui

dlls.path  =  $${DESTDIR}
dllPlatforms.path   += $${DESTDIR}/platforms
dllImageformats.path+= $${DESTDIR}/imageformats/
dllIconengines.path += $${DESTDIR}/iconengines/
dllWinsparkle.path  += $${DESTDIR}/

dlls.files += $$[QT_INSTALL_BINS]/d3dcompiler_47.dll
dlls.files += $$[QT_INSTALL_BINS]/opengl32sw.dll

CONFIG(debug, debug|release) {
    dlls.files += $$[QT_INSTALL_BINS]/icudt5*.dll
    dlls.files += $$[QT_INSTALL_BINS]/icuin5*.dll
    dlls.files += $$[QT_INSTALL_BINS]/icuuc5*.dll

    dlls.files += $$[QT_INSTALL_BINS]/libGLESv2d.dll
    dlls.files += $$[QT_INSTALL_BINS]/libEGLd.dll

    dlls.files += $$[QT_INSTALL_BINS]/Qt5Cored.dll
    dlls.files += $$[QT_INSTALL_BINS]/Qt5Guid.dll
    dlls.files += $$[QT_INSTALL_BINS]/Qt5Networkd.dll
    dlls.files += $$[QT_INSTALL_BINS]/Qt5Multimediad.dll
    dlls.files += $$[QT_INSTALL_BINS]/Qt5OpenGld.dll
    dlls.files += $$[QT_INSTALL_BINS]/Qt5PrintSupportd.dll
    dlls.files += $$[QT_INSTALL_BINS]/Qt5SerialPortd.dll
    dlls.files += $$[QT_INSTALL_BINS]/Qt5Svgd.dll
    dlls.files += $$[QT_INSTALL_BINS]/Qt5Widgetsd.dll

    dlls.files    += $$(OFFIS_DEVELOPMENT_ENVIRONMENT)/winSparkle/bin/debug/WinSparkle.dll

    dllPlatforms.files  += $$[QT_INSTALL_PLUGINS]/platforms/qwindowsd.dll

    dllImageformats.files  += $$[QT_INSTALL_PLUGINS]/imageformats/qddsd.dll
    dllImageformats.files  += $$[QT_INSTALL_PLUGINS]/imageformats/qgifd.dll
    dllImageformats.files  += $$[QT_INSTALL_PLUGINS]/imageformats/qicnsd.dll
    dllImageformats.files  += $$[QT_INSTALL_PLUGINS]/imageformats/qicod.dll
    dllImageformats.files  += $$[QT_INSTALL_PLUGINS]/imageformats/jpegd.dll
    dllImageformats.files  += $$[QT_INSTALL_PLUGINS]/imageformats/qtgad.dll
    dllImageformats.files  += $$[QT_INSTALL_PLUGINS]/imageformats/qtiffd.dll
    dllImageformats.files  += $$[QT_INSTALL_PLUGINS]/imageformats/qwbmpd.dll
    dllImageformats.files  += $$[QT_INSTALL_PLUGINS]/imageformats/qwebpd.dll

    dllIconengines.files  += $$[QT_INSTALL_PLUGINS]/iconengines/qsvgicond.dll
} else {
    dlls.files += $$[QT_INSTALL_BINS]/icudt5*.dll
    dlls.files += $$[QT_INSTALL_BINS]/icuin5*.dll
    dlls.files += $$[QT_INSTALL_BINS]/icuuc5*.dll

    dlls.files += $$[QT_INSTALL_BINS]/libGLESv2.dll
    dlls.files += $$[QT_INSTALL_BINS]/libEGL.dll

    dlls.files += $$[QT_INSTALL_BINS]/Qt5Core.dll
    dlls.files += $$[QT_INSTALL_BINS]/Qt5Gui.dll
    dlls.files += $$[QT_INSTALL_BINS]/Qt5Network.dll
    dlls.files += $$[QT_INSTALL_BINS]/Qt5Multimedia.dll
    dlls.files += $$[QT_INSTALL_BINS]/Qt5OpenGl.dll
    dlls.files += $$[QT_INSTALL_BINS]/Qt5PrintSupport.dll
    dlls.files += $$[QT_INSTALL_BINS]/Qt5SerialPort.dll
    dlls.files += $$[QT_INSTALL_BINS]/Qt5Svg.dll
    dlls.files += $$[QT_INSTALL_BINS]/Qt5Widgets.dll

    dlls.files    += $$(OFFIS_DEVELOPMENT_ENVIRONMENT)/winSparkle/bin/release/WinSparkle.dll

    dllPlatforms.files  += $$[QT_INSTALL_PLUGINS]/platforms/qwindows.dll

    dllImageformats.files  += $$[QT_INSTALL_PLUGINS]/imageformats/qdds.dll
    dllImageformats.files  += $$[QT_INSTALL_PLUGINS]/imageformats/qgif.dll
    dllImageformats.files  += $$[QT_INSTALL_PLUGINS]/imageformats/qicns.dll
    dllImageformats.files  += $$[QT_INSTALL_PLUGINS]/imageformats/qico.dll
    dllImageformats.files  += $$[QT_INSTALL_PLUGINS]/imageformats/jpeg.dll
    dllImageformats.files  += $$[QT_INSTALL_PLUGINS]/imageformats/qtga.dll
    dllImageformats.files  += $$[QT_INSTALL_PLUGINS]/imageformats/qtiff.dll
    dllImageformats.files  += $$[QT_INSTALL_PLUGINS]/imageformats/qwbmp.dll
    dllImageformats.files  += $$[QT_INSTALL_PLUGINS]/imageformats/qwebp.dll

    dllIconengines.files  += $$[QT_INSTALL_PLUGINS]/iconengines/qsvgicon.dll
}
INSTALLS   += dlls dllPlatforms dllImageformats dllIconengines
