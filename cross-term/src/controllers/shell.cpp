#include "shell.hpp"

namespace Controllers {

    Shell::Shell(Models::Config config, CommandManager commandManager) {
        this->config = config;
        this->commandManager = commandManager;
    }

    void Shell::startShell() {
        showGreetings();
        string command;
        while(true) {
            showCommandPrompt();
            getline(cin, command);
            this->commandManager.executeCommand(command);
        }
    }

    void Shell::showGreetings() {
        string greeting = this->commandManager.getCommandResult(this->config.getGreeting().c_str());
        cout << greeting;
    }

    void Shell::showCommandPrompt() {
        string prompt = this->commandManager.getCommandResult(this->config.getPrompt().c_str());
        cout << prompt;
    }

}
