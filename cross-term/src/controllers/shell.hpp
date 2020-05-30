#pragma once

#include "imports.hpp"
#include "config.hpp"
#include "command_manager.hpp"

using namespace Managers;

namespace Controllers {

    class Shell {
    public:
        Shell(Models::Config config, CommandManager commandManager);
        void startShell();

    private:
        Models::Config config;
        CommandManager commandManager;
        void showGreetings();
        void showCommandPrompt();
    };

}
