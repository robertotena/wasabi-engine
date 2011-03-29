/* 
 * File:   FSLeftShoulder.h
 * Author: Roberto
 *
 * Created on 17 de noviembre de 2010, 2:36
 */

#ifndef FSLEFTSHOULDER_H
#define	FSLEFTSHOULDER_H

#include <WasabiEngine/AIEngine/FuzzyModule/FuzzySet.h>

namespace WasabiEngine {

    /**
    * Represents a Left Shoulder fuzzy set.
    *
    * This class is represented by 3 variables: the left end (the plateau's
    * beginning), the mid point (the end of the plateau) and the right end.
    */
    class FSLeftShoulder : public FuzzySet {
    private:
        float leftEnd;
        float midPoint;
        float rightEnd;
    public:

        FSLeftShoulder(std::string name, float left, float mid, float right) :
            FuzzySet(name, (left + mid) / 2), leftEnd(left), midPoint(mid), rightEnd(right) {
        }
        FSLeftShoulder(const FSLeftShoulder& orig);
        /**
        * Calculates the current Degree Of Membership to zero. It DOES NOT set the
        * performed value.
        */
        float calculateDOM(float value);
    };
}

#endif	/* FSLEFTSHOULDER_H */

