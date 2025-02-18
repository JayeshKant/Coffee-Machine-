#pragma once

#include "Config.h"

/**
 * @file PaymentModel.h
 * @brief Declaration of the PaymentModel class.
 *
 * This class handles payment processing by maintaining a user balance and
 * tracking the total revenue collected. The initial revenue is defined by a macro.
 */
class PaymentModel {
private:
    double m_balance = 0.0;          /**< User's current balance. */
    double m_revenue = INITIAL_REVENUE;/**< Total revenue collected. */

public:
    /**
     * @brief Default constructor.
     */
    PaymentModel() = default;

    /**
     * @brief Default destructor.
     */
    ~PaymentModel() = default;

    /**
     * @brief Processes a payment by deducting the specified amount from the balance.
     *        If successful, adds the amount to the revenue.
     *
     * @param amount The payment amount to process.
     * @return true if the payment is processed successfully; false otherwise.
     */
    [[nodiscard]] bool processPayment(double amount);

    /**
     * @brief Retrieves the current user balance.
     *
     * @return The user's current balance.
     */
    [[nodiscard]] double getBalance() const;

    /**
     * @brief Adds funds to the user's balance.
     *
     * @param amount The amount to add.
     */
    void addBalance(double amount);

    /**
     * @brief Retrieves the total revenue.
     *
     * @return The total revenue collected.
     */
    [[nodiscard]] double getRevenue() const;
};
