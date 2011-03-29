/* 
 * File:   FzVery.h
 * Author: Roberto
 *
 * Created on 21 de noviembre de 2010, 19:11
 */

#ifndef FZVERY_H
#define	FZVERY_H

#include <WasabiEngine/AIEngine/FuzzyModule/FzSet.h>
#include <WasabiEngine/AIEngine/FuzzyModule/FuzzySet.h>
#include <WasabiEngine/AIEngine/FuzzyModule/FuzzyTerm.h>

namespace WasabiEngine {

    /**
    * Is a proxy of a given fuzzy set from a linguistic variable applying the
    * 'Very' hedge.
    *
    * This class is used like FzSet, but the result of its DOM will be squared.
    */
    class FzVery : public FuzzyTerm {
    private:
        FuzzySet* fSet;
    public:

        FzVery(FuzzySet* fs){
             fSet = fs;
        }

        FzVery(FzSet* fs) {
            fSet = fs->fSet;

        }

        FzVery(const FzVery& orig) {
            fSet = orig.fSet;
        }

        /**
        * Gets a copy of the term. The user is responsible of the memory management.
        * @return The term copy.
        */
        FuzzyTerm* clone() const {
            return new FzVery(*this);
        }
        /**
        * Gets the squared set's degree of membership.
        * @return The squared set's DOM.
        */
        float getDOM() const {
            return fSet->getDOM() * fSet->getDOM();
        }
        /**
        * Clears the set's DOM. To do so it clears the set's DOM
        */
        void clearDOM() {
            fSet->clearDOM();
        }
        /**
        * ORs the squared given value with the set's value.
        * @param value The value to be ORed with.
        */
        void ORWithDOM(const float& value) {
            fSet->ORWithDOM(value * value);
        }

        std::string toString() const{
            return "VERY( " + fSet->getName() + " )";
        }
    };
}

#endif	/* FZVERY_H */

