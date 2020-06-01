#pragma once

#include "environment/imports.hpp"

enum ErrorCase {
        SETTINGS_FILE_NOT_FOUND,
        CANNOT_OPEN_PIPE
};

class Error {
public:
    Error(ErrorCase errorCase);
    string getMessage();

private:
    ErrorCase errorCase;
    map<ErrorCase, string> errorMessages = {
        {
            ErrorCase::CANNOT_OPEN_PIPE,
            "Cannot open pipe to execute command and get result!"
        },
        {
            ErrorCase::SETTINGS_FILE_NOT_FOUND,
            "File not found! Make sure that the settings file is in the application folder. Settings not loaded."
        },
    };
};
