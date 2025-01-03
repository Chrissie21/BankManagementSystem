#include "Logger.h"
#include <iostream>
using namespace std;

// Constructor initializes the log file
Logger::Logger(const string& filename) {
    logFile.open(filename, ios::out | ios::app);  // Open log file in append mode
    if (!logFile) {
        cerr << "Error opening log file!" << endl;
    }
}

// Logs the message to the file
void Logger::log(const string& message) {
    if (logFile) {
        logFile << message << endl;  // Write the message to the log file
    }
}

// Destructor closes the log file
Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}
