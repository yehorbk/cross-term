#include "logger.hpp"

void Logger::out(string message, string key) {
    cout << key << ": " << message << endl;
}

void Logger::error(Error error) {
    Logger::out(error.getMessage(), "Error");
}
