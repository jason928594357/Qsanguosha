#-------------------------------------------------
#
# Project created by QtCreator 2021-02-11T19:00:10
#
#-------------------------------------------------

QT       += core gui
QT          += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Qsanguosha
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    src/main.cpp \
    src/dialog/mainwindow.cpp \
    src/dialog/flatdialog.cpp \
    src/dialog/connectiondialog.cpp \
    src/core/util.cpp \
    src/server/server.cpp \
    src/ui/startscene.cpp \
    src/core/settings.cpp \
    src/core/engine.cpp \
    src/core/general.cpp \
    src/dialog/avatarmodel.cpp \
    src/ui/skinbank.cpp \
    src/ui/stylehelper.cpp \
    src/util/serversocket.cpp \
    src/util/clientsocket.cpp

HEADERS += \
    src/dialog/mainwindow.h \
    src/dialog/flatdialog.h \
    src/dialog/connectiondialog.h \
    src/core/util.h \
    src/server/server.h \
    src/ui/startscene.h \
    src/core/settings.h \
    src/core/engine.h \
    src/core/general.h \
    src/dialog/avatarmodel.h \
    src/ui/skinbank.h \
    src/ui/stylehelper.h \
    src/util/abstractserversocket.h \
    src/util/serversocket.h \
    src/util/abstractclientsocket.h \
    src/util/clientsocket.h

FORMS += \
    src/dialog/mainwindow.ui \
    src/dialog/connectiondialog.ui

INCLUDEPATH += src/dialog
INCLUDEPATH += src/ui
INCLUDEPATH += src/server
INCLUDEPATH += src/core
INCLUDEPATH += src/util
