TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

HEADERS += \
    headers/cargo.h \
    headers/user.h

SOURCES += \
        src/tests.cpp \
        src/cargo.cpp \
        src/user.cpp

LIBS += -lboost_unit_test_framework
