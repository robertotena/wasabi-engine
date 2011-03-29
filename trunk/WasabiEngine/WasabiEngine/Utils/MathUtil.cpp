#include "MathUtil.h"

#if defined(__UNIX)
#endif

using namespace WasabiEngine;

const float WasabiMath::PI = M_PI;

int WasabiMath::sign(const float& number) {
    if (number == 0) return 0;
    if (number < 0) return -1;
    return 1;
}

float WasabiMath::max(const float& a, const float& b){
    return (a > b ? a : b);
}
float WasabiMath::min(const float& a, const float& b){
    return (a < b ? a : b);
}
