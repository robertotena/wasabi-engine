/* 
 * File:   FuzzySet.cpp
 * Author: Roberto
 * 
 * Created on 16 de noviembre de 2010, 20:00
 */

#include "FuzzySet.h"

using namespace WasabiEngine;

FuzzySet::FuzzySet() {
    curDOM = 0.0;
    representativeValue = 0;
}

FuzzySet::FuzzySet(std::string name, const float& representativeValue){
    curDOM = 0.0;
    this->name = name;
    this->representativeValue = representativeValue;
}

FuzzySet::FuzzySet(const FuzzySet& orig) {
    this->curDOM = orig.curDOM;
    this->representativeValue = orig.representativeValue;
}
