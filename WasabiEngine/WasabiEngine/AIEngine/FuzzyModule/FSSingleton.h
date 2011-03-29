/* 
 * File:   FSSingleton.h
 * Author: Roberto
 *
 * Created on 17 de noviembre de 2010, 2:49
 */

#ifndef FSSINGLETON_H
#define	FSSINGLETON_H

#include <WasabiEngine/AIEngine/FuzzyModule/FuzzySet.h>

namespace WasabiEngine {

    /**
    * Represents a Singleton fuzzy set.
    *
    * This class is represented by 2 variables: the left end (the plateau's
    * beginning) and the right end (the end of the plateau).
    */
    class FSSingleton : public FuzzySet {
    private:
        float leftEnd;
        float rightEnd;
    public:

        FSSingleton(std::string name, float left, float right) :
            FuzzySet(name, (left + right) / 2), leftEnd(left), rightEnd(right) {
        }
        FSSingleton(const FSSingleton& orig);
        /**
        * Calculates the current Degree Of Membership to zero. It DOES NOT set the
        * performed value.
        */
        float calculateDOM(float value);
    };
}

#endif	/* FSSINGLETON_H */

