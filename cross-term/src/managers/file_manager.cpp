#include <fstream>
#include <json/json.h>

#include "managers.hpp"
#include "trim.hpp"


namespace Managers {

    FileManager::FileManager() {}

    map<string, string> FileManager::loadCommands(string path) {
        map<string, string> result;
        ifstream in(path);
        if (in.is_open()) {
            string title, commands;
            while (in >> title) {
                getline(in, commands);
                result[title] = ltrim(commands);
            }
        } else {
            ofstream out(path);
            out.close();
            return loadCommands(path);
        }
        in.close();
        return result;
    }

}
