#-------------------------------------------------
#
# Project created by QtCreator 2019-11-06T13:06:36
#
#-------------------------------------------------

QT       -= gui

TARGET = GameLib
TEMPLATE = lib

DEFINES += GAMELIB_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Tiles/rock.cpp \
    Tiles/water.cpp \
    Tiles/sand.cpp \
    Buildings/mine.cpp \
    Buildings/fishinghut.cpp \
    Buildings/cottage.cpp

HEADERS += \
        gamelib_global.hh \ 
    Tiles/rock.hh \
    Tiles/water.hh \
    Tiles/sand.hh \
    Buildings/mine.hh \
    Buildings/fishinghut.hh \
    Buildings/cottage.hh \
    Core/resourcemaps.hh

INCLUDEPATH += \
    $$PWD/../Course/CourseLib

DEPENDPATH += \
    $$PWD/../Course/CourseLib


unix {
    target.path = /usr/lib
    INSTALLS += target
}
