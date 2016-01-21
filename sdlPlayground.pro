#-------------------------------------------------
#
# Project created by QtCreator 2016-01-16T17:42:36
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = sdlPlayground
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    game.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../SDL2/dlib2.0.4/lib/x64/ -lSDL2
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../SDL2/dlib2.0.4/lib/x64/ -lSDL2
else:unix: LIBS += -L$$PWD/../../SDL2/dlib2.0.4/lib/x64/ -lSDL2

INCLUDEPATH += $$PWD/../../SDL2/dlib2.0.4/lib/x64
DEPENDPATH += $$PWD/../../SDL2/dlib2.0.4/lib/x64

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../SDL2/dlib2.0.4/lib/x64/ -lSDL2main
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../SDL2/dlib2.0.4/lib/x64/ -lSDL2main
else:unix: LIBS += -L$$PWD/../../SDL2/dlib2.0.4/lib/x64/ -lSDL2main

INCLUDEPATH += $$PWD/../../SDL2/dlib2.0.4/lib/x64
DEPENDPATH += $$PWD/../../SDL2/dlib2.0.4/lib/x64

INCLUDEPATH += $$PWD/../../SDL2/dlib2.0.4/include

HEADERS += \
    game.h
