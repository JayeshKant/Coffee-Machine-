QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_unitests_brewingengine.cpp\
            ../CoffeeMachineSimulation/brewingengine.cpp \

INCLUDEPATH += ../CoffeeMachineSimulation

HEADERS += ../CoffeeMachineSimulation/brewingengine.h
