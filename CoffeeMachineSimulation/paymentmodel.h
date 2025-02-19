#pragma once

#include <QObject>
#include "Config.h"

class PaymentModel : public QObject {
    Q_OBJECT

public:
    explicit PaymentModel(QObject *parent = nullptr);
    ~PaymentModel() override = default;

    bool processPayment(double amount);
    double getBalance() const;
    void addBalance(double amount);
    double getRevenue() const;

signals:
    void balanceUpdated(double newBalance);
    void paymentProcessed(double amount);
    void paymentFailed(double amount);

private:
    double m_balance = 0.0;
    double m_revenue = INITIAL_REVENUE;
};
