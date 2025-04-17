#ifndef VEC4_HPP
#define VEC4_HPP

#include "vec_base.hpp"

template <class T = vec_default_type>
struct vec4 final : vec_base<4, T> {

    vec4(T x, T y, T z, T w) {
        this->els = {x, y, z, w};
    }

    [[ nodiscard ]] T &x() const { return this->els.at(0); }
    [[ nodiscard ]] T &y() const { return this->els.at(1); }
    [[ nodiscard ]] T &z() const { return this->els.at(2); }
    [[ nodiscard ]] T &w() const { return this->els.at(3); }

    vec4<T> &operator=(const vec_base<4, T> &other) {
        this->els = other.els;
        return *this;
    };
};

#endif // VEC4_HPP
