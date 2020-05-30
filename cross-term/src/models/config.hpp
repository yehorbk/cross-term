#pragma once

#include "imports.hpp"

namespace Models {

    class Config {
    public:
        Config();
        Config(string greeting, string prompt);
        string getGreeting();
        string getPrompt();
        string toString();

    private:
        string greeting;
        string prompt;
    };

}
