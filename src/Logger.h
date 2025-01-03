#include "Logger.h"
#include <iostream>
#include <ctime>
#include <iomanip>

Logger::Logger(const std::string& filename) {
    logFile.open(filename, std::ios::app);
    if (!logFile) {
        std::cerr << "Failed to open log file: " << filename << std::endl;
    }
}

void Logger::log(const std::string& message) {
    if (logFile) {
        // Add timestamp
        auto t = std::time(nullptr);
        auto tm = *std::localtime(&t);
        logFile << "[" << std::put_time(&tm, "%Y-%m-%d %H:%M:%S") << "] " << message << std::endl;
    }
}

Logger::~Logger() {
    if (logFile) {
        logFile.close();
    }
}
