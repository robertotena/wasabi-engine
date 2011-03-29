/* 
 * File:   FuzzyParser.cpp
 * Author: Roberto
 * 
 * Created on 16 de marzo de 2011, 20:44
 */

#include "FuzzyParser.h"

using namespace WasabiEngine;

const std::string FuzzyParser::VAR = "VAR";
const std::string FuzzyParser::RULE = "RULE";
const std::string FuzzyParser::SET = "SET";
const std::string FuzzyParser::AND = "AND";
const std::string FuzzyParser::OR = "OR";
const std::string FuzzyParser::VERY = "VERY";
const std::string FuzzyParser::FAIRLY = "FAIRLY";
const std::string FuzzyParser::TRIANGLE = "TRIANGLE";
const std::string FuzzyParser::TRAPEZOID = "TRAPEZOID";
const std::string FuzzyParser::LSHOULDER = "LSHOULDER";
const std::string FuzzyParser::RSHOULDER = "RSHOULDER";
const std::string FuzzyParser::SINGLETON = "SINGLETON";
const std::string FuzzyParser::METHOD = "METHOD";
const std::string FuzzyParser::MAX_AV = "MAX_AV";
const std::string FuzzyParser::CENTROID = "CENTROID";
const std::string FuzzyParser::COMMENT_TOKEN = "#";

FuzzyParser::FuzzyParser() {
}

FuzzyParser::FuzzyParser(const FuzzyParser& orig) {
    // not allowed
}

FuzzyParser::~FuzzyParser() {
    clear();
}

void FuzzyParser::clear()
{
    variables.clear();
    antecedents.clear();
    consequents.clear();
    fm = NULL;
}

FuzzyModule* FuzzyParser::loadModule(const char* filename)
{
    clear();
    bool success = true;

    int nLine = 0;
    std::ifstream file;
    file.open(filename, std::fstream::in);
    if(file.is_open())
    {
        fm = new FuzzyModule();
        std::string str;
        while(std::getline(file, str) && success)
        {
            nLine++;
            if(str.size() > 1 && str.substr(0,1) != COMMENT_TOKEN)
                success = parseLine(str, nLine);
        }
        if(!success)
        {
            delete fm;
            clear();
        }

    }
    else
    {
        fprintf(stderr, "Error: no se ha podido abrir el fichero correctamente.\n");
        success = false;
    }

    file.close();

    return fm;
}

bool FuzzyParser::parseLine(const std::string& line, const int& nLine)
{
    std::stringstream ss;
    std::string order = "";
    ss << line;
    ss >> order;

    if(order == VAR)
        return parseVar(ss, nLine);
    else if (order == SET)
        return parseSet(ss, nLine);
    else if (order == RULE)
        return parseRule(ss, nLine);
    else if (order == METHOD)
        return parseMethod(ss, nLine);

    fprintf(stderr, "Error: instrucción no reconocida. Linea: %d\n", nLine);
    return false;
}

bool FuzzyParser::parseMethod(std::stringstream& ss, const int& nLine)
{
    bool success = true;
    std::string str = "";
    int nSamples;
    ss >> str;

    if(str == MAX_AV)
        fm->setDefuzzifyMethod(FuzzyModule::max_av);
    else if(str == CENTROID)
    {
        fm->setDefuzzifyMethod(FuzzyModule::centroid);
        ss >> nSamples;
        fm->setNumSamples(nSamples);
    }
    else
    {
        fprintf(stderr, "Error: metodo de defuzzificacion incorrecto.\n");
        success = false;
    }

    return success;
}

bool FuzzyParser::parseVar(std::stringstream& ss, const int& nLine)
{
    std::string str = "";
    ss >> str;

    if(variables[str] == NULL)
    {
        variables[str] = fm->createFLV(str);
        return true;
    }
    else
    {
        fprintf(stderr, "Error: variable repetida. Linea: %d\n", nLine);
        return false;
    }
}

bool FuzzyParser::parseSet(std::stringstream& ss, const int& nLine)
{
    std::string varName;
    std::string setName;
    std::string setType;
    float value1, value2, value3, value4;
    ss >> varName;
    if(variables[varName] == NULL)
    {
        fprintf(stderr, "Error: variable '%s' no declarada. Linea: %d\n",
                        varName.c_str(), nLine);
        return false;
    }
    ss >> setName;
    ss >> setType;
    ss >> value1;
    ss >> value2;
    if(setType == SINGLETON)
    {
        variables[varName]->addSingletonSet(setName, value1, value2);
        return true;
    }
    ss >> value3;
    if(setType == TRIANGLE)
    {
        variables[varName]->addTriangularSet(setName, value1, value2, value3);
        return true;
    }
    if(setType == TRAPEZOID)
    {
        ss >> value4;
        variables[varName]->addTrapezoidSet(setName, value1, value2, value3, value4);
        return true;
    }
    else if(setType == RSHOULDER)
    {
        variables[varName]->addRightShoulderSet(setName, value1, value2, value3);
        return true;
    }
    else if(setType == LSHOULDER)
    {
        variables[varName]->addLeftShoulderSet(setName, value1, value2, value3);
        return true;
    }
    else
    {
        fprintf(stderr, "Error: tipo '%s' no idenfificado. Linea: %d\n",
                        setType.c_str(), nLine);
        return false;
    }
}

bool FuzzyParser::parseRule(std::stringstream& ss, const int& nLine)
{
    bool success = true;
    std::string str;
    std::string consequentVar;
    std::string consequentSet;

    try{
        FuzzyTerm* antecedent = parseExpression(ss, nLine);

        if(antecedent == NULL)
            throw std::exception();

        ss >> str;
        if(str != "THEN")
        {
            fprintf(stderr, "Error: Se esperaba elemento 'THEN'. Linea: %d\n",
                         nLine);
            throw std::exception();
        }
        ss >> consequentVar;
        ss >> consequentSet;

        if(antecedents.find(consequentVar) != antecedents.end())
        {
            fprintf(stderr, "Error: No se puede usar variable '%s' como consecuente de la regla, ya ha sido usada como antecedente. Linea :%d\n",
                        consequentSet.c_str(), nLine);
            throw std::exception();
        }

        consequents.insert(consequentVar);
        FuzzyTerm* consequent = variables[consequentVar]->getSet(consequentSet).clone();
        fm->addRule(antecedent , consequent);
        delete antecedent;
        delete consequent;
    }
    catch (std::exception &ex)
    {
        success = false;
    }

    return success;
}

FuzzyTerm* FuzzyParser::parseExpression(std::stringstream& ss, const int& nLine)
{
    std::string str;
    FuzzyTerm* term1 = NULL;
    FuzzyTerm* term2 = NULL;

    ss >> str;
    try
    {
        if(str == AND)
        {
            // skipping '('
            ss >> str;
            term1 = parseExpression(ss, nLine);
            if(term1 == NULL) throw std::exception();
            // skipping ','
            ss >> str;
            term2 = parseExpression(ss, nLine);
            if(term2 == NULL) throw std::exception();
            // skipping ')'
            ss >> str;
            return new FzAnd(term1, term2);
        }
        else if (str == OR)
        {
            // skipping '('
            ss >> str;
            term1 = parseExpression(ss, nLine);
            if(term1 == NULL) throw std::exception();
            // skipping ','
            ss >> str;
            term2 = parseExpression(ss, nLine);
            if(term2 == NULL) throw std::exception();
            // skipping ')'
            ss >> str;
            return new FzOr(term1, term2);
        }
        else if(str == VERY)
        {
            // skipping '('
            ss >> str;
            FzSet* term = dynamic_cast<FzSet*>(parseExpression(ss, nLine));
            if(term == NULL) throw std::exception();
            // skipping ')'
            ss >> str;
            return new FzVery(term);
        }
        else if(str == FAIRLY)
        {
            // skipping '('
            ss >> str;
            FzSet* term = dynamic_cast<FzSet*>(parseExpression(ss, nLine));
            if(term == NULL) throw std::exception();
            // skipping ')'
            ss >> str;
            return new FzFairly(term);
        }
        else // a variable set
        {
            std::string variableName = str;
            std::string setName;
            ss >> str;
            setName = str;
            antecedents.insert(variableName);
            if(consequents.find(variableName) == consequents.end())
                return variables[variableName]->getSet(setName).clone();
            else
            {
                fprintf(stderr, "Error: No se puede usar variable '%s' como antecedente de la regla, ya ha sido usada como consecuente. Linea :%d\n",
                        variableName.c_str(), nLine);
                return NULL;
            }
        }
    }
    catch (std::exception &ex)
    {
        if(term1 != NULL) delete term1;
        if(term2 != NULL) delete term2;
        return NULL;
    }
}
