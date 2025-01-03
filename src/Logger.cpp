#include "Logger.h"
#include <fstream>
#include <iostream>

Logger::Logger(const string& file) : filename(file) {}

void Logger::log(const string& message) {
    ofstream logFile;
    logFile.open(filename, ios::app); // Open the file in append mode
    if (logFile.is_open()) {
        logFile << message << endl; // Write message to log file
        logFile.close(); // Close the log file
    } else {
        cerr << "Error opening log file!" << endl;
    }
}

Logger::~Logger() {
    // Cleanup resources if needed
}
