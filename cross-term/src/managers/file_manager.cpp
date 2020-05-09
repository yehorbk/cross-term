#include <fstream>

#include "imports.hpp"
#include "trim.hpp"
#include "managers.hpp"

namespace Managers {

    FileManager::FileManager() {}

    map<string, string> FileManager::loadFile(string path) {
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
            return loadFile(path);
        }
        in.close();
        return result;
    }

}