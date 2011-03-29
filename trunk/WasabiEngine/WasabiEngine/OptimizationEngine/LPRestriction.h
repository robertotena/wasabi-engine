/* 
 * File:   LPRestriction.h
 * Author: Roberto
 *
 * Created on 8 de diciembre de 2010, 22:52
 */

#ifndef LPRESTRICTION_H
#define	LPRESTRICTION_H

#include <vector>
#include <string>
#include <sstream>

namespace WasabiEngine {


    /**
    *  Represents a problem's restriction.
    *
    *  Each restriction is represented by a vector of coefficients, which must
    * be as large as the target function, an equality type and the equality
    * value or 'd'.
    */
    class LPRestriction {
    public:
        enum LPRestrictionEqualityType {
            equal, lessEqual, greaterEqual
        };
    private:
        std::vector<int> coefficients;
        LPRestrictionEqualityType equalityType;
        int d;
    public:
        LPRestriction(const std::vector<int>& coef, const LPRestrictionEqualityType& type, const int& d);
        LPRestriction(const LPRestriction& orig);
        int standardize();
        void addCoefficient(const int& coefficient);
        std::string toString() const;
        
        // getters and setters
        std::vector<int> getCoefficients() const;
        int getD() const;
        LPRestrictionEqualityType getEqualityType() const;
    };

    inline void LPRestriction::addCoefficient(const int& coefficient)
    {
        coefficients.push_back(coefficient);
    }

    inline std::vector<int> LPRestriction::getCoefficients() const {
        return coefficients;
    }

    inline int LPRestriction::getD() const {
        return d;
    }

    inline LPRestriction::LPRestrictionEqualityType LPRestriction::getEqualityType() const {
        return equalityType;
    }
}

#endif	/* LPRESTRICTION_H */

