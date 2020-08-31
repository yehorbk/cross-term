#include "main.hpp"

int main(int argc, char *argv[]) {
    SettingsManager settingsManager = SettingsManager();
    Models::Config config = settingsManager.loadConfig();
    map<string, string> commands = settingsManager.loadCommands();
    CommandManager commandManager = CommandManager(commands);
    Shell shell = Shell(config, commandManager);
    shell.startShell();
    return 0;
}
