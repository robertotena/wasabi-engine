/* 
 * File:   FSTrapezoid.h
 * Author: Roberto
 *
 * Created on 18 de diciembre de 2010, 13:58
 */

#ifndef FSTRAPEZOID_H
#define	FSTRAPEZOID_H

#include <WasabiEngine/AIEngine/FuzzyModule/FuzzySet.h>

namespace WasabiEngine {

    /**
    * Represents a Trapezoid fuzzy set.
    *
    * This class is represented by 4 variables: the left end, the mid left point
    * (the plateau's beginning), the mid right point (the end of the plateau)
    * and the right end.
    */
    class FSTrapezoid : public FuzzySet {
    private:
        float leftEnd;
        float midLeft;
        float midRight;
        float rightEnd;
    public:

        FSTrapezoid(std::string name, float left, float mLeft, float mRight, float right) :
            FuzzySet(name, (midLeft + midRight) / 2), leftEnd(left), midLeft(mLeft), midRight(mRight), rightEnd(right) {
        }
        FSTrapezoid(const FSTrapezoid& orig);
        /**
        * Calculates the current Degree Of Membership to zero. It DOES NOT set the
        * performed value.
        */
        float calculateDOM(float value);
    };
}

#endif	/* FSTRAPEZOID_H */

