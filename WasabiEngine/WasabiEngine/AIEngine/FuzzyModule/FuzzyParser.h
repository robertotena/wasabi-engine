/* 
 * File:   FuzzyParser.h
 * Author: Roberto
 *
 * Created on 16 de marzo de 2011, 20:44
 */

#ifndef FUZZYPARSER_H
#define	FUZZYPARSER_H

#include <WasabiEngine/AIEngine/FuzzyModule/FuzzyModule.h>
#include <WasabiEngine/AIEngine/FuzzyModule/FzAnd.h>
#include <WasabiEngine/AIEngine/FuzzyModule/FzOr.h>
#include <WasabiEngine/AIEngine/FuzzyModule/FuzzyTerm.h>
#include <WasabiEngine/AIEngine/FuzzyModule/FzVery.h>
#include <WasabiEngine/AIEngine/FuzzyModule/FzFairly.h>
#include <WasabiEngine/AIEngine/FuzzyModule/FzSet.h>
#include <stdexcept>
#include <map>
#include <vector>
#include <set>
#include <iostream>
#include <fstream>
#include <sstream>

namespace WasabiEngine
{

/**
* Is a text file fuzzy module parser.
*
* This class is able to read a text file with a defined syntax and load a fuzzy
* module.
*/
class FuzzyParser {
private:
    static const std::string VAR;
    static const std::string RULE;
    static const std::string SET;
    static const std::string AND;
    static const std::string OR;
    static const std::string VERY;
    static const std::string FAIRLY;
    static const std::string TRIANGLE;
    static const std::string TRAPEZOID;
    static const std::string LSHOULDER;
    static const std::string RSHOULDER;
    static const std::string SINGLETON;
    static const std::string METHOD;
    static const std::string MAX_AV;
    static const std::string CENTROID;
    static const std::string COMMENT_TOKEN;

    FuzzyModule* fm;
    std::map<std::string, FuzzyVariable*> variables;
    std::set<std::string> antecedents;
    std::set<std::string> consequents;

    void clear();
    bool parseLine(const std::string& line, const int& nLine);
    bool parseMethod(std::stringstream& ss, const int& nLine);
    bool parseVar(std::stringstream& ss, const int& nLine);
    bool parseSet(std::stringstream& ss, const int& nLine);
    bool parseRule(std::stringstream& ss, const int& nLine);
    FuzzyTerm* parseExpression(std::stringstream& ss, const int& nLine);
    FuzzyParser(const FuzzyParser& orig);
public:
    /**
    * Loads the fuzzy module from the specified file.
    * @param fileName The name of the file to load the module from.
    * @return The loaded fuzzy module.
    */
    FuzzyModule* loadModule(const char* fileName);
    FuzzyParser();
    ~FuzzyParser();
};

}

#endif	/* FUZZYPARSER_H */

