/* 
 * File:   FuzzyRule.cpp
 * Author: Roberto
 * 
 * Created on 23 de noviembre de 2010, 19:24
 */

#include "FuzzyRule.h"

using namespace WasabiEngine;

FuzzyRule::FuzzyRule(const FuzzyTerm* ant, const FuzzyTerm* cons)
{
    antecedent = ant->clone();
    consequent = cons->clone();
}

FuzzyRule::FuzzyRule(const FuzzyTerm& ant, const FuzzyTerm& cons)
{
    antecedent = ant.clone();
    consequent = cons.clone();
}

FuzzyRule::FuzzyRule(const FuzzyRule& orig) {
    antecedent = orig.antecedent->clone();
    consequent = orig.consequent->clone();
}

FuzzyRule::~FuzzyRule() {
    delete antecedent;
    delete consequent;
}
