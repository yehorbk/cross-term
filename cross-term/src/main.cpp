#include "main.hpp"

int main() {
    FileManager fm = FileManager();
    map<string, string> commandsList = fm.loadCommands();
    Models::Config config = fm.loadConfig();
    cout << config.toString() << endl;
    CommandManager commandManager = CommandManager(commandsList);
    Shell shell = Shell();
    shell.startShell(commandManager);
    return 0;
}
