TEMPLATE = subdirs

# Using subdirs to separate the application and two unit test
# Qt recommends putting each unit test class in it's own project
SUBDIRS += \
    ../CoffeeMachineSimulation \
    ../unitest_brewingengine \
    ../unittests_paymentsystem \
    ../unittest_maintenancemodel \

