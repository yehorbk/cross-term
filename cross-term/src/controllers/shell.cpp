#include "shell.hpp"

namespace Controllers {

    Shell::Shell() {}

    void Shell::startShell(CommandManager commandManager) {
        showGreetings();
        string command;
        while(true) {
            showCommandPrompt();
            getline(cin, command);
            commandManager.executeCommand(command);
        }
    }

    void Shell::showGreetings() {
        cout << endl << "Welcome to cross-term!" << endl;
    }

    void Shell::showCommandPrompt() {
        cout << "> ";
    }

}
