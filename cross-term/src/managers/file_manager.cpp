#include "file_manager.hpp"

namespace Managers {

    FileManager::FileManager() {
        xml_parse_result parseResult = this->doc.load_file(this->PATH.c_str());
        cout << "File loaded with result: " << parseResult.description() << endl;
    }

    map<string, string> FileManager::loadCommands() {
        map<string, string> result;
        xml_node commands = this->doc.child("commands");
        for (xml_node command : commands.children("Item")) {
            string title = command.child_value("command");
            string execute = command.child_value("execute");
            result[title] = ltrim(execute);
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
