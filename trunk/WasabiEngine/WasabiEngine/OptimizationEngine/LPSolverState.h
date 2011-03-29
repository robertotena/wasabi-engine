/* 
 * File:   LPSolverState.h
 * Author: Roberto
 *
 * Created on 9 de diciembre de 2010, 17:47
 */

#ifndef LPSOLVERSTATE_H
#define	LPSOLVERSTATE_H

#include <vector>
#include <string>
#include <sstream>
#include "LPProblem.h"
#include "LPSolution.h"
#include "LPAlgorithm.h"

namespace WasabiEngine {

class LPAlgorithm;

/**
 *  Represents a linear programming solving state.
 *
 *  This class is used to follow the different states the solving process is going
 *  through. It will be created by one of the Simplex's Algorithms, so LPSolverState
 *  knows which algorithm will need to keep solving.
 */
class LPSolverState {
    friend class LPSimplex;
    friend class LPPenalties;
private:
    LPProblem problem;
    LPAlgorithm* solver;
    bool solved;
    bool solvable;
    std::vector<int> base;
    std::vector<int> cb;
    std::vector<float> dBar;
    std::vector<float> zj_cj;
    void updateBase_Cb(const int& enteringColumn, const int& exitingColumn);
    void updateZj_cj();
    void updateDBar();
    float adjustToInt(const float& number);
    VectorXf getVectorCb() const;
    MatrixXf getMatrixBase() const;
public:
    LPSolverState();
    LPSolverState(const LPSolverState& orig);
    ~LPSolverState();
    /**
    * Gets the associated solution to the current solver state.
    * @return The solution to the current state. It would be the final correct
    * solution if isSolved returns true.
    */
    LPSolution getAssociatedSolution();
    /**
    * Calculates the next solver state (if possible).
    * @param problem The problem to solve.
    * @return If it is possible to continue solving or not (because it is already
    * solved, or it has no solution).
    */
    bool step();
    std::string toString() const;

    // getters and setters
    std::vector<int> getBase() const;
    std::vector<int> getCb() const;
    std::vector<float> getDBar() const;
    std::vector<float> getZj_cj() const;
    /**
    * Lets to know if the problem is still in solving process
    * @return False if the process has already ended (has no solution or solution is found).
    */
    bool isSolvable() const;
    /**
    * Lets to know if the problem has found the correct solution.
    * @return True if the problem has the correct solution.
    */
    bool isSolved() const;
    LPProblem getProblem() const;
};

inline bool LPSolverState::isSolvable() const {
    return solvable;
}

inline bool LPSolverState::isSolved() const {
    return solved;
}

inline std::vector<int> LPSolverState::getBase() const {
    return base;
}

inline std::vector<int> LPSolverState::getCb() const {
    return cb;
}

inline std::vector<float> LPSolverState::getDBar() const {
    return dBar;
}

inline std::vector<float> LPSolverState::getZj_cj() const {
    return zj_cj;
}

inline LPProblem LPSolverState::getProblem() const {
    return problem;
}

}

#endif	/* LPSOLVERSTATE_H */

