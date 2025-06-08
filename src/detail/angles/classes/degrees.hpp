#ifndef GMATH_DEGREES_HPP
#define GMATH_DEGREES_HPP

#include "angle_base.hpp"

GMATH_START

namespace Angles {

#define GENERATE_APPLY_PARAM_OPERATORS_DECL_DEGREES(param_ch) \
\
    degrees &operator param_ch##=(const double other); \
    degrees &operator param_ch##=(const degrees &other); \
    degrees &operator param_ch##=(const radians &other);

#define GENERATE_PARAM_OPERATORS_DECL_DEGREES(param_ch) \
\
    degrees operator param_ch(const double other); \
    degrees operator param_ch(const degrees &other); \
    degrees operator param_ch(const radians &other);

struct radians;

struct degrees final : angle_base {
    explicit degrees(const double val = 0) : angle_base(DEGREES_MAX, val) {}

    degrees(const radians &r);

    degrees &operator=(const double val) {
        set(val);
        return *this;
    }

    GENERATE_APPLY_PARAM_OPERATORS_DECL_DEGREES(+)
    GENERATE_APPLY_PARAM_OPERATORS_DECL_DEGREES(-)
    GENERATE_APPLY_PARAM_OPERATORS_DECL_DEGREES(*)
    GENERATE_APPLY_PARAM_OPERATORS_DECL_DEGREES(/)

    GENERATE_PARAM_OPERATORS_DECL_DEGREES(+)
    GENERATE_PARAM_OPERATORS_DECL_DEGREES(-)
    GENERATE_PARAM_OPERATORS_DECL_DEGREES(*)
    GENERATE_PARAM_OPERATORS_DECL_DEGREES(/)
};

}

GMATH_END

#endif // GMATH_DEGREES_HPP
