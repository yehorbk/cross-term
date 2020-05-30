#include "logger.hpp"

void Logger::out(string message, string key) {
    cout << key << ": " << message << endl;
}

void Logger::error(Error error) {
    switch (error) {
    case Error::CANNOT_OPEN_PIPE:
        Logger::out("Cannot open pipe to execute command and get result!", "Error");
        break;
    case Error::SETTINGS_FILE_NOT_FOUND:
        Logger::out("File not found! Make sure that the settings file is in the application folder. Settings not loaded.", "Error");
        break;
    default:
        break;
    }
}
