#pragma once

#include "BrewingEngine.h"

/**
 * @file BrewingModel.h
 * @brief Declaration of the BrewingModel class.
 *
 * This class manages the high-level brewing process by coordinating with the
 * BrewingEngine. It provides methods to start, stop, and handle state changes
 * during the brewing process.
 */
class BrewingModel {
private:
    BrewingEngine* m_engine; /**< Pointer to the brewing engine responsible for the brewing steps. */

public:
    /**
     * @brief Constructor that creates the BrewingEngine.
     */
    BrewingModel();

    /**
     * @brief Destructor that cleans up the BrewingEngine.
     */
    ~BrewingModel();

    /**
     * @brief Initiates the brewing process.
     */
    void startBrewing();

    /**
     * @brief Stops the brewing process.
     */
    void stopBrewing();

    /**
     * @brief Handles changes in the brewing state.
     */
    void handleBrewStateChange();
};
