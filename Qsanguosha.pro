QT       += core gui opengl script
CONFIG   += audio
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
    src/core/card.cpp \
    src/core/engine.cpp \
    src/package/package.cpp \
    src/package/standard.cpp \
    src/package/exppattern.cpp \
    src/package/standardcards.cpp \
    src/ui/skinbank.cpp \
    src/core/json.cpp \
    src/dialog/generaloverview.cpp \
    src/core/general.cpp \
    src/package/standardgenerals.cpp \
    src/core/skill.cpp

HEADERS += \
    src/dialog/mainwindow.h \
    src/core/settings.h \
    src/ui/startscene.h \
    src/ui/qsanselectableitem.h \
    src/ui/button.h \
    src/ui/roomscene.h \
    src/dialog/cardoverview.h \
    src/core/card.h \
    src/core/audio.h \
    src/core/engine.h \
    src/package/package.h \
    src/package/exppattern.h \
    src/package/standardequips.h \
    src/package/standard.h \
    src/ui/skinbank.h \
    src/core/json.h \
    src/dialog/generaloverview.h \
    src/core/general.h \
    src/core/skill.h

FORMS += \
    src/dialog/mainwindow.ui \
    src/dialog/cardoverview.ui \
    src/dialog/generaloverview.ui

INCLUDEPATH += src/dialog
INCLUDEPATH += src/core
INCLUDEPATH += src/ui
INCLUDEPATH += src/package


LIBS += -L.

CONFIG(audio){
    DEFINES += AUDIO_SUPPORT
    INCLUDEPATH += include/fmod
    LIBS += -lfmodex
    SOURCES += src/core/audio.cpp
}

RC_FILE += resource/icon.rc

TRANSLATIONS += builds/sanguosha.ts
