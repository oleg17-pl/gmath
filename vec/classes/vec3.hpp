#ifndef VEC3_HPP
#define VEC3_HPP

#include "vec_base.hpp"

template <typename T = vec_default_type>
struct vec3 final : vec_base<3, T> {

    vec3(T x = 0.0f, T y = 0.0f, T z = 0.0f) {
        this->els = {x, y, z};
    }

    [[ nodiscard ]] T &x() { return this->els.at(0); }
    [[ nodiscard ]] T &y() { return this->els.at(1); }
    [[ nodiscard ]] T &z() { return this->els.at(2); }

    vec3<T> &operator=(const vec_base<3, T> &other) {
        this->els = other.els;
        return *this;
    }
};

#endif // VEC3_HPP
