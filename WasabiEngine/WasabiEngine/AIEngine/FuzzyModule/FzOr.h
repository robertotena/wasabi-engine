/* 
 * File:   FzOr.h
 * Author: Roberto
 *
 * Created on 24 de noviembre de 2010, 0:24
 */

#ifndef FZOR_H
#define	FZOR_H

#include <WasabiEngine/AIEngine/FuzzyModule/FuzzyTerm.h>

namespace WasabiEngine {

    /**
    * Represents an OR operation between 2, 3 or 4 terms.
    *
    */
    class FzOr : public FuzzyTerm {
    private:
        short numOperands;
        FuzzyTerm* operands[4];
    public:
        FzOr(FuzzyTerm* op1, FuzzyTerm* op2);
        FzOr(FuzzyTerm& op1, FuzzyTerm& op2);
        FzOr(FuzzyTerm& op1, FuzzyTerm& op2, FuzzyTerm& op3);
        FzOr(FuzzyTerm& op1, FuzzyTerm& op2, FuzzyTerm& op3, FuzzyTerm& op4);
        FzOr(const FzOr& orig);
        ~FzOr();
        /**
        * Gets a copy of the term. The user is responsible of the memory management.
        * @return The term copy.
        */
        FuzzyTerm* clone() const {
            return new FzOr(*this);
        }
        /**
        * Gets the term's degree of membership.
        * @return The maximum DOM of its terms.
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

#endif	/* FZOR_H */

