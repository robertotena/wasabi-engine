/* 
 * File:   FuzzyTerm.h
 * Author: Roberto
 *
 * Created on 18 de noviembre de 2010, 2:04
 */

#ifndef FUZZYTERM_H
#define	FUZZYTERM_H

#include <string>

namespace WasabiEngine {

    /**
    * Base class representing a Fuzzy term.
    */
    class FuzzyTerm {
    public:
        virtual ~FuzzyTerm() {
        }
        /**
        * Gets a copy of the term. The user is responsible of the memory management.
        * @return The term copy.
        */
        virtual FuzzyTerm* clone() const = 0;
        /**
        * Gets the term's degree of membership.
        * @return The DOM.
        */
        virtual float getDOM() const = 0;
        /**
        * Clears the term's DOM.
        */
        virtual void clearDOM() = 0;
        /**
        * ORs the given value with the current term's DOM.
        * @param value The value to be ORed with.
        */
        virtual void ORWithDOM(const float& value) = 0;
        virtual std::string toString() const = 0;
    };
}

#endif	/* FUZZYTERM_H */

