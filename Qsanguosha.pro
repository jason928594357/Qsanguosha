QT       += core gui opengl script

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Qsanguosha
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    src/dialog/mainwindow.cpp \
    src/main.cpp \
    src/core/settings.cpp \
    src/ui/startscene.cpp \
    src/ui/qsanselectableitem.cpp \
    src/ui/button.cpp \
    src/ui/roomscene.cpp \
    src/dialog/cardoverview.cpp \
    src/core/engine.cpp \
    src/core/card.cpp

HEADERS += \
    src/dialog/mainwindow.h \
    src/core/settings.h \
    src/ui/startscene.h \
    src/ui/qsanselectableitem.h \
    src/ui/button.h \
    src/ui/roomscene.h \
    src/dialog/cardoverview.h \
    src/core/engine.h \
    src/core/card.h

FORMS += \
    src/dialog/mainwindow.ui \
    src/dialog/cardoverview.ui

INCLUDEPATH += src/dialog
INCLUDEPATH += src/core
INCLUDEPATH += src/ui

RC_FILE += resource/icon.rc

TRANSLATIONS += builds/sanguosha.ts
