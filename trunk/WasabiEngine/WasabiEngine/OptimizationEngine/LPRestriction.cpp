/* 
 * File:   LPRestriction.cpp
 * Author: Roberto
 * 
 * Created on 8 de diciembre de 2010, 22:52
 */

#include "LPRestriction.h"

using namespace WasabiEngine;

LPRestriction::LPRestriction(const std::vector<int>& coef,
        const LPRestrictionEqualityType& type, const int& d) {
    coefficients = coef;
    equalityType = type;
    this->d = d;
}

LPRestriction::LPRestriction(const LPRestriction& orig) {
    coefficients = orig.coefficients;
    equalityType = orig.equalityType;
    d = orig.d;
}

int LPRestriction::standardize()
{
    int slackVariable = 0;

    // Step 1: add slack variable (if needed)
    if(equalityType == lessEqual)
    {
        slackVariable = 1;
        coefficients.push_back(slackVariable);
    }
    else if(equalityType == greaterEqual)
    {
        slackVariable = -1;
        coefficients.push_back(slackVariable);
    }

    // Step 2: multiply restriction (and so the slack variable) by -1 if d < 0
    if(d < 0)
    {
        for(int i = 0; i < coefficients.size(); i++)
            coefficients[i] *= -1;
        d *= -1;
        slackVariable *= -1;
    }

    // Step 3: add artificial variable if slack variable <= 0
    if(slackVariable <= 0)
        coefficients.push_back(1);

    equalityType = equal;
    
    return slackVariable;
}

std::string LPRestriction::toString() const
{
    std::string result = "";
    std::string number = "";
    std::stringstream ss;

    for(int i = 0; i < coefficients.size(); i++)
    {
        ss.clear();
        ss.str("");
        ss << coefficients[i];
        ss >> number;
        result += number + " ";
    }
    if(equalityType == equal)
        result += "= ";
    else if(equalityType == lessEqual)
        result += "<= ";
    else
        result += ">= ";
    ss.clear();
    ss.str("");
    ss << d;
    ss >> number;
    result +=  number + "\n";
    
    return result;
}
