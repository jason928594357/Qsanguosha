#-------------------------------------------------
#
# Project created by QtCreator 2021-02-11T19:00:10
#
#-------------------------------------------------

QT       += core gui
QT       += network

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
    src/core/engine.cpp \
    src/core/general.cpp \
    src/core/json.cpp \
    src/core/protocol.cpp \
    src/core/settings.cpp \
    src/core/util.cpp \
    src/dialog/avatarmodel.cpp \
    src/dialog/connectiondialog.cpp \
    src/dialog/flatdialog.cpp \
    src/dialog/mainwindow.cpp \
    src/dialog/serverdialog.cpp \
    src/main.cpp \
    src/server/server.cpp \
    src/server/serverroom.cpp \
    src/ui/skinbank.cpp \
    src/ui/startscene.cpp \
    src/ui/stylehelper.cpp \
    src/util/clientsocket.cpp \
    src/util/serversocket.cpp \
    src/client/client.cpp \
    src/core/roomstate.cpp \
    src/core/card.cpp \
    src/core/wrappedcard.cpp \
    src/util/udpsocket.cpp \
    src/dialog/configdialog.cpp \
    src/dialog/cardoverview.cpp \
    src/dialog/generaloverview.cpp \
    src/core/player.cpp

HEADERS += \
    src/core/engine.h \
    src/core/general.h \
    src/core/json.h \
    src/core/protocol.h \
    src/core/settings.h \
    src/core/util.h \
    src/dialog/avatarmodel.h \
    src/dialog/connectiondialog.h \
    src/dialog/flatdialog.h \
    src/dialog/mainwindow.h \
    src/dialog/serverdialog.h \
    src/server/server.h \
    src/ui/skinbank.h \
    src/ui/startscene.h \
    src/ui/stylehelper.h \
    src/util/abstractclientsocket.h \
    src/util/abstractserversocket.h \
    src/util/clientsocket.h \
    src/util/serversocket.h \
    src/client/client.h \
    src/core/roomstate.h \
    src/core/card.h \
    src/core/wrappedcard.h \
    src/util/abstractudpsocket.h \
    src/util/udpsocket.h \
    src/dialog/configdialog.h \
    src/dialog/cardoverview.h \
    src/dialog/generaloverview.h \
    src/core/namespace.h \
    src/core/player.h

FORMS += \
    src/dialog/connectiondialog.ui \
    src/dialog/mainwindow.ui \
    src/dialog/configdialog.ui \
    src/dialog/cardoverview.ui \
    src/dialog/generaloverview.ui

INCLUDEPATH += src/core
INCLUDEPATH += src/dialog
INCLUDEPATH += src/server
INCLUDEPATH += src/ui
INCLUDEPATH += src/util
