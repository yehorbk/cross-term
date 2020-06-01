#pragma once

#include <regex>
#include <unistd.h>

#include "lib/trim/trim.hpp"

#include "environment/imports.hpp"
#include "environment/logger.hpp"

namespace Managers {

    class CommandManager {
    public:
        CommandManager();
        CommandManager(map<string, string> commandsList);
        bool executeCommand(string command);
        string getCommandResult(string command);

    private:
        string specialCommands[1] = { "cd" };
        map<string, string> commandsList;
        string getCommandByKey(string command);
        bool checkIsSpecialCommand(string command);
        void executeSpecial(string command, string args);
    };

}
