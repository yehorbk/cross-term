#include <fstream>

#include "file_manager.hpp"
#include "trim.hpp"
#include "pugixml.hpp"

using namespace pugi;

namespace Managers {

    FileManager::FileManager() {}

    map<string, string> FileManager::loadCommands(string path) {
        map<string, string> result;

        xml_document doc;
        xml_parse_result parseResult = doc.load_file("tree.xml");

        xml_node settings = doc.child("settings");
        xml_node commands = doc.child("commands");
        
        for (xml_node command : commands.children("Item")) {
            string title = command.child_value("command");
            string execute = command.child_value("execute");
            result[title] = ltrim(execute);
        }
        return result;
    }

}

// cout << "Load result: " << parseResult.description() << endl;

        /*cout << "My result: ";
        cout << doc.child("settings").child("prompt").text() << endl;
        cout << doc.child("settings").child("prompt").name() << endl;
        cout << doc.child("settings").child_value("greetings") << endl;
        cout << doc.child("settings").child("greetings").child_value() << endl;
        cout << doc.child("settings").child("greetings").name() << endl;
        cout << "end of my result: " << endl;*/

        /*for (pugi::xml_node_iterator it = doc.begin(); it != doc.end(); ++it)
        {
            std::cout << "Tool:";

            for (pugi::xml_attribute_iterator ait = it->attributes_begin(); ait != it->attributes_end(); ++ait)
            {
                std::cout << " " << ait->name() << "=" << ait->value();
            }

            std::cout << std::endl;
        }*/

 /*ifstream in ("commands.json", std::ifstream::binary);
        Json::Value root;*/

        /*Json::CharReaderBuilder builder;
        builder["collectComments"] = true;
        JSONCPP_STRING errs;

        if (!parseFromStream(builder, in, &root, &errs)) {
            std::cout << errs << std::endl;
        }
        std::cout << root << std::endl;*/


// #include "INIReader.h"

 /*map<string, string> result;
        INIReader reader("commands.ini");
        if (reader.ParseError() < 0) {
            std::cout << "Can't load 'test.ini'\n";
            return result;
        }
        std::cout << "Config loaded from 'test.ini': version="
                << reader.GetInteger("protocol", "version", -1) << ", name="
                << reader.Get("user", "name", "UNKNOWN") << ", email="
                << reader.Get("user", "email", "UNKNOWN") << ", pi="
                << reader.GetReal("user", "pi", -1) << ", active="
                << reader.GetBoolean("user", "active", true) << "\n";
        

        return result;*/

/* Value commands;
        
        ifstream in ("commands.json", std::ifstream::binary);
        in >> commands;
        cout << commands;*/

        /*ifstream in(path);
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
        in.close();*/
