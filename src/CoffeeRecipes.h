#pragma once

#include "CoffeeRecipe.h"

/**
 * @enum CoffeeType
 * @brief Represents the different types of coffee available.
 */
enum class CoffeeType {
    Espresso,
    Cappuccino,
    Latte
};

/**
 * @brief Returns the CoffeeRecipe for a given CoffeeType.
 *
 * @param type The type of coffee.
 * @return A CoffeeRecipe with the resource requirements for that coffee type.
 */
inline CoffeeRecipe getCoffeeRecipe(CoffeeType type) {
    switch (type) {
        case CoffeeType::Espresso:
            return CoffeeRecipe{10, 30, 1};    // Example: 10 beans, 30 ml water, 1 cup.
        case CoffeeType::Cappuccino:
            return CoffeeRecipe{12, 60, 1};    // Example: 12 beans, 60 ml water, 1 cup.
        case CoffeeType::Latte:
            return CoffeeRecipe{10, 200, 1};   // Example: 10 beans, 200 ml water, 1 cup.
        default:
            return CoffeeRecipe{10, 30, 1};
    }
}
