TEMPLATE = app
CONFIG += console
CONFIG += opengl
QT = core gui opengl
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
INCLUDEPATH += ../googletest/include
INCLUDEPATH += ./visualizer

SOURCES += main.cpp \
    test.cpp
#    visualizer/main.cpp \
#    visualizer/visualization.cpp \
#    visualizer/view.cpp \
#    visualizer/vectornd.cpp \
#    visualizer/vector3d.cpp \
#    visualizer/vector2d.cpp \
#    visualizer/random.cpp \
#    visualizer/radix.cpp \
#    visualizer/moc_visualization.cpp \
#    visualizer/exampleclass.cpp \
#    visualizer/console.cpp \
#    visualizer/axisview.cpp

LIBS += -lgmp
LIBS += -lgmpxx
LIBS+= libgtest.a
LIBS += -lpthread

QMAKE_CXXFLAGS += -std=c++0x

HEADERS += has_intersection.h
#    visualizer/visualization.h \
#    visualizer/view.h \
#    visualizer/vectornd.h \
#    visualizer/vector3d.h \
#    visualizer/vector2d.h \
#    visualizer/random.h \
#    visualizer/radix.h \
#    visualizer/orientation.h \
#    visualizer/exampleclass.h \
#    visualizer/console.h \
#    visualizer/axisview.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/release/ -lgtest
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/debug/ -lgtest
else:symbian: LIBS += -lgtest
else:unix: LIBS += -L$$PWD/ -lgtest

INCLUDEPATH += $$PWD/
DEPENDPATH += $$PWD/

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/release/gtest.lib
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/debug/gtest.lib
else:unix:!symbian: PRE_TARGETDEPS += $$PWD/libgtest.a

#OTHER_FILES += \
#    visualizer/visualization.o \
#    visualizer/view.o \
#    visualizer/vectornd.o \
#    visualizer/vector3d.o \
#    visualizer/vector2d.o \
#    visualizer/README.md \
#    visualizer/random.o \
#    visualizer/radix.o \
#    visualizer/moc_visualization.o \
#    visualizer/Makefile \
#    visualizer/main.o \
#    visualizer/LICENSE \
#    visualizer/geometryview.o \
#    visualizer/Geometry.pro.user \
#    visualizer/Geometry.pro \
#    visualizer/Geometry \
#    visualizer/exampleclass.o \
#    visualizer/console.o \
#    visualizer/axisview.o
