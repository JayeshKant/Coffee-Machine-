#include <QtTest>
#include <QSignalSpy>
#include "LoggerModel.h"  // Ensure the header path is correct

class logger_model_test : public QObject
{
    Q_OBJECT

public:
    logger_model_test();
    ~logger_model_test();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_logEvent_basic();
    void test_logError_basic();
    void test_multipleLogEntries();
    void test_emptyLogMessages();
    void test_showLogsDoesNotAffectState();
};

logger_model_test::logger_model_test() {}
logger_model_test::~logger_model_test() {}

void logger_model_test::initTestCase()
{
    // Global initialization if needed.
}

void logger_model_test::cleanupTestCase()
{
    // Global cleanup if needed.
}

// Test that logEvent creates the proper log entry, emits the signal, and stores the entry.
void logger_model_test::test_logEvent_basic()
{
    LoggerModel logger;
    QSignalSpy spy(&logger, SIGNAL(newLogEntry(QString)));

    QString eventMessage = "Test event";
    logger.logEvent(eventMessage);
    QString expectedEntry = "[EVENT] " + eventMessage;

    // Verify that the newLogEntry signal is emitted exactly once.
    QCOMPARE(spy.count(), 1);

    // Check the signal's argument.
    QList<QVariant> arguments = spy.takeFirst();
    QCOMPARE(arguments.at(0).toString(), expectedEntry);

    // Verify that the log is stored correctly.
    QStringList logs = logger.getLogs();
    QCOMPARE(logs.size(), 1);
    QCOMPARE(logs.first(), expectedEntry);
}

// Test that logError creates the proper log entry, emits the signal, and stores the entry.
void logger_model_test::test_logError_basic()
{
    LoggerModel logger;
    QSignalSpy spy(&logger, SIGNAL(newLogEntry(QString)));

    QString errorMessage = "Test error";
    logger.logError(errorMessage);
    QString expectedEntry = "[ERROR] " + errorMessage;

    // Verify that the newLogEntry signal is emitted exactly once.
    QCOMPARE(spy.count(), 1);

    // Check the signal's argument.
    QList<QVariant> arguments = spy.takeFirst();
    QCOMPARE(arguments.at(0).toString(), expectedEntry);

    // Verify that the log is stored correctly.
    QStringList logs = logger.getLogs();
    QCOMPARE(logs.size(), 1);
    QCOMPARE(logs.first(), expectedEntry);
}

// Test multiple log entries to ensure they are stored in the correct order.
void logger_model_test::test_multipleLogEntries()
{
    LoggerModel logger;
    QSignalSpy spy(&logger, SIGNAL(newLogEntry(QString)));

    // Log several entries.
    logger.logEvent("Event 1");
    logger.logError("Error 1");
    logger.logEvent("Event 2");
    logger.logError("Error 2");

    // Four signals should have been emitted.
    QCOMPARE(spy.count(), 4);

    QStringList logs = logger.getLogs();
    QCOMPARE(logs.size(), 4);
    QCOMPARE(logs.at(0), QString("[EVENT] Event 1"));
    QCOMPARE(logs.at(1), QString("[ERROR] Error 1"));
    QCOMPARE(logs.at(2), QString("[EVENT] Event 2"));
    QCOMPARE(logs.at(3), QString("[ERROR] Error 2"));
}

// Test logging empty messages.
void logger_model_test::test_emptyLogMessages()
{
    LoggerModel logger;
    QSignalSpy spyEvent(&logger, SIGNAL(newLogEntry(QString)));
    QSignalSpy spyError(&logger, SIGNAL(newLogEntry(QString)));

    // Log an empty event.
    logger.logEvent("");
    QString expectedEventEntry = "[EVENT] ";
    QCOMPARE(spyEvent.count(), 1);
    QList<QVariant> argumentsEvent = spyEvent.takeFirst();
    QCOMPARE(argumentsEvent.at(0).toString(), expectedEventEntry);

    // Log an empty error.
    logger.logError("");
    QString expectedErrorEntry = "[ERROR] ";
    QCOMPARE(spyError.count(), 1);
    QList<QVariant> argumentsError = spyError.takeFirst();
    QCOMPARE(argumentsError.at(0).toString(), expectedErrorEntry);

    // Verify both logs are stored.
    QStringList logs = logger.getLogs();
    QCOMPARE(logs.size(), 2);
    QCOMPARE(logs.at(0), expectedEventEntry);
    QCOMPARE(logs.at(1), expectedErrorEntry);
}

// Test that calling showLogs() (which prints to the console) does not alter the stored logs.
void logger_model_test::test_showLogsDoesNotAffectState()
{
    LoggerModel logger;
    // Log a few entries.
    logger.logEvent("Test for showLogs");
    logger.logError("Another test");

    // Get logs before calling showLogs.
    QStringList logsBefore = logger.getLogs();
    QVERIFY(!logsBefore.isEmpty());

    // Call showLogs (which outputs to debug).
    logger.showLogs();

    // Get logs after calling showLogs.
    QStringList logsAfter = logger.getLogs();

    // The logs should remain unchanged.
    QCOMPARE(logsBefore, logsAfter);
}

QTEST_APPLESS_MAIN(logger_model_test)
#include "tst_loggermodel.moc"
