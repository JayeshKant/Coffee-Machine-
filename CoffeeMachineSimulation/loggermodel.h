#pragma once

#include <QObject>
#include <QString>
#include <QStringList>

class LoggerModel : public QObject {
    Q_OBJECT

public:
    explicit LoggerModel(QObject *parent = nullptr);
    ~LoggerModel() override = default;

    void logEvent(const QString &msg);
    void logError(const QString &err);
    void showLogs() const;
    QStringList getLogs() const;  // <-- Add this function

signals:
    void newLogEntry(const QString &entry);


private:
    QStringList m_logs;
};
