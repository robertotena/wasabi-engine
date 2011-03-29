/* 
 * File:   FSTrapezoid.cpp
 * Author: Roberto
 * 
 * Created on 18 de diciembre de 2010, 13:58
 */

#include "FSTrapezoid.h"

using namespace WasabiEngine;

FSTrapezoid::FSTrapezoid(const FSTrapezoid& orig) {
    name = orig.name;
    representativeValue = orig.representativeValue;
    curDOM = orig.curDOM;
    leftEnd = orig.leftEnd;
    midLeft = orig.midLeft;
    midRight = orig.midRight;
    rightEnd = orig.rightEnd;
}

float FSTrapezoid::calculateDOM(float value){
    if(value >= midLeft && value <= midRight)
        return 1.0;
    if(value > leftEnd && value < midLeft)
        return (value - leftEnd) / (midLeft - leftEnd);
    if(value > midRight && value < rightEnd)
        return (rightEnd - value) / (rightEnd - midRight);
    return 0.0;
}