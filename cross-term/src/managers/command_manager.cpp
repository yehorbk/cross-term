#include <regex>

#include "imports.hpp"
#include "managers.hpp"

namespace Managers {

    CommandManager::CommandManager(map<string, string> commandsList) {
        CommandManager::commandsList = commandsList;
    }

    bool CommandManager::executeCommand(string input) {
        string command = getCommandByKey(input);
        int error = system(command.c_str());
        return error == 0 ? true : false;
    }

    string CommandManager::getCommandByKey(string command) {
        string result;
        if (CommandManager::commandsList.size() != 0) {
            for(auto& item : CommandManager::commandsList) {
                result = regex_replace(command, regex(item.first), item.second);
            }
        } else {
            result = command;
        }
        return result;
    }

}
