#ifndef GMATH_ANGLE_BASE_HPP
#define GMATH_ANGLE_BASE_HPP

#include <cmath>

#include "../../../setup.hpp"
#include "../../../constants.hpp"

GMATH_START

namespace Angles {

constexpr double RADIANS_MAX{ Constants::PI * 2 };
constexpr double DEGREES_MAX{ 360.0 };

struct angle_base {
protected:
    double m_value;
    const double MAX_VALUE;
public:
    void set(double val) {
        if (val >= MAX_VALUE || val < -MAX_VALUE) {
            val = std::fmod(val, MAX_VALUE);
        }
        if (val < 0) {
            val = MAX_VALUE + val;
        }
        m_value = val;
    }

    double get() const { return m_value; }
    operator double() const { return m_value; }
protected:
    angle_base(const double max_value, const double val) : MAX_VALUE{ max_value } {
        set(val);
    }
};

}

GMATH_END

#endif // GMATH_ANGLE_BASE_HPP
