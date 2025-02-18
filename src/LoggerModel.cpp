#include "LoggerModel.h"
#include <iostream>
#include <chrono>
#include <iomanip>

/**
 * @brief Logs an event message.
 *
 * The function prepends a timestamp to the log entry.
 *
 * @param msg The event message to log.
 */
void LoggerModel::logEvent(const std::string &msg) {
    // Get current time as a simple timestamp.
    auto now = std::chrono::system_clock::now();
    auto time_t_now = std::chrono::system_clock::to_time_t(now);

    // Format the time as a string.
    std::string timeStr = std::string(std::ctime(&time_t_now));
    // Remove the trailing newline.
    if (!timeStr.empty() && timeStr.back() == '\n')
        timeStr.pop_back();

    std::string logEntry = "[EVENT " + timeStr + "] " + msg;
    m_logs.push_back(logEntry);
    std::cout << logEntry << std::endl;
}

/**
 * @brief Logs an error message.
 *
 * The function prepends a timestamp and "ERROR" tag to the log entry.
 *
 * @param err The error message to log.
 */
void LoggerModel::logError(const std::string &err) {
    // Get current time as a simple timestamp.
    auto now = std::chrono::system_clock::now();
    auto time_t_now = std::chrono::system_clock::to_time_t(now);
    
    // Format the time as a string.
    std::string timeStr = std::string(std::ctime(&time_t_now));
    // Remove the trailing newline.
    if (!timeStr.empty() && timeStr.back() == '\n')
        timeStr.pop_back();

    std::string logEntry = "[ERROR " + timeStr + "] " + err;
    m_logs.push_back(logEntry);
    std::cerr << logEntry << std::endl;
}

/**
 * @brief Displays all logged messages.
 *
 * This function prints all log messages stored in memory.
 */
void LoggerModel::showLogs() const {
    std::cout << "\n---- Log History ----\n";
    for (const auto &entry : m_logs) {
        std::cout << entry << std::endl;
    }
    std::cout << "---------------------\n";
}
