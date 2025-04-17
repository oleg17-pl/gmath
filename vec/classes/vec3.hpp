#ifndef VEC3_HPP
#define VEC3_HPP

#include "vec_base.hpp"

template <class T = vec_default_type>
struct vec3 final : vec_base<3, T> {

    vec3(T x = 0, T y = 0, T z = 0) {
        this->els = {x, y, z};
    }

    [[ nodiscard ]] T &x() const { return this->els.at(0); }
    [[ nodiscard ]] T &y() const { return this->els.at(1); }
    [[ nodiscard ]] T &z() const { return this->els.at(2); }

    vec3<T> &operator=(const vec_base<3, T> &other) {
        this->els = other.els;
        return *this;
    };
};

#endif // VEC3_HPP
