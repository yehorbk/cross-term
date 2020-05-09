#include "imports.hpp"
#include "managers.hpp"

using namespace Managers;

int main() {
    FileManager fm = FileManager();
    map<string, string> commandsList = fm.loadFile("myfile.txt");
    CommandManager commandManager = CommandManager(commandsList);
    string command;
    while(true) {
        getline(cin, command);
        commandManager.executeCommand(command);
    }
    return 0;
}
