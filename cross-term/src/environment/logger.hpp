#pragma once

#include "environment/imports.hpp"
#include "environment/error.hpp"

class Logger {
public:
    static void out(string message, string key = "Log");
    static void error(Error error);
};
