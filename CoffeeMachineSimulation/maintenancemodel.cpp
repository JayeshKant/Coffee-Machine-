#include "MaintenanceModel.h"
#include <QDebug>
#include <QThread>

// Helper function to simulate a loading animation.
static void simulateLoading(const QString &action, int dotCount = 3, int delayMs = 500) {
    qDebug().noquote() << action;
    for (int i = 0; i < dotCount; i++) {
        QThread::msleep(delayMs);
        qDebug().noquote() << ".";
    }
    qDebug().noquote() << "\n";
}

MaintenanceModel::MaintenanceModel(QObject *parent) : QObject(parent), m_needsMaintenance(false) {}

void MaintenanceModel::performMaintenance() {
    if (m_needsMaintenance) {
        simulateLoading("🔧 Performing maintenance");
        m_needsMaintenance = false;
        emit maintenanceCompleted();
        qDebug() << " Maintenance completed.";
    } else {
        qDebug() << " No maintenance is required at this time.";
    }
}

bool MaintenanceModel::needsMaintenance() const {
    return m_needsMaintenance;
}

void MaintenanceModel::triggerMaintenance() {
    m_needsMaintenance = true;
    emit maintenanceRequired();
    qDebug() << " Maintenance has been triggered.";
}
