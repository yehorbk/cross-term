#include "main.hpp"

int main() {
    FileManager fm = FileManager();
    map<string, string> commandsList = fm.loadFile(COMMANDS_FILE);
    CommandManager commandManager = CommandManager(commandsList);
    showGreetings();
    startShell(commandManager);
    return 0;
}

void startShell(CommandManager commandManager) {
    string command;
    while(true) {
        getline(cin, command);
        commandManager.executeCommand(command);
    }
}

void showGreetings() {
    cout << endl << "Welcome to cross-term!" << endl;
}
