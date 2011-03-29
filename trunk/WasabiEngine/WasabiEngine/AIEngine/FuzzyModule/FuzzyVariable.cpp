/* 
 * File:   FuzzyVariable.cpp
 * Author: Roberto
 * 
 * Created on 17 de noviembre de 2010, 16:27
 */

#include "FuzzyVariable.h"

using namespace WasabiEngine;

FuzzyVariable::FuzzyVariable(const std::string& name) {
    this->name = name;
    maxRange = 0;
    minRange = 0;
}

FuzzyVariable::~FuzzyVariable()
{
    std::map<std::string, FuzzySet*>::iterator it;
    for (it = memberSets.begin(); it != memberSets.end(); it++)
        delete it->second;
}

void FuzzyVariable::adjustRange(float minBound, float maxBound)
{
    if(minBound < minRange)
        minRange = minBound;
    if(maxBound > maxRange)
        maxRange = maxBound;
}

FzSet FuzzyVariable::addTriangularSet(std::string name, float leftEnd, float midPoint, float rightEnd)
{
    FuzzySet* set = new FSTriangle(this->name + " " + name, leftEnd, midPoint, rightEnd);
    memberSets[name] = set;
    adjustRange(leftEnd, rightEnd);
    return FzSet(set);
}

FzSet FuzzyVariable::addTrapezoidSet(std::string name, float leftEnd, float midLeft, float midRight, float rightEnd)
{
    FuzzySet* set = new FSTrapezoid(this->name + " " + name, leftEnd, midLeft, midRight, rightEnd);
    memberSets[name] = set;
    adjustRange(leftEnd, rightEnd);
    return FzSet(set);
}

FzSet FuzzyVariable::addRightShoulderSet(std::string name, float leftEnd, float midPoint, float rightEnd)
{
    FuzzySet* set = new FSRightShoulder(this->name + " " + name, leftEnd, midPoint, rightEnd);
    memberSets[name] = set;
    adjustRange(leftEnd, rightEnd);
    return FzSet(set);
}

FzSet FuzzyVariable::addLeftShoulderSet(std::string name, float leftEnd, float midPoint, float rightEnd)
{
    FuzzySet* set = new FSLeftShoulder(this->name + " " + name, leftEnd, midPoint, rightEnd);
    memberSets[name] = set;
    adjustRange(leftEnd, rightEnd);
    return FzSet(set);
}

FzSet FuzzyVariable::addSingletonSet(std::string name, float leftEnd, float rightEnd)
{
    FuzzySet* set = new FSSingleton(this->name + " " + name, leftEnd, rightEnd);
    memberSets[name] = set;
    adjustRange(leftEnd, rightEnd);
    return FzSet(set);
}

FzSet FuzzyVariable::getSet(std::string name)
{
    return FzSet(memberSets[name]);
}

std::vector<FzSet> FuzzyVariable::getSets() const
{
    std::vector<FzSet> sets;
    std::map<std::string, FuzzySet*>::const_iterator it;

    for(it = memberSets.begin(); it != memberSets.end(); it++)
        sets.push_back(FzSet((*it).second));

    return sets;
}

void FuzzyVariable::clearDOMs()
{
    std::map<std::string, FuzzySet*>::iterator it;
    for (it = memberSets.begin(); it != memberSets.end(); it++)
        (*it).second->clearDOM();
}

void FuzzyVariable::fuzzify(float value)
{
    std::map<std::string, FuzzySet*>::const_iterator it;
    for (it = memberSets.begin(); it != memberSets.end(); it++)
        (*it).second->setDOM((*it).second->calculateDOM(value));
}

float FuzzyVariable::deffuzifyMaxAv() const
{
    float confidenceSum = 0.0;
    float weightedRepresentativeSum = 0.0;

    std::map<std::string, FuzzySet*>::const_iterator it;
    for (it = memberSets.begin(); it != memberSets.end(); it++)
    {
        weightedRepresentativeSum += (*it).second->getDOM() * (*it).second->getRepresentativeValue();
        confidenceSum += (*it).second->getDOM();
    }

    return weightedRepresentativeSum / confidenceSum;
}

float FuzzyVariable::deffuzifyCentroid(int numSamples) const
{
    // we do not consider possible negative ranges, just minimum ranges >= 0
    float sampleSize = (maxRange - minRange) / (float)numSamples;
    float weightedDomSum = 0.0;
    float domSum = 0.0;

    // loop variables
    std::map<std::string, FuzzySet*>::const_iterator it;
    float partialDomSum;
    float sampleValue;
    for(int i = 1; i <= numSamples; i++)
    {
        partialDomSum = 0.0;
        sampleValue = i * sampleSize;
        for (it = memberSets.begin(); it != memberSets.end(); it++)
            partialDomSum += WasabiMath::min(it->second->getDOM(), it->second->calculateDOM(sampleValue));
        weightedDomSum += partialDomSum * sampleValue;
        domSum += partialDomSum;
    }

    return weightedDomSum / domSum;
}
