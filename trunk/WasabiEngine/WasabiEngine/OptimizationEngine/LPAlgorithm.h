/* 
 * File:   LPAlgorithm.h
 * Author: Roberto
 *
 * Created on 9 de diciembre de 2010, 18:08
 */

#ifndef LPALGORITHM_H
#define	LPALGORITHM_H

#include "LPSolverState.h"
#include "LPSolution.h"
#include "LPProblem.h"

namespace WasabiEngine {

class LPSolverState;

class LPAlgorithm {
public:
    virtual ~LPAlgorithm(){}
    /**
    * Tells whether the algorithm is able to solve the given
    * problem or not.
    * @param problem The problem to be solved.
    * @return If the problem can be solved.
    */
    virtual bool canSolve(const LPProblem& problem) = 0;
     /**
    * Gets the final solution (valid or unvalid) of the given problem.
    * @param problem The problem we want to begin to solve from.
    * @return The solution performed by the algorithm.
    */
    virtual LPSolution solve(const LPProblem& problem) = 0;
    /**
    * Gets the first problem's solver state.
    * @param problem The problem we want to begin to solve from.
    * @return The first solver state associated to the problem.
    */
    virtual LPSolverState solveBySteps(const LPProblem& problem) = 0;
    /**
    * The current state advances to its next if possible.
    * @param currentState The state to get the next state from. The state will
    * be changed if the return value is true.
    * @return If the problem has not been solved yet (if we can keep solving or not).
    */
    virtual bool step(LPSolverState* currentState) = 0;
};

}

#endif	/* LPALGORITHM_H */

