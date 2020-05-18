#pragma once

#include "imports.hpp"

namespace Managers {

    class CommandManager {
    private:
        map<string, string> commandsList;
        string getCommandByKey(string command);
    public:
        CommandManager(map<string, string> commandsList);
        bool executeCommand(string command);
    };
    
}
