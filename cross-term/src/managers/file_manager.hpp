#pragma once

#if __has_include(<filesystem>)
#  include <filesystem>
#elif __has_include(<experimental/filesystem>)
#  include <experimental/filesystem>
#endif

#include <fstream>
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
