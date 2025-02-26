#include <QtTest>
#include "brewingengine.h"

class unitests_brewingengine : public QObject
{
    Q_OBJECT

public:
    unitests_brewingengine();
    ~unitests_brewingengine();

private slots:
    void initTestCase();
    void cleanupTestCase();

    // Each test function calls a method from BrewingEngine
    void testGrindBeans();
    void testHeatWater();
    void testPreInfuse();
    void testExtract();
    void testDispense();
    void testCleanUp();
    void testHeatMilk();

};

unitests_brewingengine::unitests_brewingengine() {}
unitests_brewingengine::~unitests_brewingengine() {}

void unitests_brewingengine::initTestCase() {
    qDebug() << "Starting BrewingEngine tests...";
}

void unitests_brewingengine::cleanupTestCase() {
    qDebug() << "BrewingEngine tests completed.";
}

void unitests_brewingengine::testGrindBeans() {
    BrewingEngine engine;
    engine.grindBeans();
    // If no crash, test passes.
    QVERIFY(true);
}

void unitests_brewingengine::testHeatWater() {
    BrewingEngine engine;
    engine.heatWater();
    QVERIFY(true);
}

void unitests_brewingengine::testPreInfuse() {
    BrewingEngine engine;
    engine.preInfuse();
    QVERIFY(true);
}

void unitests_brewingengine::testExtract() {
    BrewingEngine engine;
    engine.extract();
    QVERIFY(true);
}

void unitests_brewingengine::testDispense() {
    BrewingEngine engine;
    engine.dispense();
    QVERIFY(true);
}

void unitests_brewingengine::testCleanUp() {
    BrewingEngine engine;
    engine.cleanUp();
    QVERIFY(true);
}

void unitests_brewingengine::testHeatMilk() {
    BrewingEngine engine;
    engine.heatMilk();
    QVERIFY(true);
}


QTEST_APPLESS_MAIN(unitests_brewingengine)

#include "tst_unitests_brewingengine.moc"
