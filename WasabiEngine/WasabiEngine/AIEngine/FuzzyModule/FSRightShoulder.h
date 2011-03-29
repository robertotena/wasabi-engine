/* 
 * File:   FSRightShoulder.h
 * Author: Roberto
 *
 * Created on 17 de noviembre de 2010, 2:26
 */

#ifndef FSRIGHTSHOULDER_H
#define	FSRIGHTSHOULDER_H

#include <WasabiEngine/AIEngine/FuzzyModule/FuzzySet.h>

namespace WasabiEngine {

    /**
    * Represents a Right Shoulder fuzzy set.
    *
    * This class is represented by 3 variables: the left end, the mid point (the
    * plateau's beginning) and the right end (the end of the plateau).
    */
    class FSRightShoulder : public FuzzySet {
    private:
        float leftEnd;
        float midPoint;
        float rightEnd;
    public:

        FSRightShoulder(std::string name, float left, float mid, float right) :
            FuzzySet(name, (right + mid) / 2), leftEnd(left), midPoint(mid), rightEnd(right) {
        };
        FSRightShoulder(const FSRightShoulder& orig);
        /**
        * Calculates the current Degree Of Membership to zero. It DOES NOT set the
        * performed value.
        */
        float calculateDOM(float value);
    };
}

#endif	/* FSRIGHTSHOULDER_H */

