#include "MaintenanceModel.h"
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

MaintenanceModel::MaintenanceModel() : m_needsMaintenance(false) {
    // Initialization if needed.
}

void MaintenanceModel::performMaintenance() {
    if (m_needsMaintenance) {
        simulateLoading("Performing maintenance");
        m_needsMaintenance = false;
        std::cout << "Maintenance completed.\n";
    } else {
        std::cout << "No maintenance is required at this time.\n";
    }
}

bool MaintenanceModel::needsMaintenance() const {
    return m_needsMaintenance;
}

void MaintenanceModel::triggerMaintenance() {
    m_needsMaintenance = true;
    std::cout << "Maintenance has been triggered.\n";
}
