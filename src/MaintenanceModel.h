#pragma once

/**
 * @file MaintenanceModel.h
 * @brief Declaration of the MaintenanceModel class.
 *
 * This class handles maintenance tasks for the coffee machine.
 * It can check whether maintenance is needed and perform the required maintenance.
 */
class MaintenanceModel {
private:
    bool m_needsMaintenance = false; /**< Indicates whether the machine needs maintenance. */

public:
    /**
     * @brief Constructor that initializes the maintenance status.
     */
    MaintenanceModel();

    /**
     * @brief Default destructor.
     */
    ~MaintenanceModel() = default;

    /**
     * @brief Performs maintenance on the coffee machine.
     *
     * If maintenance is needed, this method performs the necessary tasks
     * and resets the maintenance flag.
     */
    void performMaintenance();

    /**
     * @brief Checks if the coffee machine needs maintenance.
     *
     * @return true if maintenance is needed; false otherwise.
     */
    [[nodiscard]] bool needsMaintenance() const;

    /**
     * @brief Triggers the maintenance requirement (for simulation purposes).
     *
     * This method sets the internal flag indicating that maintenance is needed.
     */
    void triggerMaintenance();
};
