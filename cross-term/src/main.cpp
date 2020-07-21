#include "main.hpp"

int main(int argc, char *argv[]) {
    SettingsManager settingsManager = SettingsManager();
    Models::Config config = settingsManager.loadConfig();
    CommandManager commandManager = CommandManager(settingsManager
        .loadCommands());
    Shell shell = Shell(config, commandManager);
    shell.startShell();
    return 0;
}
