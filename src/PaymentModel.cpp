#include "PaymentModel.h"
#include <iostream>

bool PaymentModel::processPayment(double amount) {
    if (amount <= m_balance) {
        m_balance -= amount;
        m_revenue += amount;
        return true;
    } else {
        std::cout << "Insufficient funds. Payment failed.\n";
        return false;
    }
}

double PaymentModel::getBalance() const {
    return m_balance;
}

void PaymentModel::addBalance(double amount) {
    m_balance += amount;
}

double PaymentModel::getRevenue() const {
    return m_revenue;
}
