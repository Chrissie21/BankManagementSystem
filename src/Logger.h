#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>
using namespace std;

class Logger {
private:
    ofstream logFile; // Output file stream to log into a file.

public:
    // Constructor that accepts the log filename
    Logger(const string& filename);

    // Function to log messages
    void log(const string& message);

    // Destructor (if needed for file cleanup, etc.)
    ~Logger();
};

#endif // LOGGER_H
