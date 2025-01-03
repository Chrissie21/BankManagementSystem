#ifndef LOGGER_H
#define LOGGER_H

#include <string>
using namespace std;

class Logger {
private:
    string filename;

public:
    // Constructor that accepts the log filename
    Logger(const string& file);

    // Function to log messages
    void log(const string& message);

    // Destructor (if needed for file cleanup, etc.)
    ~Logger();
};

#endif // LOGGER_H
