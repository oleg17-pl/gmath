#ifndef GMATH_VEC3_HPP
#define GMATH_VEC3_HPP

#include "vec_base.hpp"

GMATH_START

namespace Vec {

template <typename T = vec_default_type>
struct vec3 final : vec_base<3, T> {

    explicit vec3(T x, T y, T z) : vec_base<3, T>({x, y, z}) {}
    explicit vec3(T val) : vec_base<3, T>(val) {}
    vec3() : vec3(0) {}

    [[ nodiscard ]] T &x() { return this->at(0); }
    [[ nodiscard ]] T &y() { return this->at(1); }
    [[ nodiscard ]] T &z() { return this->at(2); }

    vec3<T> operator=(const vec_base<3, T> &other) {
        for (std::size_t i{}; i < 3; ++i) {
            this->at(i) = other.at(i);
        }
        return *this;
    }
};

}

GMATH_END

#endif // GMATH_VEC3_HPP
