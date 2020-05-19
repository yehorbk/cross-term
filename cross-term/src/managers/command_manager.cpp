#include <regex>

#include "command_manager.hpp"

namespace Managers {

    CommandManager::CommandManager() {}

    CommandManager::CommandManager(map<string, string> commandsList) {
        CommandManager::commandsList = commandsList;
    }

    bool CommandManager::executeCommand(string input) {
        string command = getCommandByKey(input);
        int error = system(command.c_str());
        return error == 0 ? true : false;
    }

    string CommandManager::getCommandByKey(string command) {
        string result = command;
        if (CommandManager::commandsList.size() != 0) {
            for(auto& item : CommandManager::commandsList) {
                if (command.find(item.first) != -1) {
                    result = regex_replace(command, regex(item.first), item.second);
                }
            }
        } else {
            result = command;
        }
        return result;
    }

    string CommandManager::getCommandResult(string command) {
        char buffer[128];
        string result = "";
        FILE* pipe = popen(command.c_str(), "r");
        if (!pipe) {
            Logger::error(Error::CANNOT_OPEN_PIPE);
            return "";
        }
        while (!feof(pipe)) {
            if (fgets(buffer, 128, pipe) != NULL)
                result += buffer;
        }
        pclose(pipe);
        return result;
    }

}
