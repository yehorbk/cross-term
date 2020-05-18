#include "config.hpp"

namespace Models {

    Config::Config(string greeting, string prompt) {
        this->greeting = greeting;
        this->prompt = prompt;
    }

    string Config::getGreeting() {
        return this->greeting;
    }

    string Config::getPrompt() {
        return this->prompt;
    }

}