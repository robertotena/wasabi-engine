/* 
 * File:   FuzzyModule.h
 * Author: Roberto
 *
 * Created on 22 de noviembre de 2010, 1:49
 */

#ifndef FUZZYMODULE_H
#define	FUZZYMODULE_H

#include <map>
#include <vector>
#include <string>
#include <WasabiEngine/AIEngine/FuzzyModule/FuzzyVariable.h>
#include <WasabiEngine/AIEngine/FuzzyModule/FuzzyRule.h>

namespace WasabiEngine {

    /**
    * Represents the main fuzzy module.
    *
    * This class is responsible of managing the variables and rules to be fired.
    * Is the facade to be used for apply fuzzification.
    */
    class FuzzyModule {
    public:

        enum DefuzzifyMethod {
            max_av, centroid
        };
    private:
        int numSamples;
        DefuzzifyMethod method;
        std::map<std::string, FuzzyVariable*> variables;
        std::vector<FuzzyRule*> rules;
        void runRules();
    public:

        FuzzyModule(const int& samples = 10, const DefuzzifyMethod& m = max_av) : numSamples(samples), method(m) {
        }
        ~FuzzyModule();
        FuzzyVariable* createFLV(std::string name);
        FuzzyRule* addRule(const FuzzyTerm* antecendent, const FuzzyTerm* consequent);
        void addRule(const FuzzyTerm& antecendent, const FuzzyTerm& consequent);
        void fuzzify(const std::string& variable, const float& value);
        /**
        * Defuzzifies the given variable.
        * @param variable The variable to be defuzzified.
        * @return The crisp value.
        */
        float deffuzify(const std::string& variable);

        /**
        * Sets the number of samples to be used in the Centroid defuzzification method.
        * @param numSamples The number of samples.
        */
        void setNumSamples(const int& numSamples) {
            this->numSamples = numSamples;
        }
        /**
        * Sets the defuzzification method to be used when the 'defuzzify' method is called.
        * @param method The defuzzify method.
        */
        void setDefuzzifyMethod(const DefuzzifyMethod& method)
        {
            this->method = method;
        }
    };
}

#endif	/* FUZZYMODULE_H */

