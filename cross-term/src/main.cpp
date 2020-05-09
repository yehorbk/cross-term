#include "managers.hpp"

using namespace Managers;

int main() {
    CommandManager commandManager = CommandManager();
    string command;
    while(true) {
        getline(cin, command);
        commandManager.executeCommand(command);
    }
    return 0;
}
