#pragma once

#include <fstream>
#include <filesystem>
#include "pugixml.hpp"
#include "trim.hpp"

#include "imports.hpp"
#include "logger.hpp"
#include "config.hpp"

using namespace pugi;

namespace Managers {

    class FileManager {
    private:
        const string SETTINGS_FILENAME = "/settings.xml";
        xml_document doc;
        void logFileLoading(string result);
    public:
        FileManager(string path);
        map<string, string> loadCommands();
        Models::Config loadConfig();
    };

}
