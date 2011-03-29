/* 
 * File:   LPSolution.cpp
 * Author: Roberto
 * 
 * Created on 9 de diciembre de 2010, 18:24
 */

#include "LPSolution.h"

using namespace WasabiEngine;

LPSolution::LPSolution() {
    validSolution = false;
    value = 0.0;
}

LPSolution::LPSolution(const LPSolution& orig) {
    validSolution = orig.validSolution;
    coefficients = orig.coefficients;
    value = orig.value;
}

bool LPSolution::isPureInteger() const
{
    if(!validSolution)
        return false;
    for(unsigned int i = 0; i < coefficients.size(); i++)
        if(!isInteger(coefficients[i]))
            return false;
    return true;
}

std::string LPSolution::toString() const
{
    std::string result = "";
    std::stringstream ss;
    std::string number;

    result += "Coefficients: ";
    for(unsigned int i = 0; i < coefficients.size(); i++)
    {
        ss.clear();
        ss.str("");
        ss << coefficients[i];
        ss >> number;
        result += number;
        result += " ";
    }
    result += "\n";

    result += "Result: ";
    ss.clear();
    ss.str("");
    ss << value;
    ss >> number;
    result += number;
    result += "\n";

    return result;
}


// private methods

bool LPSolution::isInteger(const float& number) const
{
    if(fabs(number - (int)number) <= 0.0001 ||
             fabs(number - (((int)number)+1)) <= 0.0001)
    {
        return true;
    }
    return false;
}
