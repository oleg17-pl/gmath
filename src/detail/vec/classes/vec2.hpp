#ifndef GMATH_VEC2_HPP
#define GMATH_VEC2_HPP

#include "vec_base.hpp"

GMATH_START

namespace Vec {

template <typename T = vec_default_type>
struct vec2 final : vec_base<2, T> {

    explicit vec2(T x, T y) : vec_base<2, T>({x, y}) {}
    explicit vec2(T val) : vec_base<2, T>(val) {}
    vec2() : vec2(0) {}

    [[ nodiscard ]] T &x() { return this->at(0); }
    [[ nodiscard ]] T &y() { return this->at(1); }
};

}

GMATH_END

#endif // GMATH_VEC2_HPP
