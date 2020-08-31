#include "settings_manager.hpp"

namespace Managers {

    SettingsManager::SettingsManager() {
        this->initSettingsFilePath();
        if (!this->checkIsFileExists()) {
            this->createSettingsFile();
        }
        this->loadSettingsFile();
    }

    Models::Config SettingsManager::loadConfig() {
        xml_node settings = this->doc
            .child(SettingsFileIdentifiers::SETTINGS);
        string greeting = settings
            .child_value(SettingsFileIdentifiers::GREETING);
        string prompt = settings
            .child_value(SettingsFileIdentifiers::PROMPT);
        return Models::Config(greeting, prompt);
    }

    map<string, string> SettingsManager::loadCommands() {
        map<string, string> result;
        xml_node commands = this->doc
            .child(SettingsFileIdentifiers::COMMANDS);
        for (xml_node item : commands.children(
                SettingsFileIdentifiers::ITEM)) {
            string command = item
                .child_value(SettingsFileIdentifiers::COMMAND);
            string execute = item
                .child_value(SettingsFileIdentifiers::EXECUTE);
            result.insert(pair<string, string>(
                trim(command),
                trim(execute)
            ));
        }
        return result;
    }

    void SettingsManager::initSettingsFilePath() {
        string HOME;
        const string FILENAME = "crossterm.xml";
        #if unix || __APPLE__ || __linux__
            HOME = string(getenv("HOME")) + "/";
        #elif _WIN32
            HOME = string(getenv("USERPROFILE")) + "\\";
        #endif
        this->settingsFilePath = HOME + FILENAME;
    }

    bool SettingsManager::checkIsFileExists() {
        ifstream file(this->settingsFilePath);
        return file.is_open();
    }

    void SettingsManager::createSettingsFile() {
        xml_document file;
        xml_node settings = file
            .append_child(SettingsFileIdentifiers::SETTINGS);
        xml_node commands = file
            .append_child(SettingsFileIdentifiers::COMMANDS);
        settings.append_child(SettingsFileIdentifiers::GREETING)
            .text().set("");
        settings.append_child(SettingsFileIdentifiers::PROMPT)
            .text().set(DefaultConfiguration::PROMPT);
        xml_node firstCommand = commands
            .append_child(SettingsFileIdentifiers::ITEM);
        firstCommand.append_child(SettingsFileIdentifiers::COMMAND)
            .text().set(DefaultConfiguration::COMMAND);
        firstCommand.append_child(SettingsFileIdentifiers::EXECUTE)
            .text().set(DefaultConfiguration::EXECUTE);
        file.save_file(this->settingsFilePath.c_str());
    }

    void SettingsManager::loadSettingsFile() {
        this->doc.load_file(this->settingsFilePath.c_str());
    }

}
