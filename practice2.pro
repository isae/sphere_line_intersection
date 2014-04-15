TEMPLATE = app
CONFIG += console
CONFIG -= qt


INCLUDEPATH += ../googletest/include

SOURCES += main.cpp \
    test.cpp
SOURCES +=

LIBS += -lgmp
LIBS += -lgmpxx
LIBS+= libgtest.a

HEADERS += has_intersection.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/release/ -lgtest
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/debug/ -lgtest
else:symbian: LIBS += -lgtest
else:unix: LIBS += -L$$PWD/ -lgtest

INCLUDEPATH += $$PWD/
DEPENDPATH += $$PWD/

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/release/gtest.lib
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/debug/gtest.lib
else:unix:!symbian: PRE_TARGETDEPS += $$PWD/libgtest.a
