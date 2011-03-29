/* 
 * File:   FSTriangle.cpp
 * Author: Roberto
 * 
 * Created on 16 de noviembre de 2010, 20:29
 */

#include "FuzzySet.h"
#include "FSTriangle.h"

using namespace WasabiEngine;

FSTriangle::FSTriangle(const FSTriangle& orig) {
    name = orig.name;
    curDOM = orig.curDOM;
    representativeValue = orig.representativeValue;
    leftEnd = orig.leftEnd;
    midPoint = orig.midPoint;
    rightEnd = orig.rightEnd;
}

float FSTriangle::calculateDOM(float value){
    if(value == midPoint)
        return 1.0;
    if(value > leftEnd && value < rightEnd)
    {
        if(value < midPoint)
            return (value - leftEnd) / (midPoint - leftEnd);
        else
            return (rightEnd - value) / (rightEnd - midPoint);
    }
    return 0.0;
}
