/* 
 * File:   LPBranchBound.cpp
 * Author: Roberto
 * 
 * Created on 15 de diciembre de 2010, 2:09
 */

#include "LPBranchBound.h"
#include "LPPenalties.h"

using namespace WasabiEngine;


bool LPBranchBound::canSolve(const LPProblem& problem)
{
    return problem.integerProblem;
}

LPSolution LPBranchBound::solve(const LPProblem& problem)
{
    std::vector<LPProblem> problemQueue;
    LPSolution bestSolution;
    LPSolution solution;
    int bestValue;
    bool finished = false;
    problemQueue.push_back(problem);
    problemQueue[0].integerProblem = false;

    solution = penaltiesSolver.solve(problemQueue[0]);
    bestValue = solution.getValue();
    if(solution.isValidSolution())
    {
        if(solution.isPureInteger())
        {
            bestSolution = solution;
            finished = true;
        }
        else
            ramify(problemQueue, solution);
    }
    else
        finished = true;

    while(!finished && problemQueue.size() > 0)
    {
        solution = penaltiesSolver.solve(problemQueue[0]);
        if(solution.isValidSolution())
        {
            if(solution.isPureInteger())
            {
                if(solution.getValue() == bestValue)
                {
                    finished = true;
                    bestSolution = solution;
                }
                else if(betterSolution(problemQueue[0].problemType, solution, bestSolution))
                {
                    bestSolution = solution;
                }
                problemQueue.erase(problemQueue.begin());
            }
            else
            {
                ramify(problemQueue, solution);
            }
        }
        else
        {
            problemQueue.erase(problemQueue.begin());
        }
    }
    
    return bestSolution;
}

LPSolverState LPBranchBound::solveBySteps(const LPProblem& problem)
{
    return LPSolverState();
}

bool LPBranchBound::step(LPSolverState* currentState)
{
    return false;
}

// private functions

void LPBranchBound::ramify(std::vector<LPProblem>& problemQueue, LPSolution& solution)
{
    LPProblem problemLess = problemQueue[0];
    LPProblem problemGreater = problemQueue[0];
    int problemSize = problemQueue[0].getTargetFunction().size();
    int selectedVariable;
    int i;
    std::vector<float> solutionCoeff = solution.getCoefficients();

    // select the new variable to ramify from
    selectedVariable = -1;
    for(i = 0; i < solutionCoeff.size() && selectedVariable < 0; i++)
        if(!isInteger(solutionCoeff[i]))
            selectedVariable = i;

    // add the new restrictions to the problem
    std::vector<int> restrictionCoeff;
    for(i = 0; i < problemSize; i++)
        restrictionCoeff.push_back(0);
    restrictionCoeff[selectedVariable] = 1;

    LPRestriction restrictionLess(
            restrictionCoeff,
            LPRestriction::lessEqual,
            (int)solutionCoeff[selectedVariable]);
    LPRestriction restrictionGreater(
            restrictionCoeff,
            LPRestriction::greaterEqual,
            (int)solutionCoeff[selectedVariable] + 1);

    problemLess.addRestriction(restrictionLess);
    problemLess.standardizeRestriction(problemLess.restrictions.size() - 1);
    problemGreater.addRestriction(restrictionGreater);
    problemGreater.standardizeRestriction(problemGreater.restrictions.size() - 1);

    // add the new problems to the queue
    problemQueue.erase(problemQueue.begin());
    problemQueue.insert(problemQueue.begin(), problemGreater);
    problemQueue.insert(problemQueue.begin(), problemLess);
}

bool LPBranchBound::betterSolution(
    const LPProblem::LPProblemType& type,
    const LPSolution& sol,
    const LPSolution& bestSol)
{
    if(type == LPProblem::max)
        return sol.getValue() > bestSol.getValue();
    else
        return sol.getValue() < bestSol.getValue();
}

bool LPBranchBound::isInteger(const float& number)
{
    if(fabs(number - (int)number) <= 0.0001 ||
             fabs(number - (((int)number)+1)) <= 0.0001)
    {
        return true;
    }
    return false;
}
