/* 
 * File:   LPSolverState.cpp
 * Author: Roberto
 * 
 * Created on 9 de diciembre de 2010, 17:47
 */

#include "LPSolverState.h"

using namespace WasabiEngine;

LPSolverState::LPSolverState() {
    solved = false;
    solvable = false;
}

LPSolverState::LPSolverState(const LPSolverState& orig) {
    problem = orig.problem;
    solver = orig.solver;
    solved = orig.solved;
    solvable = orig.solvable;
    base = orig.base;
    cb = orig.cb;
    dBar = orig.dBar;
}

LPSolverState::~LPSolverState() {
    solver = NULL;
}

LPSolution LPSolverState::getAssociatedSolution()
{
    LPSolution solution;

    if(solved)
    {
        solution.validSolution = true;
        std::vector<float> solutionCoefficients(problem.getDefaultVariables() , 0);

        // writing the solution vector
        for(unsigned int i = 0; i < base.size(); i++)
        {
            if(base[i] < problem.getDefaultVariables())
                solutionCoefficients[base[i]] = dBar[i];
        }
        // writing the solution value
        solution.value = 0.0;
        for(int i = 0; i < problem.getDefaultVariables(); i++)
            solution.value += problem.targetFunction[i] * solutionCoefficients[i];
        solution.value *= problem.getSign();
        solution.coefficients = solutionCoefficients;
    }
    
    return solution;
}

bool LPSolverState::step()
{
    if(solvable == false || solved == true || solver == NULL)
        return false;
    else
        solver->step(this);
    return solvable;
}

std::string LPSolverState::toString() const
{
    int i, j;
    MatrixXf mBase = getMatrixBase();
    MatrixXf invertedBase = mBase.inverse();
    
    std::string result = "";
    std::string number = "";
    int element;
    std::stringstream ss;
    // base
    result += "--- Base:\n";
    for(i = 0; i < base.size(); i++)
    {
        result += "A";
        ss.clear();
        ss.str("");
        ss << base[i];
        ss >> number;
        result += number;
        result += " ";
    }
    result += "\n";
    for(i = 0; i < mBase.rows(); i++)
    {
        for(j = 0; j < mBase.cols(); j++)
        {
            ss.clear();
            ss.str("");
            element = mBase(i,j);
            ss << element;
            ss >> number;
            result += number;
            result += " ";
        }
        result += "\n";
    }
    
    result += "--- InvertedBase:\n";
    for(i = 0; i < invertedBase.rows(); i++)
    {
        for(j = 0; j < invertedBase.cols(); j++)
        {
            ss.clear();
            ss.str("");
            element = invertedBase(i,j);
            ss << element;
            ss >> number;
            result += number;
            result += " ";
        }
        result += "\n";
    }

    result += "--- cb:\n";
    for(i = 0; i < cb.size(); i++)
    {
        ss.clear();
        ss.str("");
        ss << cb[i];
        ss >> number;
        result += number;
        result += " ";
    }
    result += "\n";
    result += "--- dBar:\n";
    for(i = 0; i < dBar.size(); i++)
    {
        ss.clear();
        ss.str("");
        ss << dBar[i];
        ss >> number;
        result += number;
        result += " ";
    }
    result += "\n";
    result += "--- zj - cj:\n";
    for(i = 0; i < zj_cj.size(); i++)
    {
        ss.clear();
        ss.str("");
        ss << zj_cj[i];
        ss >> number;
        result += number;
        result += " ";
    }
    result += "\n\n";

    return result;
}

// private functions

void LPSolverState::updateBase_Cb(const int& enteringColumn, const int& exitingColumn)
{
    int i = 0;
    while(base[i] != exitingColumn)
        i++;
    base[i] = enteringColumn;
    cb[i] = problem.getTargetFunction()[enteringColumn];
}

void LPSolverState::updateDBar()
{
    VectorXf xB = getMatrixBase().inverse() * problem.getVectorD();
    for(int i = 0; i < xB.rows(); i++)
        dBar[i] = xB[i];
}

void LPSolverState::updateZj_cj()
{
    std::vector<float> updatedZj_cj;
    std::vector<int> targetFunction = problem.getTargetFunction();
    MatrixXf a = problem.getMatrixA();
    VectorXf prod = getVectorCb().transpose() * getMatrixBase().inverse();
    float zj;
    // zj = cb*inv(B)*aj
    for(int i = 0; i < a.cols(); i++ )
    {
        zj = (prod.transpose() * a.col(i))(0);
        zj = adjustToInt(zj);
        updatedZj_cj.push_back(zj - targetFunction[i]);
    }
    zj_cj = updatedZj_cj;
}

// private methods

// if the value is close enough to a integer, returns the closest integer found
float LPSolverState::adjustToInt(const float& number)
{
    if(fabs(fabs(number) - (int)fabs(number)) <= 0.0001)
         return (int)number;
    if(fabs(fabs(number) - (((int)fabs(number))+1)) <= 0.0001)
    {
        if(number > 0)
            return (int)number+1;
        else
            return (int)number-1;
    }
    return number;
}

VectorXf LPSolverState::getVectorCb() const
{
    VectorXf result = VectorXf::Zero(cb.size());
    
    for(unsigned int i = 0; i < cb.size(); i++)
        result(i) = cb[i];

    return result;
}

MatrixXf LPSolverState::getMatrixBase() const
{
    MatrixXf result = MatrixXf::Zero(base.size(), base.size());
    MatrixXf a = problem.getMatrixA();

    for(unsigned int i = 0; i < base.size(); i++)
        result.col(i) = a.col(base[i]);
    
    return result;
}
