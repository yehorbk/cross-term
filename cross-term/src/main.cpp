#include "main.hpp"

int main() {
    FileManager fm = FileManager();
    map<string, string> commandsList = fm.loadCommands();
    Models::Config config = fm.loadConfig();
    CommandManager commandManager = CommandManager(commandsList);
    Shell shell = Shell(config, commandManager);
    shell.startShell();
    return 0;
}
