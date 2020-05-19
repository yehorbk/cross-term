#include "config.hpp"

namespace Models {

    Config::Config() {}

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

    string Config::toString() {
        return "Config { greeting = " + this->greeting + ", prompt = " 
            + this->prompt + " };";
    }

}
