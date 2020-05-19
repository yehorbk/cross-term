#include "file_manager.hpp"

namespace Managers {

    FileManager::FileManager(string path) {
        string file = path.substr(0, path.find_last_of("/")) + this->SETTINGS_FILENAME;
        xml_parse_result parseResult = this->doc.load_file(file.c_str());
        if (parseResult.description() == "File was not found") {
            Logger::error(Error::SETTINGS_FILE_NOT_FOUND);
        }
    }

    map<string, string> FileManager::loadCommands() {
        map<string, string> result;
        xml_node commands = this->doc.child("commands");
        for (xml_node command : commands.children("Item")) {
            string title = command.child_value("command");
            string execute = command.child_value("execute");
            result.insert(pair<string, string>(trim(title), trim(execute)));
        }
        return result;
    }

    Models::Config FileManager::loadConfig() {
        xml_node settings = this->doc.child("settings");
        string greeting = settings.child_value("greeting");
        string prompt = settings.child_value("prompt");
        return Models::Config(greeting, prompt);
    }

}
