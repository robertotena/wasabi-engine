/* 
 * File:   FzOr.cpp
 * Author: Roberto
 * 
 * Created on 24 de noviembre de 2010, 0:24
 */

#include "FzOr.h"

using namespace WasabiEngine;

FzOr::FzOr(FuzzyTerm* op1, FuzzyTerm* op2)
{
    numOperands = 2;
    operands[0] = op1->clone();
    operands[1] = op2->clone();
}

FzOr::FzOr(FuzzyTerm& op1, FuzzyTerm& op2)
{
    numOperands = 2;
    operands[0] = op1.clone();
    operands[1] = op2.clone();
}

FzOr::FzOr(FuzzyTerm& op1, FuzzyTerm& op2, FuzzyTerm& op3)
{
    numOperands = 3;
    operands[0] = op1.clone();
    operands[1] = op2.clone();
    operands[2] = op3.clone();
}

FzOr::FzOr(FuzzyTerm& op1, FuzzyTerm& op2, FuzzyTerm& op3, FuzzyTerm& op4)
{
    numOperands = 4;
    operands[0] = op1.clone();
    operands[1] = op2.clone();
    operands[2] = op3.clone();
    operands[3] = op4.clone();
}


FzOr::FzOr(const FzOr& orig)
{
    numOperands = orig.numOperands;
    for(int i = 0; i < numOperands; i++)
        operands[i] = orig.operands[i]->clone();
}

FzOr::~FzOr()
{
    for(int i = 0; i < numOperands; i++)
        delete operands[i];
}

float FzOr::getDOM() const
{
    float result = 0.0;

    for(int i = 0; i < numOperands; i++)
        if(operands[i]->getDOM() > result)
            result = operands[i]->getDOM();

    return result;
}

void FzOr::clearDOM()
{
    for(int i = 0; i < numOperands; i++)
        operands[i]->clearDOM();
}

void FzOr::ORWithDOM(const float& value)
{
    for(int i = 0; i < numOperands; i++)
        operands[i]->ORWithDOM(value);
}

std::string FzOr::toString() const
{
    std::string result = "( ";

    for(int i = 0; i < numOperands; i++)
    {
        result += operands[i]->toString() + " ";
        if(i < numOperands - 1)
            result += "OR ";
    }
    result += ")";

    return result;
}
