TEMPLATE = subdirs

SUBDIRS += \
    CourseLib \
    UnitTests \
    Game \
    GameLib

CourseLib.subdir = Course/CourseLib
Game.depends = CourseLib
UnitTests.depends = CourseLib
