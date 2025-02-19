#pragma once

#include <QObject>

class MaintenanceModel : public QObject {
    Q_OBJECT

public:
    explicit MaintenanceModel(QObject *parent = nullptr);
    ~MaintenanceModel() override = default;

    void performMaintenance();
    bool needsMaintenance() const;
    void triggerMaintenance();

signals:
    void maintenanceRequired();
    void maintenanceCompleted();

private:
    bool m_needsMaintenance = false;
};
