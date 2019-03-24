TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    course.cpp \
    student.cpp \
    portal.cpp \
    representation.cpp

HEADERS += \
    course.h \
    student.h \
    portal.h \
    representation.h

DISTFILES += \
    students.txt
