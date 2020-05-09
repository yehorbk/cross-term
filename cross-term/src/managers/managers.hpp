#pragma once

#include "imports.hpp"

namespace Managers {
    class CommandManager {
    public:
        CommandManager();
        bool executeCommand(string command);
    };
    class FileManager {
    public:
        FileManager();
    };
}
