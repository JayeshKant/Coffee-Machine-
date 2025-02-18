#pragma once

/**
 * @file CoffeeRecipe.h
 * @brief Defines the CoffeeRecipe structure for resource requirements.
 *
 * This struct represents the amount of resources needed to brew one cup of a particular type of coffee.
 */
struct CoffeeRecipe {
    int coffeeBeansRequired; /**< Number of coffee beans needed. */
    int waterRequired;       /**< Amount of water needed (in milliliters). */
    int cupsRequired;        /**< Number of cups required (typically 1). */
};
