/* 
 * File:   LPProblem.cpp
 * Author: Roberto
 * 
 * Created on 8 de diciembre de 2010, 22:27
 */

#include "LPProblem.h"

using namespace WasabiEngine;

const int LPProblem::M_CONST = 10001;

LPProblem::LPProblem()
{
    problemType = min;
    sign = 1;
    integerProblem = false;
    defaultVariables = 0;
    slackVariables = 0;
    artificialVariables = 0;
}

LPProblem::LPProblem(const LPProblemType& type,
        const bool& isIntegerProblem, const std::vector<int>& targetFunction)
{
    sign = 1;
    this->problemType = type;
    this->integerProblem = isIntegerProblem;
    this->targetFunction = targetFunction;
    defaultVariables = targetFunction.size();
    slackVariables = 0;
    artificialVariables = 0;
}

LPProblem::LPProblem(const LPProblem& orig)
{
    problemType = orig.problemType;
    sign = orig.sign;
    integerProblem = orig.integerProblem;
    targetFunction = orig.targetFunction;
    restrictions = orig.restrictions;
    initialBase = orig.initialBase;
    defaultVariables = orig.defaultVariables;
    slackVariables = orig.slackVariables;
    artificialVariables = orig.artificialVariables;
}

void LPProblem::standardize()
{
    if(problemType == max)
    {
        std::vector<int>::iterator coef;

        sign = -1;
        for (coef = targetFunction.begin(); coef != targetFunction.end(); coef++)
            (*coef) *= -1;
    }
    else
        sign = 1;
    // standarizing all restrictions
    for (int i = 0; i < restrictions.size(); i++)
        standardizeRestriction(i);
}

std::string LPProblem::toString() const
{
    int i;
    std::string result = "";
    std::string number = "";
    std::stringstream ss;

    if(problemType == max)
        result += "Max ";
    else
        result +=  "Min ";
    for( i = 0; i < targetFunction.size(); i++)
    {
        ss.clear();
        ss.str("");
        ss << targetFunction[i];
        ss >> number;
        result += number + " ";
    }
    result += "\n";
    for(i = 0; i < restrictions.size(); i++)
        result += restrictions[i].toString();

    return result;
}

// private methods

void LPProblem::standardizeRestriction(const int& i)
{
    int slackValue;
    slackValue = restrictions[i].standardize();

    // add the zero value of the column to the other rows
    for(int j = i + 1; j != i; j++)
    {
        if(j == restrictions.size())
            j = -1;
        else
        {
            restrictions[j].addCoefficient(0);
            // we add two new columns, for the slack and artificial value
            if(slackValue < 0)
                restrictions[j].addCoefficient(0);
        }
    }
    if(slackValue > 0)
    {
        initialBase.push_back(targetFunction.size());
        targetFunction.push_back(0);
        slackVariables++;
    }
    else if(slackValue < 0)
    {
        initialBase.push_back(targetFunction.size()+1);
        targetFunction.push_back(0);
        targetFunction.push_back(M_CONST);
        slackVariables++;
        artificialVariables++;
    }
    else
    {
        initialBase.push_back(targetFunction.size());
        targetFunction.push_back(M_CONST);
        artificialVariables++;
    }
}

MatrixXf LPProblem::getMatrixA() const
{
    if(restrictions.size() <= 0)
        return MatrixXf::Zero(0,0);

    int rows = restrictions.size();
    int columns = targetFunction.size();
    MatrixXf result = MatrixXf::Zero(rows, columns);
    std::vector<int> coefficients;
    int i, j;
    for (i = 0; i < restrictions.size(); i++)
    {
        coefficients = restrictions[i].getCoefficients();
        for (j = 0; j < coefficients.size(); j++)
            result(i,j) = coefficients[j];
    }

    return result;
}

VectorXf LPProblem::getVectorD() const
{
    if(restrictions.size() <= 0)
        return VectorXf::Zero(0);

    int rows = restrictions.size();
    VectorXf result = VectorXf::Zero(rows);
    for (int i = 0; i < restrictions.size(); i++)
        result(i) = restrictions[i].getD();

    return result;
}

