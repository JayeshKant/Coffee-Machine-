#include "InventoryModel.h"
#include <iostream>

bool InventoryModel::hasSufficientResources(const CoffeeRecipe& recipe) const {
    return (m_coffeeBeans >= recipe.coffeeBeansRequired &&
            m_waterLevel >= recipe.waterRequired &&
            m_cups >= recipe.cupsRequired);
}

void InventoryModel::updateResources(const CoffeeRecipe& recipe) {
    if (!hasSufficientResources(recipe)) {
        std::cout << "Not enough resources to brew this type of coffee.\n";
        return;
    }
    m_coffeeBeans -= recipe.coffeeBeansRequired;
    m_waterLevel -= recipe.waterRequired;
    m_cups -= recipe.cupsRequired;
}

void InventoryModel::refillCoffeeBeans(int amount) {
    m_coffeeBeans += amount;
    std::cout << "Refilled coffee beans by " << amount 
              << ". New level: " << m_coffeeBeans << "\n";
}

void InventoryModel::refillWater(int amount) {
    m_waterLevel += amount;
    std::cout << "Refilled water by " << amount 
              << " ml. New level: " << m_waterLevel << "\n";
}

void InventoryModel::refillCups(int amount) {
    m_cups += amount;
    std::cout << "Refilled cups by " << amount 
              << ". New level: " << m_cups << "\n";
}

int InventoryModel::getCoffeeBeans() const {
    return m_coffeeBeans;
}

int InventoryModel::getWaterLevel() const {
    return m_waterLevel;
}

int InventoryModel::getCups() const {
    return m_cups;
}
