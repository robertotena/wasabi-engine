/* 
 * File:   FzSet.h
 * Author: Roberto
 *
 * Created on 17 de noviembre de 2010, 17:07
 */

#ifndef FZSET_H
#define	FZSET_H

#include <cstdio>
#include <WasabiEngine/AIEngine/FuzzyModule/FuzzyTerm.h>
#include <WasabiEngine/AIEngine/FuzzyModule/FuzzySet.h>

namespace WasabiEngine {

    /**
    * Is a proxy of a given fuzzy set from a linguistic variable.
    *
    * This class is used to access directly to the fuzzy set's main services.
    * This way we can apply our rules without the need of accessing directly to
    * the set.
    */
    class FzSet : public FuzzyTerm {
    public:
        friend class FzVery;
        friend class FzFairly;
    private:
        FuzzySet* fSet;
    public:
        FzSet(FuzzySet* fs) : fSet(fs) {
        }

        FzSet(const FzSet& orig) : fSet(orig.fSet) {
        }
        /**
        * Gets a copy of the term. The user is responsible of the memory management.
        * @return The term copy.
        */
        FuzzyTerm* clone() const {
            return new FzSet(*this);
        }
        /**
        * Gets the set's degree of membership.
        * @return The set's DOM.
        */
        float getDOM() const {
            return fSet->getDOM();
        }
        /**
        * Clears the set's DOM. To do so it clears the set's DOM
        */
        void clearDOM() {
            fSet->clearDOM();
        }
        /**
        * ORs the given value with the set's value.
        * @param value The value to be ORed with.
        */
        void ORWithDOM(const float& value) {
            fSet->ORWithDOM(value);
        }

        std::string toString() const{
            return fSet->getName();
        }
    };
}
#endif	/* FZSET_H */

