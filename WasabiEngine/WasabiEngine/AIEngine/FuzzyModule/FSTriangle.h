/* 
 * File:   FSTriangle.h
 * Author: Roberto
 *
 * Created on 16 de noviembre de 2010, 20:29
 */

#ifndef FSTRIANGLE_H
#define	FSTRIANGLE_H

#include <WasabiEngine/AIEngine/FuzzyModule/FuzzySet.h>

namespace WasabiEngine {

    /**
    * Represents a Triangle fuzzy set.
    *
    * This class is represented by 3 variables: the left end, the mid point (the
    * peak value), and the right end.
    */
    class FSTriangle : public FuzzySet {
    private:
        float leftEnd;
        float midPoint;
        float rightEnd;
    public:

        FSTriangle(std::string name, float left, float mid, float right) :
            FuzzySet(name, mid), leftEnd(left), midPoint(mid), rightEnd(right) {
        }
        FSTriangle(const FSTriangle& orig);
        /**
        * Calculates the current Degree Of Membership to zero. It DOES NOT set the
        * performed value.
        */
        float calculateDOM(float value);
    };
}

#endif	/* FSTRIANGLE_H */

