#-------------------------------------------------
#
# Project created by QtCreator 2019-11-27T09:45:26
#
#-------------------------------------------------

QT       += widgets core gui

TARGET = peony-batch-rename-plugin
TEMPLATE = lib

DEFINES += PEONYBATCHRENAMEMENUPLUGIN_LIBRARY

include(../common.pri)

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += debug link_pkgconfig plugin

PKGCONFIG += peony

TRANSLATIONS = translations/peony-batch-rename-extension_zh_CN.ts \
               translations/peony-batch-rename-extension_tr.ts \

#DESTDIR += ../testdir

SOURCES += \
        batch-rename-plugin.cpp \
        rename-page.cpp

HEADERS += \
        rename-page.h \
        ui-rename-page.h \
        batch-rename-plugin.h \
        peony-batch-rename-plugin_global.h

unix {
    target.path = $$[QT_INSTALL_LIBS]/peony-extensions
    INSTALLS += target
}

RESOURCES += \
    peony-batch-rename.qrc
