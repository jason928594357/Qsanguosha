QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Qsanguosha
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    src/dialog/mainwindow.cpp \
    src/main.cpp

HEADERS += \
    src/dialog/mainwindow.h

FORMS += \
    src/dialog/mainwindow.ui

INCLUDEPATH += src/dialog

RC_FILE += resource/icon.rc

TRANSLATIONS += builds/sanguosha.ts
