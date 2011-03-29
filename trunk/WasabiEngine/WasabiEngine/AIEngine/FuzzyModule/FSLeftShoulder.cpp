/* 
 * File:   FSLeftShoulder.cpp
 * Author: Roberto
 * 
 * Created on 17 de noviembre de 2010, 2:36
 */

#include "FSLeftShoulder.h"

using namespace WasabiEngine;

FSLeftShoulder::FSLeftShoulder(const FSLeftShoulder& orig) {
    name = orig.name;
    curDOM = orig.curDOM;
    representativeValue = orig.representativeValue;
    leftEnd = orig.leftEnd;
    midPoint = orig.midPoint;
    rightEnd = orig.rightEnd;
}

float FSLeftShoulder::calculateDOM(float value){
    if(value >= leftEnd && value <= midPoint)
        return 1.0;
    if(value > midPoint && value < rightEnd)
        return (rightEnd - value) / (rightEnd - midPoint);
    return 0.0;
}
