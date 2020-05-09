#include <fstream>
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
                result[title] = commands;
            }
        } else {
            cout << "Cannot open the file!" << endl;
        }
        in.close();
        return result;
    }

}
