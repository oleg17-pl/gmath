#ifndef VEC2_HPP
#define VEC2_HPP

#include "vec_base.hpp"

template <typename T = vec_default_type>
struct vec2 final : vec_base<2, T> {

    vec2(T x = 0.0f, T y = 0.0f) {
        this->els = {x, y};
    }

    [[ nodiscard ]] T &x() { return this->els.at(0); }
    [[ nodiscard ]] T &y() { return this->els.at(1); }

    vec2<T> &operator=(const vec_base<2, T> &other) {
        this->els = other.els;
        return *this;
    }
};

#endif // VEC2_HPP
