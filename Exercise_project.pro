TEMPLATE = subdirs

SUBDIRS += \
    CourseLib \
    UnitTests \
    Game


CourseLib.subdir = Course/CourseLib
Game.subdir = Game
Game.depends = CourseLib
UnitTests.depends = CourseLib
UnitTest.depends = Game



