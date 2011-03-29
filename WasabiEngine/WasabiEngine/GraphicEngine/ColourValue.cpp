/* 
 * File:   ColourValue.cpp
 * Author: Fran_2
 * 
 * Created on 21 de febrero de 2011, 18:54
 */

#include "ColourValue.h"

using namespace WasabiEngine;

const ColourValue ColourValue::RED(1,0,0,1);
const ColourValue ColourValue::GREEN(0,1,0,1);
const ColourValue ColourValue::BLUE(0,0,1,1);
const ColourValue ColourValue::BLACK(0,0,0,1);
const ColourValue ColourValue::GREY(0.5,0.5,0.5,1);
const ColourValue ColourValue::WHITE(1,1,1,1);

ColourValue::ColourValue(const float& red, const float& green, const float& blue, const float& alpha)
{
    this->red = red;
    this->green = green;
    this->blue = blue;
    this->alpha = alpha;
}

ColourValue::ColourValue(const ColourValue& orig)
{
    red = orig.red;
    green = orig.green;
    blue = orig.blue;
    alpha = orig.alpha;
}
