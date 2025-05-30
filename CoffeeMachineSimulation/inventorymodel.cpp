#include "InventoryModel.h"
#include <QDebug>

InventoryModel::InventoryModel(QObject *parent) : QObject(parent) {
    m_coffeeBeans = INITIAL_COFFEE_BEANS;
    m_waterLevel = INITIAL_WATER_LEVEL;
    m_cups = INITIAL_CUPS;
    m_milklevel = INITIAL_MILK_LVL;
}

bool InventoryModel::hasSufficientResources(const CoffeeRecipe& recipe) const {
    return (m_coffeeBeans >= recipe.coffeeBeansRequired &&
            m_waterLevel >= recipe.waterRequired &&
            m_cups >= recipe.cupsRequired &&
            m_milklevel >= recipe.milkRequired);

}

void InventoryModel::updateResources(const CoffeeRecipe& recipe) {
    if (!hasSufficientResources(recipe)) {
        qDebug() << "⚠ Not enough resources to brew this type of coffee.";
        return;
    }

    m_coffeeBeans -= recipe.coffeeBeansRequired;
    m_waterLevel -= recipe.waterRequired;
    m_cups -= recipe.cupsRequired;
    m_milklevel = m_milklevel - recipe.milkRequired;

    emit inventoryUpdated();
}

void InventoryModel::refillCoffeeBeans(int amount) {
    m_coffeeBeans += amount;
    qDebug() << " Refilled coffee beans by" << amount << ". New level:" << m_coffeeBeans;
    emit inventoryUpdated();
}

void InventoryModel::refillWater(int amount) {
    m_waterLevel += amount;
    qDebug() << " Refilled water by" << amount << "ml. New level:" << m_waterLevel;
    emit inventoryUpdated();
}

void InventoryModel::refillCups(int amount) {
    m_cups += amount;
    qDebug() << " Refilled cups by" << amount << ". New level:" << m_cups;
    emit inventoryUpdated();
}

void InventoryModel::refillMilk(int amount){
    m_milklevel += amount;
    qDebug() << " Refilled Milk by" << amount << ". New level:" << m_milklevel;
    emit inventoryUpdated();

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

int InventoryModel::getMilk() const {
    return m_milklevel;
}

