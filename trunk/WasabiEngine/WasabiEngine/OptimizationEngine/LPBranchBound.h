/* 
 * File:   LPBranchBound.h
 * Author: Roberto
 *
 * Created on 15 de diciembre de 2010, 2:09
 */

#ifndef LPBRANCHBOUND_H
#define	LPBRANCHBOUND_H

#include <climits>
#include "LPAlgorithm.h"
#include "LPPenalties.h"

namespace WasabiEngine
{

/**
*  Solves a linear programming problem using the Branch & Bound Simplex
* Algorithm.
*
*  LPBranchBound makes use of the Branch & Bound Simplex Algorithm to solve a
* given LPProblem. It is able to know if it can solve the problem, but is not
* able to solve it by steps.
*/
class LPBranchBound : public LPAlgorithm {
private:
    LPPenalties penaltiesSolver;
    void ramify(std::vector<LPProblem>& problemQueue, LPSolution& solution);
    /// Returns true if sol is better solution than bestSol
    bool betterSolution(
        const LPProblem::LPProblemType& type,
        const LPSolution& sol,
        const LPSolution& bestSol);
    bool isInteger(const float& number);
public:
    /**
    * Tells whether the Simplex's Branch & Bound algorithm is able to solve the 
    * given problem or not. It will be able if the given problem requires a pure
    * integer solution.
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
    * It does not do anything. This algorithm is not able to solve by steps.
    */
    LPSolverState solveBySteps(const LPProblem& problem);
    /**
    * It does not do anything. This algorithm is not able to solve by steps.
    */
    bool step(LPSolverState* currentState);
};

}
#endif	/* LPBRANCHBOUND_H */

