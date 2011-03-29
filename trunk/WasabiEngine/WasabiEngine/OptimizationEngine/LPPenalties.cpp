/* 
 * File:   LPPenalties.cpp
 * Author: Roberto
 * 
 * Created on 14 de diciembre de 2010, 17:38
 */

#include "LPPenalties.h"

using namespace WasabiEngine;


bool LPPenalties::canSolve(const LPProblem& problem)
{
    if(!problem.integerProblem && problem.artificialVariables > 0)
        return true;
    else
        return false;
}

LPSolution LPPenalties::solve(const LPProblem& problem)
{
    LPSolverState state = solveBySteps(problem);
    while(state.step());
    return state.getAssociatedSolution();
}

LPSolverState LPPenalties::solveBySteps(const LPProblem& problem)
{
    LPSolverState initialState = simplexSolver.solveBySteps(problem);
    initialState.solver = this;
    return initialState;
}

bool LPPenalties::step(LPSolverState* currentState)
{
    if(!simplexSolver.step(currentState))
        if(currentState->solved && !isSolved(currentState))
            currentState->solved = false;
    
    return currentState->solvable;
}

// private functions

bool LPPenalties::isSolved(const LPSolverState* state) const
{
    for(int i = 0; i < state->base.size(); i++)
    {
        if(state->problem.targetFunction[state->base[i]] == LPProblem::M_CONST
                && state->dBar[i] > 0)
            return false;
    }
    return true;
}