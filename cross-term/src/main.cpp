#include "managers.hpp"

using namespace Managers;

int main() {
    FileManager fm = FileManager();
    map<string, string> commandsList = fm.loadFile("myfile.txt");

    
    /*for (auto it = commandsList.begin(); it != commandsList.end(); ++it)
    {
        cout << it->first << " : " << it->second << endl;
    }*/
    /*CommandManager commandManager = CommandManager();
    string command;
    while(true) {
        getline(cin, command);
        commandManager.executeCommand(command);
    }*/
    return 0;
}
