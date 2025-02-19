#pragma once

#include <QObject>

//! Represents the amount of resources needed to brew one cup of a particular type of coffee.
struct CoffeeRecipe {
    int coffeeBeansRequired; //!< Number of coffee beans needed.
    int waterRequired;       //!< Amount of water needed (in milliliters).
    int cupsRequired;        //!< Number of cups required (typically 1).
    int milkRequired;
};
