#pragma once

#include <QObject>

//! Handles low-level operations of the brewing process.
class BrewingEngine : public QObject {
    Q_OBJECT

public:
    //! Constructor.
    explicit BrewingEngine(QObject *parent = nullptr);

    //! Destructor.
    ~BrewingEngine() override = default;

    //! Grinds the coffee beans.
    void grindBeans();

    //! Heats the water to the optimal temperature.
    void heatWater();

    //! Pre-infuses the coffee grounds before extraction.
    void preInfuse();

    //! Extracts the coffee by applying pressure.
    void extract();

    //! Dispenses the brewed coffee into the cup.
    void dispense();

    //! Cleans up the brewing system after use.
    void cleanUp();

    void heatMilk();
};
