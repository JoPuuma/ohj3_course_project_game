TEMPLATE = app
TARGET = TheGame

QT += core gui widgets

CONFIG += c++14

SOURCES += \
    main.cpp \
    mapwindow.cc \
    startdialog.cpp \
    gamewindow.cpp \
    Tiles/rock.cpp \
    Tiles/water.cpp \
    Tiles/sand.cpp \
    Buildings/mine.cpp \
    Buildings/fishinghut.cpp \
    Buildings/cottage.cpp \
    Workers/miner.cpp \
    Workers/fisher.cpp \
    Workers/timberjack.cpp \
    Core/worldgenerator.cpp \
    Core/gameeventhandler.cpp \
    Core/objectmanager.cpp \
    Core/player.cpp \
    Graphics/gamescene.cpp \
    Graphics/mapitem.cpp


HEADERS += \
    mapwindow.hh \
    startdialog.hh \
    gamewindow.hh \
    Tiles/rock.hh \
    Tiles/water.hh \
    Tiles/sand.hh \
    Buildings/mine.hh \
    Buildings/fishinghut.hh \
    Buildings/cottage.hh \
    Core/resourcemaps.hh \
    Workers/miner.hh \
    Workers/fisher.hh \
    Workers/timberjack.hh \
    Core/worldgenerator.hh \
    Core/gameeventhandler.hh \
    Core/objectmanager.hh \
    Core/player.hh \
    Graphics/gamescene.hh \
    Graphics/mapitem.hh

win32:CONFIG(release, debug|release): LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/release/ -lCourseLib
else:win32:CONFIG(debug, debug|release): LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/debug/ -lCourseLib
else:unix: LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/ -lCourseLib

INCLUDEPATH += \
    $$PWD/../Course/CourseLib


DEPENDPATH += \
    $$PWD/../Course/CourseLib


win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/release/libCourseLib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/debug/libCourseLib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/release/CourseLib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/debug/CourseLib.lib
else:unix: PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/libCourseLib.a

FORMS += \
    mapwindow.ui \
    startdialog.ui \
    gamewindow.ui
