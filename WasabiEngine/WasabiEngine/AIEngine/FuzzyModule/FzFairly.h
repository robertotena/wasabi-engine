/* 
 * File:   FzFairly.h
 * Author: Roberto
 *
 * Created on 20 de noviembre de 2010, 20:22
 */

#ifndef FZFAIRLY_H
#define	FZFAIRLY_H

#include <math.h>
#include <WasabiEngine/AIEngine/FuzzyModule/FzSet.h>
#include <WasabiEngine/AIEngine/FuzzyModule/FuzzySet.h>
#include <WasabiEngine/AIEngine/FuzzyModule/FuzzyTerm.h>

class FuzzySet;

namespace WasabiEngine {

    /**
    * Is a proxy of a given fuzzy set from a linguistic variable applying the
    * 'Fairly' hedge.
    *
    * This class is used like FzSet, but the result of its DOM will be its
    * square root.
    */
    class FzFairly : public FuzzyTerm {
    private:
        FuzzySet* fSet;
    public:

        FzFairly(FuzzySet* fs) {
            fSet = fs;
        }

        FzFairly(FzSet* fs){
            fSet = fs->fSet;
        }

        FzFairly(const FzFairly& orig) : fSet(orig.fSet) {
        }
        /**
        * Gets a copy of the term. The user is responsible of the memory management.
        * @return The term copy.
        */
        FuzzyTerm* clone() const {
            return new FzFairly(*this);
        }
        /**
        * Gets the set's degree of membership square root.
        * @return The set's DOM square root.
        */
        float getDOM() const {
            return sqrt(fSet->getDOM());
        }
        /**
        * Clears the set's DOM. To do so it clears the set's DOM
        */
        void clearDOM() {
            fSet->clearDOM();
        }
        /**
        * ORs the given value's square root with the set's value.
        * @param value The value to be ORed with.
        */
        void ORWithDOM(const float& value) {
            fSet->ORWithDOM(sqrt(value));
        }

        std::string toString() const{
            return "FAIRLY( " + fSet->getName() + " )";
        }
    };
}

#endif	/* FZFAIRLY_H */

