#pragma once

#include "imports.hpp"
#include "command_manager.hpp"

using namespace Managers;

namespace Controllers {

    class Shell {
    private:
        string greetings;
        string prompt;
        void showGreetings();
        void showCommandPrompt();
    public:
        Shell();
        void startShell(CommandManager commandManager);
    };

}
