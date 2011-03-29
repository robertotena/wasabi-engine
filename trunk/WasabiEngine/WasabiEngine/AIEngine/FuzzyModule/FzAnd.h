/* 
 * File:   FzAnd.h
 * Author: Roberto
 *
 * Created on 23 de noviembre de 2010, 20:38
 */

#ifndef FZAND_H
#define	FZAND_H

#include <WasabiEngine/AIEngine/FuzzyModule/FuzzyTerm.h>

namespace WasabiEngine {

    /**
    * Represents an AND operation between 2, 3 or 4 terms.
    *
    */
    class FzAnd : public FuzzyTerm {
    private:
        short numOperands;
        FuzzyTerm* operands[4];
    public:
        FzAnd(FuzzyTerm* op1, FuzzyTerm* op2);
        FzAnd(FuzzyTerm& op1, FuzzyTerm& op2);
        FzAnd(FuzzyTerm& op1, FuzzyTerm& op2, FuzzyTerm& op3);
        FzAnd(FuzzyTerm& op1, FuzzyTerm& op2, FuzzyTerm& op3, FuzzyTerm& op4);
        FzAnd(const FzAnd& orig);
        ~FzAnd();
        /**
        * Gets a copy of the term. The user is responsible of the memory management.
        * @return The term copy.
        */
        FuzzyTerm* clone() const {
            return new FzAnd(*this);
        }
        /**
        * Gets the term's degree of membership.
        * @return The minimum DOM of its terms.
        */
        float getDOM() const;
        /**
        * Clears the term's DOM. To do so it clears its operands.
        */
        void clearDOM();
        /**
        * ORs the given value with the operands this term has.
        * @param value The value to be ORed with.
        */
        void ORWithDOM(const float& value);
        std::string toString() const;
    };
}

#endif	/* FZAND_H */

