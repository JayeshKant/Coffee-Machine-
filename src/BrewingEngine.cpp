#include "BrewingEngine.h"
#include <iostream>
#include <chrono>
#include <thread>

// Helper function to simulate a loading animation.
static void simulateLoading(const std::string& action, int dotCount = 3, int delayMs = 500) {
    std::cout << action;
    for (int i = 0; i < dotCount; i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
        std::cout << ".";
    }
    std::cout << "\n";
}

BrewingEngine::BrewingEngine() {
    // Initialization if needed.
}

void BrewingEngine::grindBeans() {
    simulateLoading("Grinding beans");
}

void BrewingEngine::heatWater() {
    simulateLoading("Heating water");
}

void BrewingEngine::preInfuse() {
    simulateLoading("Pre-infusing coffee grounds");
}

void BrewingEngine::extract() {
    simulateLoading("Extracting coffee");
}

void BrewingEngine::dispense() {
    simulateLoading("Dispensing coffee");
}

void BrewingEngine::cleanUp() {
    simulateLoading("Cleaning up brewing equipment");
}
