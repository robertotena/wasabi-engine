/* 
 * File:   FuzzyModule.cpp
 * Author: Roberto
 * 
 * Created on 22 de noviembre de 2010, 1:49
 */

#include "FuzzyModule.h"

using namespace WasabiEngine;

FuzzyModule::~FuzzyModule()
{
    // deleting the rules
    std::vector<FuzzyRule*>::iterator rule;
    for (rule = rules.begin(); rule != rules.end(); rule++)
        delete *rule;
    // deleting the variables
    std::map<std::string, FuzzyVariable*>::iterator variable;
    for (variable = variables.begin(); variable != variables.end(); variable++)
        delete variable->second;

}

void FuzzyModule::runRules()
{
    std::vector<FuzzyRule*>::iterator rule;
    for (rule = rules.begin(); rule != rules.end(); rule++)
        (*rule)->clearConsequentConfidence();
    for (rule = rules.begin(); rule != rules.end(); rule++)
        (*rule)->calculate();
}

FuzzyVariable* FuzzyModule::createFLV(std::string name)
{
    variables[name] = new FuzzyVariable(name);
    return variables[name];
}

FuzzyRule* FuzzyModule::addRule(const FuzzyTerm* antecendent, const FuzzyTerm* consequent)
{
    FuzzyRule* rule = new FuzzyRule(antecendent, consequent);
    rules.push_back(rule);
    return rule;
}

void FuzzyModule::addRule(const FuzzyTerm& antecendent, const FuzzyTerm& consequent)
{
    rules.push_back(new FuzzyRule(antecendent, consequent));
}

void FuzzyModule::fuzzify(const std::string& variable, const float& value)
{
    variables[variable]->fuzzify(value);
}

float FuzzyModule::deffuzify(const std::string& variable)
{
    variables[variable]->clearDOMs();
    runRules();
    if(method == max_av)
        return variables[variable]->deffuzifyMaxAv();
    if(method == centroid)
        return variables[variable]->deffuzifyCentroid(numSamples);
    return 0.0;
}
