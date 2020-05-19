#pragma once

#include "imports.hpp"

namespace Models {

    class Config {
    private:
        string greeting;
        string prompt;
    public:
        Config();
        Config(string greeting, string prompt);
        string getGreeting();
        string getPrompt();
        string toString();
    };

}
