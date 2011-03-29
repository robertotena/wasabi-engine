/* 
 * File:   LPSimplex.h
 * Author: Roberto
 *
 * Created on 9 de diciembre de 2010, 19:36
 */

#ifndef LPSIMPLEX_H
#define	LPSIMPLEX_H

#include <climits>
#include "LPAlgorithm.h"

namespace WasabiEngine {

/**
*  Solves a linear programming problem using the standard's Simplex Algorithm.
*
*  LPSimplex makes use of the standard's Simplex Algorithm to solve a given
* LPProblem. It is able to know if it can solve the problem, and solve it
* by steps.
*/
class LPSimplex : public LPAlgorithm {
private:
    bool isSolved(const LPSolverState* state) const;
    int getEnteringColumn(const LPSolverState* state) const;
    VectorXf calculateVectorYk(const LPSolverState* state, int enteringColumn) const;
    bool isBounded(const VectorXf& yk) const;
    int getExitingColumn(const LPSolverState* state, VectorXf yk) const;
public:
    /**
    * Tells whether the Simplex's Standard algorithm is able to solve the given
    * problem or not. It will be able to do so if the given problem does not
    * have artificial variables nor requires a pure integer solution.
    * @param problem The problem to be solved.
    * @return If the problem can be solved.
    */
    bool canSolve(const LPProblem& problem);
    /**
    * Gets the final solution (valid or unvalid) of the given problem.
    * @param problem The problem we want to begin to solve from.
    * @return The solution performed by this algorithm.
    */
    LPSolution solve(const LPProblem& problem);
    /**
    * Gets the first problem's solver state.
    * @param problem The problem we want to begin to solve from.
    * @return The first solver state associated to the problem.
    */
    LPSolverState solveBySteps(const LPProblem& problem);
    /**
    * The current state advances to its next if possible.
    * @param currentState The state to get the next state from. The state will
    * be changed if the return value is true.
    * @return If the problem has not been solved yet (if we can keep solving or not).
    */
    bool step(LPSolverState* currentState);
};

}
#endif	/* LPSIMPLEX_H */

