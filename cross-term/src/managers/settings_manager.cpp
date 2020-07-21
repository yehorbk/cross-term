#include "settings_manager.hpp"

namespace Managers {

    SettingsManager::SettingsManager() {
        this->initSettingsFilePath();
        if (!this->checkIsFileExists()) {
            this->createSettingsFile();
        }
        this->loadSettingsFile();
    }

    map<string, string> SettingsManager::loadCommands() {
        map<string, string> result;
        xml_node commands = this->doc.child("commands");
        for (xml_node command : commands.children("Item")) {
            string title = command.child_value("command");
            string execute = command.child_value("execute");
            result.insert(pair<string, string>(trim(title), trim(execute)));
        }
        return result;
    }

    Models::Config SettingsManager::loadConfig() {
        xml_node settings = this->doc.child("settings");
        string greeting = settings.child_value("greeting");
        string prompt = settings.child_value("prompt");
        return Models::Config(greeting, prompt);
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
        xml_node settings = file.append_child("settings");
        xml_node commands = file.append_child("commands");
        settings.append_child("greeting").text().set("");
        settings.append_child("prompt").text().set("printf \"$ \"");
        xml_node firstCommand = commands.append_child("Item");
        firstCommand.append_child("command").text().set("hello");
        firstCommand.append_child("execute").text().set("echo \"Hello Cross-term!\"");
        file.save_file(this->settingsFilePath.c_str());
    }

    void SettingsManager::loadSettingsFile() {
        this->doc.load_file(this->settingsFilePath.c_str());
    }

}
