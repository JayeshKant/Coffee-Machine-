#pragma once

#include "Config.h"       // Contains macros like INITIAL_COFFEE_BEANS, etc.
#include "CoffeeRecipe.h" // For the CoffeeRecipe struct

/**
 * @file InventoryModel.h
 * @brief Declaration of the InventoryModel class.
 *
 * This class manages the coffee machine's inventory resources.
 * The initial values are defined by macros in Config.h.
 */
class InventoryModel {
private:
    int m_coffeeBeans = INITIAL_COFFEE_BEANS; /**< Current number of coffee beans. */
    int m_waterLevel = INITIAL_WATER_LEVEL;   /**< Current water level in milliliters. */
    int m_cups = INITIAL_CUPS;                  /**< Current number of cups available. */

public:
    /**
     * @brief Default constructor.
     */
    InventoryModel() = default;

    /**
     * @brief Default destructor.
     */
    ~InventoryModel() = default;

    /**
     * @brief Checks if there are sufficient resources to brew a cup of coffee based on the provided recipe.
     *
     * @param recipe The CoffeeRecipe specifying resource consumption.
     * @return true if enough resources are available; false otherwise.
     */
    [[nodiscard]] bool hasSufficientResources(const CoffeeRecipe& recipe) const;

    /**
     * @brief Updates the resources after brewing one cup of coffee based on the provided recipe.
     *
     * @param recipe The CoffeeRecipe specifying resource consumption.
     */
    void updateResources(const CoffeeRecipe& recipe);

    /**
     * @brief Refills the coffee beans inventory.
     *
     * @param amount The amount of coffee beans to add.
     */
    void refillCoffeeBeans(int amount);

    /**
     * @brief Refills the water inventory.
     *
     * @param amount The amount of water (in milliliters) to add.
     */
    void refillWater(int amount);

    /**
     * @brief Refills the cups inventory.
     *
     * @param amount The number of cups to add.
     */
    void refillCups(int amount);

    /**
     * @brief Gets the current number of coffee beans.
     *
     * @return The current count of coffee beans.
     */
    [[nodiscard]] int getCoffeeBeans() const;

    /**
     * @brief Gets the current water level.
     *
     * @return The current water level in milliliters.
     */
    [[nodiscard]] int getWaterLevel() const;

    /**
     * @brief Gets the current number of cups.
     *
     * @return The current number of cups.
     */
    [[nodiscard]] int getCups() const;
};
