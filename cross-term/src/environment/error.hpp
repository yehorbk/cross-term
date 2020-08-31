#pragma once

#include "environment/imports.hpp"

enum ErrorCase {
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
        }
    };
};
