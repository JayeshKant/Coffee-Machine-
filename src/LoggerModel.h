#pragma once

#include <string>
#include <vector>

/**
 * @file LoggerModel.h
 * @brief Declaration of the LoggerModel class.
 *
 * This class logs events and errors for the coffee machine.
 * It can display logs, store them in memory, and print messages to the console.
 */
class LoggerModel {
private:
    /// Stores the log messages.
    std::vector<std::string> m_logs;

public:
    /**
     * @brief Default constructor.
     */
    LoggerModel() = default;

    /**
     * @brief Default destructor.
     */
    ~LoggerModel() = default;

    /**
     * @brief Logs an event message.
     *
     * @param msg The event message to log.
     */
    void logEvent(const std::string &msg);

    /**
     * @brief Logs an error message.
     *
     * @param err The error message to log.
     */
    void logError(const std::string &err);

    /**
     * @brief Displays all logged messages to the console.
     */
    void showLogs() const;
};
