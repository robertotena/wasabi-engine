/* 
 * File:   LPSolver.cpp
 * Author: Roberto
 * 
 * Created on 9 de diciembre de 2010, 17:45
 */

#include "LPSolver.h"
#include "LPBranchBound.h"

using namespace WasabiEngine;

LPSolver::LPSolver() {
    solvers.push_back(new LPSimplex());
    solvers.push_back(new LPPenalties());
    solvers.push_back(new LPBranchBound());
}

LPSolver::~LPSolver() {
    std::vector<LPAlgorithm*>::iterator solver;
    for (solver = solvers.begin(); solver != solvers.end(); solver++)
        delete *solver;
}

LPSolution LPSolver::solve(LPProblem problem)
{
    problem.standardize();
    std::vector<LPAlgorithm*>::iterator solver;
    for (solver = solvers.begin(); solver != solvers.end(); solver++)
        if((*solver)->canSolve(problem))
            return (*solver)->solve(problem);
    return LPSolution();
}

LPSolverState LPSolver::solveBySteps(LPProblem problem)
{
    problem.standardize();
    std::vector<LPAlgorithm*>::iterator solver;
    for (solver = solvers.begin(); solver != solvers.end(); solver++)
        if((*solver)->canSolve(problem))
            return (*solver)->solveBySteps(problem);
    return LPSolverState();
}
