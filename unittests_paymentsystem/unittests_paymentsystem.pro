QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_paymentsystem.cpp \
            ../CoffeeMachineSimulation/paymentmodel.cpp \

INCLUDEPATH += ../CoffeeMachineSimulation

HEADERS += ../CoffeeMachineSimulation/paymentmodel.h

