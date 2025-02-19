#include "LoggerModel.h"
#include <QDebug>
#include <QDateTime>

LoggerModel::LoggerModel(QObject *parent) : QObject(parent) {}

// Logs an event message.
// LoggerModel.cpp
void LoggerModel::logEvent(const QString &msg) {
    QString entry = "[EVENT] " + msg;
    m_logs.append(entry);
    // Emit signal so the UI knows a new log entry arrived
    emit newLogEntry(entry);
}

void LoggerModel::logError(const QString &err) {
    QString entry = "[ERROR] " + err;
    m_logs.append(entry);
    emit newLogEntry(entry);
}


// Displays all logged messages.
void LoggerModel::showLogs() const {
    qDebug() << "\n---- Log History ----";
    for (const QString &entry : m_logs) {
        qDebug() << entry;
    }
    qDebug() << "---------------------";
}
QStringList LoggerModel::getLogs() const {
    return m_logs;
}
