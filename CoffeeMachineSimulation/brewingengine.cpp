#include "BrewingEngine.h"
#include <QDebug>
#include <QThread>

//! Helper function to simulate a loading animation with delay.
#include <QCoreApplication>  // Needed for processEvents()

static void simulateLoading(const QString &action, int dotCount = 3, int delayMs = 2500) {
    qDebug() << action;
    for (int i = 0; i < dotCount; i++) {
        QCoreApplication::processEvents();  // ✅ Allow UI to update
        QThread::msleep(delayMs);
        qDebug() << ".";
    }
    QCoreApplication::processEvents();  // ✅ Ensure UI gets updated
    qDebug() << "\n";
}


//! Constructor for BrewingEngine.
BrewingEngine::BrewingEngine(QObject *parent) : QObject(parent) {
    // Initialization if needed.
}

//! Grinds the coffee beans.
void BrewingEngine::grindBeans() {
    simulateLoading(" Grinding beans");
}

//! Heats the water to the optimal temperature.
void BrewingEngine::heatWater() {
    simulateLoading(" Heating water");
}

//! Pre-infuses the coffee grounds before extraction.
void BrewingEngine::preInfuse() {
    simulateLoading("💦 Pre-infusing coffee grounds");
}

//! Extracts the coffee by applying pressure.
void BrewingEngine::extract() {
    simulateLoading(" Extracting coffee");
}

//! Dispenses the brewed coffee into the cup.
void BrewingEngine::dispense() {
    simulateLoading(" Dispensing coffee");
}

//! Cleans up the brewing system after use.
void BrewingEngine::cleanUp() {
    simulateLoading(" Cleaning up brewing equipment");
}
