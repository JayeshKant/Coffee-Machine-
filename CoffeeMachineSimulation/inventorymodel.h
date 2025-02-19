#pragma once

#include <QObject>
#include "Config.h"
#include "CoffeeRecipe.h"

class InventoryModel : public QObject {
    Q_OBJECT

public:
    explicit InventoryModel(QObject *parent = nullptr);
    ~InventoryModel() override = default;

    bool hasSufficientResources(const CoffeeRecipe& recipe) const;
    void updateResources(const CoffeeRecipe& recipe);

    void refillCoffeeBeans(int amount);
    void refillWater(int amount);
    void refillCups(int amount);

    int getCoffeeBeans() const;
    int getWaterLevel() const;
    int getCups() const;

signals:
    void inventoryUpdated();

private:
    int m_coffeeBeans = INITIAL_COFFEE_BEANS;
    int m_waterLevel = INITIAL_WATER_LEVEL;
    int m_cups = INITIAL_CUPS;
};
