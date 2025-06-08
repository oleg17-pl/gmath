#ifndef GMATH_VEC4_HPP
#define GMATH_VEC4_HPP

#include "vec_base.hpp"

GMATH_START

namespace Vec {

template <typename T = vec_default_type>
struct vec4 final : vec_base<4, T> {

    explicit vec4(T x, T y, T z, T w) : vec_base<4, T>({x, y, z, w}) {}
    explicit vec4(T val) : vec_base<4, T>(val) {}
    vec4() : vec4(0) {}

    [[ nodiscard ]]
    static vec4<T> get_single() {
        return vec4{ 0, 0, 0, 1 };
    }

    [[ nodiscard ]] T &x() { return this->at(0); }
    [[ nodiscard ]] T &y() { return this->at(1); }
    [[ nodiscard ]] T &z() { return this->at(2); }
    [[ nodiscard ]] T &w() { return this->at(3); }

    vec4<T> operator=(const vec_base<4, T> &other) {
        for (std::size_t i{}; i < 4; ++i) {
            this->at(i) = other.at(i);
        }
        return *this;
    }
};

}

GMATH_END

#endif // GMATH_VEC4_HPP
