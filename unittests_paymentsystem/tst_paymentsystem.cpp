#include <QtTest>
#include <limits>
#include "PaymentModel.h"  // Include your PaymentModel header
#include <QSignalSpy>

class paymentsystem : public QObject
{
    Q_OBJECT

public:
    paymentsystem();
    ~paymentsystem();

private slots:
    // Called before the first test function
    void initTestCase();
    // Called after the last test function
    void cleanupTestCase();

    // Data-driven tests for addBalance method
    void addBalance_data();
    void addBalance();

    // Data-driven tests for processPayment method
    void processPayment_data();
    void processPayment();
};

paymentsystem::paymentsystem() {}
paymentsystem::~paymentsystem() {}

void paymentsystem::initTestCase() {}
void paymentsystem::cleanupTestCase() {}

//////////////////////////////
// Tests for addBalance method
//////////////////////////////

void paymentsystem::addBalance_data()
{
    QTest::addColumn<double>("initialBalance");
    QTest::addColumn<double>("amountToAdd");
    QTest::addColumn<double>("expectedBalance");

    // Basic cases
    QTest::newRow("add zero from zero")                << 0.0  << 0.0                      << 0.0;
    QTest::newRow("add positive from zero")             << 0.0  << 100.0                    << 100.0;
    QTest::newRow("add negative from zero")             << 0.0  << -50.0                    << -50.0;
    QTest::newRow("positive initial then positive add") << 50.0 << 75.0                     << 125.0;
    QTest::newRow("positive initial then negative add") << 50.0 << -25.0                    << 25.0;

    // Extreme cases
    QTest::newRow("large positive addition")            << 0.0  << 1e9                      << 1e9;
    QTest::newRow("large negative addition")            << 0.0  << -1e9                     << -1e9;
    QTest::newRow("small positive addition")            << 0.0  << 1e-10                    << 1e-10;
    QTest::newRow("small negative addition")            << 0.0  << -1e-10                   << -1e-10;
    QTest::newRow("add max double")                     << 0.0  << std::numeric_limits<double>::max() << std::numeric_limits<double>::max();
    QTest::newRow("add min double")                     << 0.0  << std::numeric_limits<double>::min() << std::numeric_limits<double>::min();
}

void paymentsystem::addBalance()
{
    QFETCH(double, initialBalance);
    QFETCH(double, amountToAdd);
    QFETCH(double, expectedBalance);

    PaymentModel model;

    // Set the initial balance if required.
    if (initialBalance != 0.0) {
        model.addBalance(initialBalance);
    }

    // Prepare a QSignalSpy to capture balanceUpdated signal emissions.
    QSignalSpy spy(&model, SIGNAL(balanceUpdated(double)));

    // Call addBalance with the test input.
    model.addBalance(amountToAdd);

    // Verify the updated balance using qFuzzyCompare for floating-point comparisons.
    double newBalance = model.getBalance();
    QVERIFY(qFuzzyCompare(newBalance + 1, expectedBalance + 1));

    // Verify that balanceUpdated signal was emitted exactly once.
    QCOMPARE(spy.count(), 1);

    // Validate that the signal argument matches the expected balance.
    QList<QVariant> arguments = spy.takeFirst();
    QVERIFY(qFuzzyCompare(arguments.at(0).toDouble() + 1, expectedBalance + 1));
}

//////////////////////////////////
// Tests for processPayment method
//////////////////////////////////

void paymentsystem::processPayment_data()
{
    QTest::addColumn<double>("initialBalance");
    QTest::addColumn<double>("paymentAmount");
    QTest::addColumn<bool>("expectedResult");
    QTest::addColumn<double>("expectedBalance");
    QTest::addColumn<double>("expectedRevenue");
    QTest::addColumn<QString>("expectedSignal"); // "processed" or "failed"

    // Payment succeeds: amount less than initial balance.
    QTest::newRow("payment success - partial")  << 200.0 << 100.0 << true  << 100.0 << 100.0 << "processed";
    // Payment succeeds: amount equal to initial balance.
    QTest::newRow("payment success - exact")    << 100.0 << 100.0 << true  << 0.0   << 100.0 << "processed";
    // Payment fails: insufficient funds.
    QTest::newRow("payment failure")            << 50.0  << 100.0 << false << 50.0  << 0.0   << "failed";
    // Edge: zero payment amount (should succeed without changing values).
    QTest::newRow("zero payment")               << 50.0  << 0.0   << true  << 50.0  << 0.0   << "processed";
    // Edge: negative payment amount (design-dependent; here we assume it adds funds).
    QTest::newRow("negative payment")           << 100.0 << -20.0 << true  << 120.0 << -20.0 << "processed";
    // Extreme: payment amount exceeds maximum double (likely fails).
    QTest::newRow("payment exceeds max")        << 1e9   << std::numeric_limits<double>::max() << false << 1e9 << 0.0 << "failed";
}

void paymentsystem::processPayment()
{
    QFETCH(double, initialBalance);
    QFETCH(double, paymentAmount);
    QFETCH(bool, expectedResult);
    QFETCH(double, expectedBalance);
    QFETCH(double, expectedRevenue);
    QFETCH(QString, expectedSignal);

    PaymentModel model;

    // Set the initial balance using addBalance.
    if (initialBalance != 0.0) {
        model.addBalance(initialBalance);
    }

    // Prepare signal spies for all relevant signals.
    QSignalSpy spyBalance(&model, SIGNAL(balanceUpdated(double)));
    QSignalSpy spyProcessed(&model, SIGNAL(paymentProcessed(double)));
    QSignalSpy spyFailed(&model, SIGNAL(paymentFailed(double)));

    // Call processPayment and capture the result.
    bool result = model.processPayment(paymentAmount);
    QCOMPARE(result, expectedResult);

    // Verify the updated balance and revenue.
    double newBalance = model.getBalance();
    double newRevenue = model.getRevenue();
    QVERIFY(qFuzzyCompare(newBalance + 1, expectedBalance + 1));
    QVERIFY(qFuzzyCompare(newRevenue + 1, expectedRevenue + 1));

    // Verify the correct signal was emitted.
    if (expectedSignal == "processed") {
        QCOMPARE(spyProcessed.count(), 1);
        // The balanceUpdated signal should have been emitted (in addition to any from addBalance).
        QVERIFY(spyBalance.count() >= 1);
        QCOMPARE(spyFailed.count(), 0);
    } else if (expectedSignal == "failed") {
        QCOMPARE(spyFailed.count(), 1);
        // If the payment failed, no paymentProcessed signal should be emitted.
        QCOMPARE(spyProcessed.count(), 0);
    }
}

QTEST_APPLESS_MAIN(paymentsystem)

#include "tst_paymentsystem.moc"
