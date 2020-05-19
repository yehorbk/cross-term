#include "main.hpp"

int main(int argc, char *argv[]) {
    FileManager fileManager = FileManager(argv[0]);
    Models::Config config = fileManager.loadConfig();
    CommandManager commandManager = CommandManager(fileManager.loadCommands());
    Shell shell = Shell(config, commandManager);
    shell.startShell();
    return 0;
}
