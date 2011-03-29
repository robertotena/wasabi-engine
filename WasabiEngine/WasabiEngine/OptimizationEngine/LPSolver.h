/* 
 * File:   LPSolver.h
 * Author: Roberto
 *
 * Created on 9 de diciembre de 2010, 17:45
 */

#ifndef LPSOLVER_H
#define	LPSOLVER_H

#include "LPProblem.h"
#include "LPSolution.h"
#include "LPSolverState.h"
#include "LPAlgorithm.h"
#include "LPSimplex.h"
#include "LPPenalties.h"
#include <vector>


namespace WasabiEngine {

/**
 *  Main class to solve linear programming problems.
 *
 *  This is the class you have to use to start solving a linear programming problem.
 * 
 *     It is able to solve by steps non integer problems, and to give a final solution to
 *  any kind of LP problem.
 */
class LPSolver {
private:
    std::vector<LPAlgorithm*> solvers;
public:
    LPSolver();
    ~LPSolver();
    /**
    * Solves the specified LP problem.
    * @param problem The problem to solve.
    * @return The solution to the LP problem.
    */
    LPSolution solve(LPProblem problem);
    /**
    * Solves the specified LP problem.
    * @param problem The problem to solve.
    * @return The first solver state
    */
    LPSolverState solveBySteps(LPProblem problem);
};

}

#endif	/* LPSOLVER_H */

