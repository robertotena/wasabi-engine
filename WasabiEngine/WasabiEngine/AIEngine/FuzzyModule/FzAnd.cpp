/* 
 * File:   FzAnd.cpp
 * Author: Roberto
 * 
 * Created on 23 de noviembre de 2010, 20:38
 */

#include "FzAnd.h"

using namespace WasabiEngine;

FzAnd::FzAnd(FuzzyTerm* op1, FuzzyTerm* op2)
{
    numOperands = 2;
    operands[0] = op1->clone();
    operands[1] = op2->clone();
}

FzAnd::FzAnd(FuzzyTerm& op1, FuzzyTerm& op2)
{
    numOperands = 2;
    operands[0] = op1.clone();
    operands[1] = op2.clone();
}

FzAnd::FzAnd(FuzzyTerm& op1, FuzzyTerm& op2, FuzzyTerm& op3)
{
    numOperands = 3;
    operands[0] = op1.clone();
    operands[1] = op2.clone();
    operands[2] = op3.clone();
}

FzAnd::FzAnd(FuzzyTerm& op1, FuzzyTerm& op2, FuzzyTerm& op3, FuzzyTerm& op4)
{
    numOperands = 4;
    operands[0] = op1.clone();
    operands[1] = op2.clone();
    operands[2] = op3.clone();
    operands[3] = op4.clone();
}


FzAnd::FzAnd(const FzAnd& orig)
{
    numOperands = orig.numOperands;
    for(int i = 0; i < numOperands; i++)
        operands[i] = orig.operands[i]->clone();
}

FzAnd::~FzAnd()
{
    for(int i = 0; i < numOperands; i++)
        delete operands[i];
}

float FzAnd::getDOM() const
{
    float result = 1.0;
    
    for(int i = 0; i < numOperands; i++)
        if(operands[i]->getDOM() < result)
            result = operands[i]->getDOM();

    return result;
}

void FzAnd::clearDOM()
{
    for(int i = 0; i < numOperands; i++)
        operands[i]->clearDOM();
}

void FzAnd::ORWithDOM(const float& value)
{
    for(int i = 0; i < numOperands; i++)
        operands[i]->ORWithDOM(value);
}

std::string FzAnd::toString() const
{
    std::string result = "( ";

    for(int i = 0; i < numOperands; i++)
    {
        result += operands[i]->toString() + " ";
        if(i < numOperands -1)
            result += "AND ";
    }
    result += ")";

    return result;
}
