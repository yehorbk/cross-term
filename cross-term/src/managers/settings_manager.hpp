#pragma once

#if unix || __APPLE__ || __linux__
    #define PATH_SEPARATOR "/"
#elif _WIN32
    #define PATH_SEPARATOR "\\"
#endif

#if __has_include(<filesystem>)
    #include <filesystem>
#elif __has_include(<experimental/filesystem>)
    #include <experimental/filesystem>
#endif
#include <fstream>

#include "lib/pugixml/pugixml.hpp"
#include "lib/trim/trim.hpp"

#include "environment/imports.hpp"
#include "environment/logger.hpp"
#include "models/config.hpp"

using namespace pugi;

namespace Managers {

    class SettingsManager {
    public:
        SettingsManager(string path);
        map<string, string> loadCommands();
        Models::Config loadConfig();

    private:
        const string SETTINGS_FILENAME = "/settings.xml";
        xml_document doc;
        void logFileLoading(string result);
    };

}
