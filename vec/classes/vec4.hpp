#ifndef VEC4_HPP
#define VEC4_HPP

#include "vec_base.hpp"

template <typename T = vec_default_type>
struct vec4 final : vec_base<4, T> {

    vec4(T x = 0.0f, T y = 0.0f, T z = 0.0f, T w = 0.0f) {
        this->els = {x, y, z, w};
    }

    [[ nodiscard ]] T &x() { return this->els.at(0); }
    [[ nodiscard ]] T &y() { return this->els.at(1); }
    [[ nodiscard ]] T &z() { return this->els.at(2); }
    [[ nodiscard ]] T &w() { return this->els.at(3); }

    vec4<T> &operator=(const vec_base<4, T> &other) {
        this->els = other.els;
        return *this;
    }
};

#endif // VEC4_HPP
