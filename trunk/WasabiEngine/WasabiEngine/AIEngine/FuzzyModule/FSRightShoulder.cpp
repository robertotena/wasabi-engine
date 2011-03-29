/* 
 * File:   FSRightShoulder.cpp
 * Author: Roberto
 * 
 * Created on 17 de noviembre de 2010, 2:26
 */

#include "FSRightShoulder.h"

using namespace WasabiEngine;

FSRightShoulder::FSRightShoulder(const FSRightShoulder& orig) {
    name = orig.name;
    curDOM = orig.curDOM;
    representativeValue = orig.representativeValue;
    leftEnd = orig.leftEnd;
    midPoint = orig.midPoint;
    rightEnd = orig.rightEnd;
}

float FSRightShoulder::calculateDOM(float value){
    if(value >= midPoint && value <= rightEnd)
        return 1.0;
    if(value > leftEnd && value < midPoint)
        return (value - leftEnd) / (midPoint - leftEnd);
    return 0.0;
}
