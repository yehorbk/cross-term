#pragma once

#include "imports.hpp"
#include "error.hpp"

class Logger {
public:
    static void out(string message, string key = "Log");
    static void error(Error error);
};
