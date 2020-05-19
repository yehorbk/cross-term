#pragma once

#include <regex>
#include <unistd.h>
#include "trim.hpp"

#include "imports.hpp"
#include "logger.hpp"

namespace Managers {

    class CommandManager {
    private:
        string specialCommands[1] = { "cd" };
        map<string, string> commandsList;
        string getCommandByKey(string command);
        bool checkIsSpecialCommand(string command);
        void executeSpecial(string command, string args);
    public:
        CommandManager();
        CommandManager(map<string, string> commandsList);
        bool executeCommand(string command);
        string getCommandResult(string command);
    };
    
}
