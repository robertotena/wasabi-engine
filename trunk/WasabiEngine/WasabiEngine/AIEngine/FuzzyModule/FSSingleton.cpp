/* 
 * File:   FSSingleton.cpp
 * Author: Roberto
 * 
 * Created on 17 de noviembre de 2010, 2:49
 */

#include "FSSingleton.h"

using namespace WasabiEngine;

FSSingleton::FSSingleton(const FSSingleton& orig) {
    name = orig.name;
    curDOM = orig.curDOM;
    representativeValue = orig.representativeValue;
    leftEnd = orig.leftEnd;
    rightEnd = orig.rightEnd;
}

float FSSingleton::calculateDOM(float value){
    if(value >= leftEnd && value <= rightEnd)
        return 1.0;
    return 0.0;
}
