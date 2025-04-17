#ifndef VEC2_HPP
#define VEC2_HPP

#include "vec_base.hpp"

template <class T = vec_default_type>
struct vec2 final : vec_base<2, T> {

    vec2(T x = 0, T y = 0) {
        this->els = {x, y};
    }

    [[ nodiscard ]] T &x() const { return this->els.at(0); }
    [[ nodiscard ]] T &y() const { return this->els.at(1); }

    vec2<T> &operator=(const vec_base<2, T> &other) {
        this->els = other.els;
        return *this;
    };
};

#endif // VEC2_HPP
