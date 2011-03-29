/* 
 * File:   FuzzyRule.h
 * Author: Roberto
 *
 * Created on 23 de noviembre de 2010, 19:24
 */

#ifndef FUZZYRULE_H
#define	FUZZYRULE_H

#include <cstdio>
#include <string>
#include <WasabiEngine/AIEngine/FuzzyModule/FuzzyTerm.h>

namespace WasabiEngine {

    /**
    * Represents a rule in a fuzzy system.
    *
    * This class takes two terms: an antecedent and a consequent. The antecedent
    * result will be stored in the consequent.
    */
    class FuzzyRule {
    private:
        FuzzyTerm* antecedent;
        FuzzyTerm* consequent;
    public:
        FuzzyRule(const FuzzyTerm* ant, const FuzzyTerm* cons);
        FuzzyRule(const FuzzyTerm& ant, const FuzzyTerm& cons);
        FuzzyRule(const FuzzyRule& orig);
        ~FuzzyRule();

        std::string toString() const
        {
            return "IF " + antecedent->toString() + " THEN " + consequent->toString();
        }
        /**
        * Gets the antecedent result and is ORed with the consequent.
        * @return The antecedent result.
        */
        float calculate() {
            float value = antecedent->getDOM();
            consequent->ORWithDOM(value);
            return value;
        }
        
        void clearConsequentConfidence()
        {
            consequent->clearDOM();
        }
    };
}

#endif	/* FUZZYRULE_H */

