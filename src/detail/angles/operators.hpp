#ifndef GMATH_ANGLES_OPERATORS_HPP
#define GMATH_ANGLES_OPERATORS_HPP

#include "classes/degrees.hpp"
#include "classes/radians.hpp"

#include "funcs.hpp"

GMATH_START

namespace Angles {

#define GENERATE_APPLY_PARAM_OPERATOR_RADIANS(param_ch) \
\
    radians &radians::operator param_ch##=(const double other) { \
        this->set(this->get() param_ch other); \
        return *this; \
    } \
\
    radians &radians::operator param_ch##=(const radians &other) { \
        this->set(this->get() param_ch other); \
        return *this; \
    } \
\
    radians &radians::operator param_ch##=(const degrees &other) { \
        this->set(this->get() param_ch radians{ other }); \
        return *this; \
    }

#define GENERATE_APPLY_PARAM_OPERATOR_DEGREES(param_ch) \
\
    degrees &degrees::operator param_ch##=(const double other) { \
        this->set(this->get() param_ch other); \
        return *this; \
    } \
\
    degrees &degrees::operator param_ch##=(const degrees &other) { \
        this->set(this->get() param_ch other); \
        return *this; \
    } \
\
    degrees &degrees::operator param_ch##=(const radians &other) { \
        this->set(this->get() param_ch degrees{ other }); \
        return *this; \
    }

#define GENERATE_PARAM_OPERATOR_RADIANS(param_ch) \
\
    radians radians::operator param_ch(const double other) { \
        return radians{ this->get() param_ch other }; \
    } \
\
    radians radians::operator param_ch(const radians &other) { \
        return radians{ this->get() param_ch other }; \
    } \
\
    radians radians::operator param_ch(const degrees &other) { \
        return radians{ this->get() param_ch radians{ other } }; \
    }

#define GENERATE_PARAM_OPERATOR_DEGREES(param_ch) \
\
    degrees degrees::operator param_ch(const double other) { \
        return degrees{ this->get() param_ch other }; \
    } \
\
    degrees degrees::operator param_ch(const degrees &other) { \
        return degrees{ this->get() param_ch other }; \
    } \
\
    degrees degrees::operator param_ch(const radians &other) { \
        return degrees{ this->get() param_ch degrees{ other } }; \
    }

GENERATE_APPLY_PARAM_OPERATOR_RADIANS(+)
GENERATE_APPLY_PARAM_OPERATOR_RADIANS(-)
GENERATE_APPLY_PARAM_OPERATOR_RADIANS(*)
GENERATE_APPLY_PARAM_OPERATOR_RADIANS(/)

GENERATE_APPLY_PARAM_OPERATOR_DEGREES(+)
GENERATE_APPLY_PARAM_OPERATOR_DEGREES(-)
GENERATE_APPLY_PARAM_OPERATOR_DEGREES(*)
GENERATE_APPLY_PARAM_OPERATOR_DEGREES(/)

GENERATE_PARAM_OPERATOR_RADIANS(+)
GENERATE_PARAM_OPERATOR_RADIANS(-)
GENERATE_PARAM_OPERATOR_RADIANS(*)
GENERATE_PARAM_OPERATOR_RADIANS(/)

GENERATE_PARAM_OPERATOR_DEGREES(+)
GENERATE_PARAM_OPERATOR_DEGREES(-)
GENERATE_PARAM_OPERATOR_DEGREES(*)
GENERATE_PARAM_OPERATOR_DEGREES(/)

}

GMATH_END

#endif // GMATH_ANGLES_OPERATORS_HPP
