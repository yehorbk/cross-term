#pragma once

#if __has_include(<filesystem>)
#  include <filesystem>
#else
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
    public:
        FileManager(string path);
        map<string, string> loadCommands();
        Models::Config loadConfig();

    private:
        xml_document doc;
        const string SETTINGS_FILENAME = "/settings.xml";
        void logFileLoading(string result);
    };

}
