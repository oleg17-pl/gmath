#ifndef GMATH_RADIANS_HPP
#define GMATH_RADIANS_HPP

#include "angle_base.hpp"

GMATH_START

namespace Angles {

#define GENERATE_APPLY_PARAM_OPERATORS_DECL_RADIANS(param_ch) \
\
    radians &operator param_ch##=(const double other); \
    radians &operator param_ch##=(const radians &other); \
    radians &operator param_ch##=(const degrees &other);

#define GENERATE_PARAM_OPERATORS_DECL_RADIANS(param_ch) \
\
    radians operator param_ch(const double other); \
    radians operator param_ch(const radians &other); \
    radians operator param_ch(const degrees &other);

struct degrees;

struct radians final : angle_base {
    explicit radians(const double val = 0) : angle_base(RADIANS_MAX, val) {}

    radians(const degrees &d);

    radians &operator=(const double val) {
        set(val);
        return *this;
    }

    GENERATE_APPLY_PARAM_OPERATORS_DECL_RADIANS(+)
    GENERATE_APPLY_PARAM_OPERATORS_DECL_RADIANS(-)
    GENERATE_APPLY_PARAM_OPERATORS_DECL_RADIANS(*)
    GENERATE_APPLY_PARAM_OPERATORS_DECL_RADIANS(/)

    GENERATE_PARAM_OPERATORS_DECL_RADIANS(+)
    GENERATE_PARAM_OPERATORS_DECL_RADIANS(-)
    GENERATE_PARAM_OPERATORS_DECL_RADIANS(*)
    GENERATE_PARAM_OPERATORS_DECL_RADIANS(/)
};

}

GMATH_END

#endif // GMATH_RADIANS_HPP
