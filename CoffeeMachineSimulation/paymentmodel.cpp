#include "PaymentModel.h"
#include <QDebug>

PaymentModel::PaymentModel(QObject *parent) : QObject(parent) {}

bool PaymentModel::processPayment(double amount) {
    if (amount <= m_balance) {
        m_balance -= amount;
        m_revenue += amount;
        emit balanceUpdated(m_balance);
        emit paymentProcessed(amount);
        qDebug() << " Payment of $" << amount << " processed successfully.";
        return true;
    } else {
        emit paymentFailed(amount);
        qDebug() << " Insufficient funds. Payment of $" << amount << " failed.";
        return false;
    }
}

double PaymentModel::getBalance() const {
    return m_balance;
}

void PaymentModel::addBalance(double amount) {
    m_balance += amount;
    emit balanceUpdated(m_balance);
    qDebug() << " Added $" << amount << " to balance. New balance: $" << m_balance;
}

double PaymentModel::getRevenue() const {
    return m_revenue;
}
