#include "Logger.h"
#include <iostream>
#include <string>
#include <chrono>
#include <ctime>

std::vector<LogEntry> Logger::messages;

// Method to get the current date and time as a string
std::string CurrentDateTimeToString() 
{
    std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::string output(30, '\0');
    std::strftime(&output[0], output.size(), "%d-%b-%Y %H:%M:%S", std::localtime(&now));
    return output;
}

// Method to log messages
void Logger::Log(const std::string& message) 
{
    LogEntry logEntry;
    logEntry.type = LOG_INFO;
    logEntry.message = "LOG: [" + CurrentDateTimeToString() + "]: " + message;
    std::cout << "\033[32m" << logEntry.message << "\033[0m" << std::endl; // Green color
    
    messages.push_back(logEntry);
}

// Nethod to log error messages
void Logger::Err(const std::string& message) 
{
    LogEntry logEntry;
    logEntry.type = LOG_ERROR;
    logEntry.message = "ERR: [" + CurrentDateTimeToString() + "]: " + message;
    std::cerr << "\033[31m" << logEntry.message << "\033[0m" << std::endl; // Red color

    messages.push_back(logEntry);
}
