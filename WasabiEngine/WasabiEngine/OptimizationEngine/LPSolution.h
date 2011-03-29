/* 
 * File:   LPSolution.h
 * Author: Roberto
 *
 * Created on 9 de diciembre de 2010, 18:24
 */

#ifndef LPSOLUTION_H
#define	LPSOLUTION_H

#include <vector>
#include <string>
#include <sstream>
#include <cmath>

namespace WasabiEngine {

/**
*  Represents the solution of a known linear programming problem's SolverState
*
*  LPSolution has the terms to be used as the optimal solution of the LPProblem
* associated to a SolverState, as well as the optimal value found. Also tells
* whether and whether it is a valid solution or not (depending on the SolverState's state).
*/
class LPSolution {
    friend class LPSolverState;
private:
    bool validSolution;
    std::vector<float> coefficients;
    float value;

    bool isInteger(const float& number) const ;
public:
    LPSolution();
    LPSolution(const LPSolution& orig);
    bool isPureInteger() const;
    std::string toString() const;

    // getters and setters
    bool isValidSolution() const;
    std::vector<float> getCoefficients() const;
    float getValue() const;
};

inline bool LPSolution::isValidSolution() const {
    return validSolution;
}

inline std::vector<float> LPSolution::getCoefficients() const {
    return coefficients;
}

inline float LPSolution::getValue() const {
    return value;
}

}


#endif	/* LPSOLUTION_H */

