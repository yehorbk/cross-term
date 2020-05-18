#pragma once

#include "imports.hpp"

namespace Managers {

    class FileManager {
    public:
        FileManager();
        map<string, string> loadCommands(string path);
    };

}
