#include "managers.hpp"

namespace Managers {

    CommandManager::CommandManager() {}

    bool CommandManager::executeCommand(string command) {
        int error = system(command.c_str());
        return error == 0 ? true : false;
    }

}
