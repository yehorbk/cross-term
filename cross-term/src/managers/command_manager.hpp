#pragma once

#include "imports.hpp"
#include "logger.hpp"

namespace Managers {

    class CommandManager {
    private:
        map<string, string> commandsList;
        string getCommandByKey(string command);
    public:
        CommandManager();
        CommandManager(map<string, string> commandsList);
        bool executeCommand(string command);
        string getCommandResult(string command);
    };
    
}
