#include "command_manager.hpp"

namespace Managers {

    CommandManager::CommandManager() {}

    CommandManager::CommandManager(map<string, string> commandsList) {
        CommandManager::commandsList = commandsList;
    }

    bool CommandManager::executeCommand(string input) {
        string command = getCommandByKey(input);
        if (this->checkIsSpecialCommand(input)) {
            return true;
        } else {
            int error = system(command.c_str());
            return error == 0 ? true : false;
        }
    }

    string CommandManager::getCommandResult(string command) {
        char buffer[128];
        string result = "";
        FILE* pipe = popen(command.c_str(), "r");
        if (!pipe) {
            Logger::error(Error(ErrorCase::CANNOT_OPEN_PIPE));
            return "";
        }
        while (!feof(pipe)) {
            if (fgets(buffer, 128, pipe) != NULL) {
                result += buffer;
            }
        }
        pclose(pipe);
        return result;
    }

    string CommandManager::getCommandByKey(string command) {
        string result = command;
        if (CommandManager::commandsList.size() != 0) {
            for(auto& item : CommandManager::commandsList) {
                if (command.find(item.first) != -1) {
                    result = regex_replace(command,
                        regex(item.first), item.second);
                }
            }
        } else {
            result = command;
        }
        return result;
    }

    bool CommandManager::checkIsSpecialCommand(string command) {
        for (const string &key : this->specialCommands) {
            if (command.find(key) != -1) {
                string args = regex_replace(command, regex(key), "");
                this->executeSpecial(key, trim(args));
                return true;
            }
        }
        return false;
    }

    void CommandManager::executeSpecial(string command, string args) {        
        if (command == SpecialCommand::CD) {
            chdir(args.c_str());
        } else if (command == SpecialCommand::EXIT) {
            exit(0);
        }
    }

}
