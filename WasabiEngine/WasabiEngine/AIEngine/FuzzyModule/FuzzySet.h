/* 
 * File:   FuzzySet.h
 * Author: Roberto
 *
 * Created on 16 de noviembre de 2010, 20:00
 */

#ifndef FUZZYSET_H
#define	FUZZYSET_H

#include <string>

namespace WasabiEngine {

    /**
     * Base class representing a Fuzzy set.
     */
    class FuzzySet {
    protected:
        std::string name;
        float curDOM;
        float representativeValue;
    public:
        FuzzySet();
        FuzzySet(std::string name, const float& representativeValue);
        FuzzySet(const FuzzySet& orig);

        virtual ~FuzzySet() {
        }

        /**
        * Calculates the current Degree Of Membership to zero. It DOES NOT set the
        * performed value.
        */
        virtual float calculateDOM(float value) = 0;

        /**
        * Sets the current Degree Of Membership to zero.
        */
        void clearDOM() {
            curDOM = 0;
        }

        /**
        * Updates the current DOM to the given value, if this is greater than
        * the current DOM.
        * @param dom The dom we want to OR with.
        */
        void ORWithDOM(float dom) {
            if (curDOM < dom) curDOM = dom;
        }
        
        float getRepresentativeValue() const {
            return representativeValue;
        }

        void setDOM(const float& curDOM) {
            this->curDOM = curDOM;
        }

        float getDOM() const {
            return curDOM;
        }

        std::string getName() const {
            return name;
        }

    };
}


#endif	/* FUZZYSET_H */

