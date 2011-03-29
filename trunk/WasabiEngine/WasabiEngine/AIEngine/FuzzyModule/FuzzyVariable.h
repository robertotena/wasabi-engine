/* 
 * File:   FuzzyVariable.h
 * Author: Roberto
 *
 * Created on 17 de noviembre de 2010, 16:27
 */

#ifndef FUZZYVARIABLE_H
#define	FUZZYVARIABLE_H

#include <map>
#include <vector>
#include <string>
#include <math.h>
#include <WasabiEngine/AIEngine/FuzzyModule/FuzzySet.h>
#include <WasabiEngine/AIEngine/FuzzyModule/FSTriangle.h>
#include <WasabiEngine/AIEngine/FuzzyModule/FSTrapezoid.h>
#include <WasabiEngine/AIEngine/FuzzyModule/FSLeftShoulder.h>
#include <WasabiEngine/AIEngine/FuzzyModule/FSRightShoulder.h>
#include <WasabiEngine/AIEngine/FuzzyModule/FSSingleton.h>
#include <WasabiEngine/AIEngine/FuzzyModule/FzSet.h>
#include <WasabiEngine/Utils/MathUtil.h>

namespace WasabiEngine {

    /**
    * Represents a fuzzy linguistic variable.
    *
    * With this class you can create any kind of the available sets, fuzzify
    * a value or defuzzify it with the Average Maxima or Centroid methods.
    */
    class FuzzyVariable {
    private:
        std::string name;
        std::map<std::string, FuzzySet*> memberSets;
        float minRange;
        float maxRange;
        void adjustRange(float minBound, float maxBound);

        FuzzyVariable(const FuzzyVariable& orig) {
            // not allowed
        } 
    public:
        FuzzyVariable(const std::string& name);
        ~FuzzyVariable();
        FzSet addTriangularSet(std::string name, float leftEnd, float midPoint, float rightEnd);
        FzSet addTrapezoidSet(std::string name, float leftEnd, float midLeft, float midRight, float rightEnd);
        FzSet addRightShoulderSet(std::string name, float leftEnd, float midPoint, float rightEnd);
        FzSet addLeftShoulderSet(std::string name, float leftEnd, float midPoint, float rightEnd);
        FzSet addSingletonSet(std::string name, float leftEnd, float rightEnd);
        FzSet getSet(std::string name);
        std::vector<FzSet> getSets() const;
        /**
        * Sets all the sets' DOM to zero.
        */
        void clearDOMs();
        /**
        * Fuzzifies the given value. The result will be stored in the sets' DOM.
        * @param value The value to be fuzzified.
        */
        void fuzzify(float value);
        /**
        * Defuzzifies the variable with the Average Maxima method.
        * @return The crisp value.
        */
        float deffuzifyMaxAv() const;
        /**
        * Defuzzifies the variable with the Centroid method.
        * @param numSamples The number of the samples to be taken in the process.
        * @return The crisp value.
        */
        float deffuzifyCentroid(int numSamples) const;
    };
}

#endif	/* FUZZYVARIABLE_H */

