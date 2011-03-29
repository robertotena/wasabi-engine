/* 
 * File:   LPSimplex.cpp
 * Author: Roberto
 * 
 * Created on 9 de diciembre de 2010, 19:36
 */

#include "LPSimplex.h"
#include <iostream>
using namespace WasabiEngine;

bool LPSimplex::canSolve(const LPProblem& problem)
{
    if(!problem.integerProblem && problem.artificialVariables == 0)
        return true;
    else
        return false;
}

LPSolution LPSimplex::solve(const LPProblem& problem)
{
    LPSolverState state = solveBySteps(problem);
    while(state.step());
    return state.getAssociatedSolution();
}

LPSolverState LPSimplex::solveBySteps(const LPProblem& problem)
{
    LPSolverState initialState;

    initialState.problem = problem;
    initialState.solver = this;
    MatrixXf a = problem.getMatrixA();
    if(a.rows() <= a.cols())
    {
        int i;
        std::vector<int> targetFunction = problem.getTargetFunction();
        std::vector<float> dBar;
        std::vector<int> cb;
        // writing base
        initialState.base = problem.initialBase;

        // writing dBar
        MatrixXf invertedBase = initialState.getMatrixBase().inverse();
        VectorXf d = problem.getVectorD();
        VectorXf xB = invertedBase * d;
        for(i = 0; i < xB.rows(); i++)
            dBar.push_back(xB[i]);
        initialState.dBar = dBar;

        //writing cb
        for(i = 0; i < initialState.base.size(); i++)
            cb.push_back(targetFunction[initialState.base[i]]);
        initialState.cb = cb;

        // writing zj-cj    
        initialState.updateZj_cj();
        initialState.solvable = true;
        initialState.solved = false;
    }

    return initialState;
}

bool LPSimplex::step(LPSolverState* currentState)
{
    if(!currentState->solvable)
        return false;
    if(isSolved(currentState))
    {
        currentState->solvable = false;
        currentState->solved = true;
    }
    else
    {
        int enteringColumn = getEnteringColumn(currentState);
        VectorXf yk = calculateVectorYk(currentState, enteringColumn);
        if(!isBounded(yk))
            currentState->solvable = false;
        else
        {
            int exitingColumn = getExitingColumn(currentState, yk);
            currentState->updateBase_Cb(enteringColumn, exitingColumn);
            currentState->updateDBar();
            currentState->updateZj_cj();
        }
    }

    return currentState->solvable;
}

// Private functions

bool LPSimplex::isSolved(const LPSolverState* state) const
{
    for(int i = 0; i < state->zj_cj.size(); i++)
    {
        if(state->zj_cj[i] > 0)
            return false;
    }
    return true;
}

int LPSimplex::getEnteringColumn(const LPSolverState* state) const
{
    int column = 0;
    float maxValue = -1;
    for(int i = 0; i < state->zj_cj.size(); i++)
    {
        if(state->zj_cj[i] > maxValue)
        {
            column = i;
            maxValue = state->zj_cj[i];
        }
    }

    return column;
}

VectorXf LPSimplex::calculateVectorYk(const LPSolverState* state, int enteringColumn) const
{
    MatrixXf b = state->getMatrixBase();
    MatrixXf a = state->problem.getMatrixA();
    VectorXf col = a.col(enteringColumn);
    return b.inverse() * col;
}

bool LPSimplex::isBounded(const VectorXf& yk) const
{
    for(int i = 0; i < yk.size(); i++)
        if(yk[i] > 0)
            return true;
    return false;
}

int LPSimplex::getExitingColumn(const LPSolverState* state, VectorXf yk) const
{
    int column = 0;
    float minValue = INT_MAX;
    float value;

    for(int i = 0; i < yk.size(); i++)
    {
        if(yk[i] > 0)
        {
            value = state->dBar[i]/yk[i];
            if(value < minValue)
            {
                column = state->base[i];
                minValue = value;
            }
        }
    }

    return column;
}
