#include "BrewingModel.h"
#include <iostream>

BrewingModel::BrewingModel() {
    // Create an instance of BrewingEngine.
    m_engine = new BrewingEngine();
}

BrewingModel::~BrewingModel() {
    delete m_engine;
}

void BrewingModel::startBrewing() {
    std::cout << "Starting brewing process...\n";
    // Call the steps in sequence.
    m_engine->grindBeans();
    m_engine->heatWater();
    m_engine->preInfuse();
    m_engine->extract();
    m_engine->dispense();
    std::cout << "Brewing process completed.\n";
}

void BrewingModel::stopBrewing() {
    std::cout << "Stopping brewing process...\n";
    m_engine->cleanUp();
}

void BrewingModel::handleBrewStateChange() {
    std::cout << "Handling brewing state change...\n";
    // Here you can update internal state or trigger notifications based on brewing progress.
}
