#include <QtTest>
#include <QSignalSpy>
#include "MaintenanceModel.h"  // Ensure this header file is accessible

class maintenance_model : public QObject
{
    Q_OBJECT

public:
    maintenance_model();
    ~maintenance_model();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_initialState();
    void test_triggerMaintenance();
    void test_performMaintenanceWhenRequired();
    void test_performMaintenanceWhenNotRequired();
    void test_multipleTriggers();
    void test_repeatedMaintenanceCalls();
};

maintenance_model::maintenance_model() {}

maintenance_model::~maintenance_model() {}

void maintenance_model::initTestCase()
{
    // Any global initialization can be done here.
}

void maintenance_model::cleanupTestCase()
{
    // Global cleanup can be done here.
}

// Test that the initial state of MaintenanceModel is correct.
void maintenance_model::test_initialState()
{
    MaintenanceModel model;
    QVERIFY(!model.needsMaintenance());
}

// Test that triggering maintenance sets the flag and emits maintenanceRequired.
void maintenance_model::test_triggerMaintenance()
{
    MaintenanceModel model;
    QVERIFY(!model.needsMaintenance());

    // Set up QSignalSpy for maintenanceRequired signal.
    QSignalSpy spy(&model, SIGNAL(maintenanceRequired()));

    model.triggerMaintenance();

    // The maintenance flag should be set.
    QVERIFY(model.needsMaintenance());
    // Verify that maintenanceRequired signal was emitted exactly once.
    QCOMPARE(spy.count(), 1);
}

// Test that when maintenance is required, performing maintenance emits maintenanceCompleted and resets the flag.
void maintenance_model::test_performMaintenanceWhenRequired()
{
    MaintenanceModel model;
    QSignalSpy spyCompleted(&model, SIGNAL(maintenanceCompleted()));

    // Trigger maintenance first.
    model.triggerMaintenance();
    QVERIFY(model.needsMaintenance());

    // Now perform maintenance.
    model.performMaintenance();

    // Verify that maintenanceCompleted signal was emitted.
    QCOMPARE(spyCompleted.count(), 1);
    // The maintenance flag should now be false.
    QVERIFY(!model.needsMaintenance());
}

// Test that performing maintenance when not required does nothing.
void maintenance_model::test_performMaintenanceWhenNotRequired()
{
    MaintenanceModel model;
    QSignalSpy spyCompleted(&model, SIGNAL(maintenanceCompleted()));

    // Without triggering maintenance, call performMaintenance.
    model.performMaintenance();

    // No signal should be emitted and the flag should remain false.
    QCOMPARE(spyCompleted.count(), 0);
    QVERIFY(!model.needsMaintenance());
}

// Test calling triggerMaintenance multiple times.
void maintenance_model::test_multipleTriggers()
{
    MaintenanceModel model;
    QSignalSpy spyRequired(&model, SIGNAL(maintenanceRequired()));

    // Trigger maintenance twice.
    model.triggerMaintenance();
    model.triggerMaintenance();

    // Expect two emissions of maintenanceRequired.
    QCOMPARE(spyRequired.count(), 2);
    // The maintenance flag should still be true.
    QVERIFY(model.needsMaintenance());

    // Now perform maintenance and check for maintenanceCompleted.
    QSignalSpy spyCompleted(&model, SIGNAL(maintenanceCompleted()));
    model.performMaintenance();
    QCOMPARE(spyCompleted.count(), 1);
    QVERIFY(!model.needsMaintenance());
}

// Test repeated calls to performMaintenance.
void maintenance_model::test_repeatedMaintenanceCalls()
{
    MaintenanceModel model;
    QSignalSpy spyCompleted(&model, SIGNAL(maintenanceCompleted()));

    // Call performMaintenance without triggering.
    model.performMaintenance();
    model.performMaintenance();
    // No signal should be emitted.
    QCOMPARE(spyCompleted.count(), 0);
    QVERIFY(!model.needsMaintenance());

    // Now trigger maintenance and call performMaintenance twice.
    model.triggerMaintenance();
    model.performMaintenance();
    // The first call should complete maintenance.
    model.performMaintenance(); // This call should not do anything further.
    // Verify that maintenanceCompleted was only emitted once.
    QCOMPARE(spyCompleted.count(), 1);
    QVERIFY(!model.needsMaintenance());
}

QTEST_APPLESS_MAIN(maintenance_model)
#include "tst_maintenance_model.moc"
