#pragma once

#include <regex>
#if unix || __APPLE__ || __linux__
    #include <unistd.h>
#elif _WIN32
    #include <direct.h>
    #define popen  _popen
    #define pclose  _pclose
#endif


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
