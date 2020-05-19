#include "main.hpp"

int main() {
    FileManager fm = FileManager();
    Models::Config config = fm.loadConfig();
    CommandManager commandManager = CommandManager(fm.loadCommands());
    Shell shell = Shell(config, commandManager);
    shell.startShell();
    return 0;
}
