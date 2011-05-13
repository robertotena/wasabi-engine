/* 
 * File:   ColourValue.h
 * Author: Fran_2
 *
 * Created on 21 de febrero de 2011, 18:54
 */

#ifndef COLOURVALUE_H
#define	COLOURVALUE_H

namespace WasabiEngine {

    /**
     * Color abstraction
     */
    class ColourValue {
    private:
        float red;
        float green;
        float blue;
        float alpha;
    public:
        static const ColourValue RED;
        static const ColourValue GREEN;
        static const ColourValue BLUE;
        static const ColourValue BLACK;
        static const ColourValue GREY;
        static const ColourValue WHITE;


        ColourValue(const float& red = 1.0, const float& green = 1.0, const float& blue = 1.0, const float& alpha = 1.0);
        ColourValue(const ColourValue& orig);
        void setBlue(float blue);
        void setGreen(float green);
        void setRed(float red);
        void setAlpha(float alpha);
        float getBlue() const;
        float getGreen() const;
        float getRed() const;
        float getAlpha() const;
        /**
         * Pointer accessor to a float array [r,g,b,a]
         */
        const float* ptr() const;
    };

    inline void ColourValue::setBlue(float blue) {
        this->blue = blue;
    }

    inline void ColourValue::setGreen(float green) {
        this->green = green;
    }

    inline void ColourValue::setRed(float red) {
        this->red = red;
    }

    inline void ColourValue::setAlpha(float alpha) {
        this->alpha = alpha;
    }

    inline float ColourValue::getBlue() const {
        return blue;
    }

    inline float ColourValue::getGreen() const {
        return green;
    }

    inline float ColourValue::getRed() const {
        return red;
    }

    inline float ColourValue::getAlpha() const {
        return alpha;
    }

    inline const float* ColourValue::ptr() const{
        return &red;
    }
}

#endif	/* COLOURVALUE_H */

