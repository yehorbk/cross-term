#pragma once

#include <fstream>

#include "imports.hpp"
#include "pugixml.hpp"
#include "trim.hpp"
#include "config.hpp"

using namespace pugi;

namespace Managers {

    class FileManager {
    private:
        string PATH = "settings.xml";
        xml_document doc;
    public:
        FileManager();
        map<string, string> loadCommands();
        Models::Config loadConfig();
    };

}
