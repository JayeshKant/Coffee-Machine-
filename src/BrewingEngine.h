#pragma once

/**
 * @file BrewingEngine.h
 * @brief Declaration of the BrewingEngine class.
 *
 * This class encapsulates the low-level operations involved in brewing coffee,
 * such as grinding beans, heating water, pre-infusing, extracting, dispensing,
 * and cleaning up.
 */
class BrewingEngine {
public:
    /**
     * @brief Constructor.
     */
    BrewingEngine();

    /**
     * @brief Default destructor.
     */
    ~BrewingEngine() = default;

    /**
     * @brief Grinds the coffee beans.
     */
    void grindBeans();

    /**
     * @brief Heats the water.
     */
    void heatWater();

    /**
     * @brief Pre-infuses the coffee grounds.
     */
    void preInfuse();

    /**
     * @brief Extracts the coffee.
     */
    void extract();

    /**
     * @brief Dispenses the brewed coffee.
     */
    void dispense();

    /**
     * @brief Cleans up after brewing.
     */
    void cleanUp();
};
