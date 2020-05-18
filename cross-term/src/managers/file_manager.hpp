#pragma once

#include <fstream>

#include "imports.hpp"
#include "pugixml.hpp"
#include "trim.hpp"

using namespace pugi;

namespace Managers {

    class FileManager {
    private:
        string PATH = "settings.xml";
        xml_node settings;
        xml_node commands;
    public:
        FileManager();
        map<string, string> loadCommands();
    };

}
