#ifndef GMATH_ANGLES_FUNCS_HPP
#define GMATH_ANGLES_FUNCS_HPP

#include "classes/degrees.hpp"
#include "classes/radians.hpp"

GMATH_START

namespace Angles {

radians::radians(const degrees &d) :
    angle_base(RADIANS_MAX, d * (Constants::PI / 180)) {}

degrees::degrees(const radians &r) :
    angle_base(DEGREES_MAX, r * (180 / Constants::PI)) {}

}

GMATH_END

#endif // GMATH_ANGLES_FUNCS_HPP
