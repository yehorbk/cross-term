#include "file_manager.hpp"

namespace Managers {

    FileManager::FileManager() {
        xml_document doc;
        xml_parse_result parseResult = doc.load_file(this->PATH.c_str());
        cout << "File loaded with result: " << parseResult.description() << endl;
        this->settings = doc.child("settings");
        this->commands = doc.child("commands");
    }

    map<string, string> FileManager::loadCommands() {
        map<string, string> result;        
        for (xml_node command : this->commands.children("Item")) {
            string title = command.child_value("command");
            string execute = command.child_value("execute");
            result[title] = ltrim(execute);
        }
        return result;
    }

}
