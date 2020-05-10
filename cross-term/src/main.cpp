#include "main.hpp"

int main() {
    FileManager fm = FileManager();
    map<string, string> commandsList = fm.loadCommands(COMMANDS_FILE);
    CommandManager commandManager = CommandManager(commandsList);
    Shell shell = Shell();
    shell.startShell(commandManager);
    return 0;
}
