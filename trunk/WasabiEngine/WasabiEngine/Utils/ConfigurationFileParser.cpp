/* 
 * File:   ConfigurationFileParser.cpp
 * Author: Fran_2
 * 
 * Created on 3 de marzo de 2011, 12:06
 */

#include "ConfigurationFileParser.h"

using namespace WasabiEngine;

bool ConfigurationFileParser::load(const std::string& file) {
    map.clear();
    std::ifstream stream(file.c_str(), std::ios::in);
    if (stream.good()) {
        while (!stream.eof()) {
            char line[256];
            stream.getline(line, 256);
            if (!parseLine(std::string(line))) {
                std::cout << "Invalid line at configuration file " << file << " : " << line << ". Ignoring" << std::endl;
            }
        }
        stream.close();
        return true;
    } else {
        std::cout << "Can not read configuration file " << file << std::endl;
        return false;
    }
}

void ConfigurationFileParser::clear() {
    map.clear();
}

namespace {

    enum ParserState {
        KEY,
        PREEQUAL,
        EQUAL,
        POSTEQUAL,
        VALUE
    };
}

bool ConfigurationFileParser::parseLine(std::string line) {
    std::string key;
    std::string value;
    ParserState state = KEY;
    //Remove any return character ('\r') from the string
    line = line.substr(0, line.find_first_of('\r'));
    if (line.length() == 0 || line[0] == '#')
        return true;
    for (unsigned int i = 0; i < line.length(); i++) {
        switch (state) {
            case KEY:
                if (line[i] == ' ')
                    state = PREEQUAL;
                else if (line[i] == '=')
                    state = EQUAL;
                else
                    key += line[i];
                break;
            case PREEQUAL:
                if (line[i] == ' ')
                    ;
                else if (line[i] == '=')
                    state = EQUAL;
                else
                    return false;
                break;
            case EQUAL:
                if (line[i] == ' ')
                    state = POSTEQUAL;
                else {
                    state = VALUE;
                    value += line[i];
                }
                break;
            case POSTEQUAL:
                if (line[i] == ' ')
                    ;
                else {
                    state = VALUE;
                    value += line[i];
                }
                break;
            case VALUE:
                if (line[i] == ' ')
                    return true;
                else
                    value += line[i];
                break;
        }
    }
    if (state != VALUE)
        return false;

    map.set(key, value);
    return true;
}

std::string ConfigurationFileParser::get(const std::string& property) {
    if (map.get(property))
        return *map.get(property);
    else
        return "";
}
