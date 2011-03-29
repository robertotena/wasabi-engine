/* 
 * File:   LPProblem.h
 * Author: Roberto
 *
 * Created on 8 de diciembre de 2010, 22:27
 */

#ifndef LPPROBLEM_H
#define	LPPROBLEM_H

#include <string>
#include <sstream>
#include <vector>
#include <Eigen/Core>
#include <Eigen/Array>
#include <Eigen/LU>
USING_PART_OF_NAMESPACE_EIGEN
#include "LPRestriction.h"

namespace WasabiEngine {

/**
*  Represents a linear programming problem.
*
*  The problem representation is based on a target function, a set of
* restrictions, and the target type of the problem (maximize or minimize).
* Also, the target type may be positive or negative, so the result sign would
* change accordingly.
*/
class LPProblem {
    friend class LPSolverState;
    friend class LPSimplex;
    friend class LPPenalties;
    friend class LPBranchBound;
public:
    static const int M_CONST;
    enum LPProblemType {
        max, min
    };
private:
    LPProblemType problemType;
    int sign;
    bool integerProblem;
    std::vector<int> targetFunction;
    std::vector<LPRestriction> restrictions;
    std::vector<int> initialBase;
    int defaultVariables;
    int slackVariables;
    int artificialVariables;

    void standardizeRestriction(const int& i);
    MatrixXf getMatrixA() const;
    VectorXf getVectorD() const;
public:
    LPProblem();
    LPProblem(const LPProblemType& type,
              const bool& isIntegerProblem,
              const std::vector<int>& targetFunction);
    LPProblem(const LPProblem& orig);
    /**
    * It transforms the current problem to its standard mode (if it is not already).
    * In order to standardize, it will look for an identity matrix at the right
    * of the restrictions' matrix. If it does not have any, it will add the artificial
    * and slack variables in order to get it.
    */
    void standardize();
    std::string toString() const;

    //getters and setters
    bool isIntegerProblem() const;
    void setIntegerProblem(const bool& integerProblem);
    LPProblemType getProblemType() const;
    std::vector<LPRestriction> getRestrictions() const;
    void setRestrictions(const std::vector<LPRestriction>& restrictions);
    void addRestriction(const LPRestriction& restriction);
    int getSign() const;
    int getDefaultVariables() const;
    int getSlackVariables() const;
    int getArtificialVariables() const;
    std::vector<int> getTargetFunction() const;
};


inline void LPProblem::addRestriction(const LPRestriction& restriction)
{
    this->restrictions.push_back(restriction);
}

inline bool LPProblem::isIntegerProblem() const {
    return integerProblem;
}

inline void LPProblem::setIntegerProblem(const bool& integerProblem) {
    this->integerProblem = integerProblem;
}

inline LPProblem::LPProblemType LPProblem::getProblemType() const {
    return problemType;
}

inline std::vector<LPRestriction> LPProblem::getRestrictions() const {
    return restrictions;
}

inline void LPProblem::setRestrictions(const std::vector<LPRestriction>& restrictions) {
    this->restrictions = restrictions;
}

inline int LPProblem::getSign() const {
    return sign;
}

inline int LPProblem::getDefaultVariables() const {
    return defaultVariables;
}

inline int LPProblem::getSlackVariables() const {
    return slackVariables;
}

inline int LPProblem::getArtificialVariables() const {
    return artificialVariables;
}

inline std::vector<int> LPProblem::getTargetFunction() const {
    return targetFunction;
}

}

#endif	/* LPPROBLEM_H */

