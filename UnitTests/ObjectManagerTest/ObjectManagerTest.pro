#-------------------------------------------------
#
# Project created by QtCreator 2019-12-02T22:42:37
#
#-------------------------------------------------

QT       += testlib
QT       += core gui widgets
QT       += gui

TARGET = tst_objectmanagertest
CONFIG   += console
CONFIG   -= app_bundle
CONFIG  += c++14

TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += $$PWD/../../Game
DEPENDPATH += $$PWD/../../Game

HEADERS += \
    ../../Game/Core/gameeventhandler.hh \
    ../../Game/Core/player.hh \
    ../../Game/Core/objectmanager.hh \
    ../../Game/Buildings/mine.hh \
    ../../Game/Buildings/fishinghut.hh \
    ../../Game/Buildings/cottage.hh \
    ../../Game/Workers/basicworker.hh \
    ../../Game/Workers/miner.hh \
    ../../Game/Workers/timberjack.hh \
    ../../Game/Workers/fisher.hh \
    ../../Game/Graphics/gamescene.hh \
    ../../Game/Graphics/mapitem.hh \
    ../../Game/objecttypes.hh \
    ../../Game/Core/resourcemaps.hh \
    ../../Course/CourseLib/core/coordinate.h

SOURCES += \
    tst_objectmanagertest.cpp \
    ../../Game/Core/player.cpp \
    ../../Game/Core/gameeventhandler.cpp \
    ../../Game/Core/objectmanager.cpp \
    ../../Game/Buildings/mine.cpp \
    ../../Game/Buildings/fishinghut.cpp \
    ../../Game/Buildings/cottage.cpp \
    ../../Game/Workers/basicworker.cpp \
    ../../Game/Workers/timberjack.cpp \
    ../../Game/Workers/miner.cpp \
    ../../Game/Workers/fisher.cpp \
    ../../Game/Graphics/gamescene.cpp \
    ../../Game/Graphics/mapitem.cpp \
    ../../Course/CourseLib/core/coordinate.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../Course/CourseLib/release/ -lCourseLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../Course/CourseLib/debug/ -lCourseLib
else:unix: LIBS += -L$$OUT_PWD/../../Course/CourseLib/ -lCourseLib

INCLUDEPATH += $$PWD/../../Course/CourseLib
DEPENDPATH += $$PWD/../../Course/CourseLib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Course/CourseLib/release/libCourseLib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Course/CourseLib/debug/libCourseLib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Course/CourseLib/release/CourseLib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Course/CourseLib/debug/CourseLib.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../Course/CourseLib/libCourseLib.a
