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
#include "models/config.hpp"

using namespace pugi;

namespace Managers {

    class SettingsFileIdentifiers {
    public:
        // Config
        static constexpr const char* SETTINGS = "settings";
        static constexpr const char* GREETING = "greeting";
        static constexpr const char* PROMPT = "prompt";

        // Commands
        static constexpr const char* COMMANDS = "commands";
        static constexpr const char* ITEM = "item";
        static constexpr const char* COMMAND = "command";
        static constexpr const char* EXECUTE = "execute";
    };

    class DefaultConfiguration {
    public:
        // Prompt
        #if unix || __APPLE__ || __linux__
            static constexpr const char* PROMPT = "printf \"$ \"";
        #elif _WIN32
            static constexpr const char* PROMPT = "echo | set /p=$ ";
        #endif

        // Commands
        static constexpr const char* COMMAND = "hello";
        static constexpr const char* EXECUTE = "echo \"Hello Cross-term!\"";
    };

    class SettingsManager {
    public:
        SettingsManager();
        Models::Config loadConfig();
        map<string, string> loadCommands();

    private:
        string settingsFilePath;
        xml_document doc;
        void initSettingsFilePath();
        bool checkIsFileExists();
        void createSettingsFile();
        void loadSettingsFile();
    };

}
