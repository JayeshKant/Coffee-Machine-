QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_loggermodel.cpp \
            ../CoffeeMachineSimulation/loggermodel.cpp \


INCLUDEPATH += ../CoffeeMachineSimulation

HEADERS += ../CoffeeMachineSimulation/loggermodel.h

