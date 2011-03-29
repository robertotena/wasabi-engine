/* 
 * File:   ConfigurationFileParser.h
 * Author: Fran_2
 *
 * Created on 3 de marzo de 2011, 12:06
 */

#ifndef CONFIGURATIONFILEPARSER_H
#define	CONFIGURATIONFILEPARSER_H

#include <string>
#include <fstream>
#include <iostream>
#include <WasabiEngine/Utils/PropertyMap.h>

namespace WasabiEngine {

    /**
     * Reads pairs of Key = Value on a file and puts the values on a PropertyMap.
     * Lines with '#' are comments
     */
    class ConfigurationFileParser {
    private:
        PropertyMap<std::string, std::string> map;
        bool parseLine(std::string line);
    public:
        /**
         * Load a configuration file
         * @param file relative path to file
         * @return true if we are ok.
         */
        bool load(const std::string& file);
        void clear();
        std::string get(const std::string& property);
    };
}
#endif	/* CONFIGURATIONFILEPARSER_H */

