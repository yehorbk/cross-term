#pragma once

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
        SettingsManager();
        map<string, string> loadCommands();
        Models::Config loadConfig();

    private:
        xml_document doc;
        string settingsFilePath;
        void initSettingsFilePath();
        void logFileLoading(string result);
        bool checkIsFileExists();
        void createSettingsFile();
        void loadSettingsFile();
    };

}
