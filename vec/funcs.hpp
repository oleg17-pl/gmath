#ifndef F_HPP
#define F_HPP

#include "classes/vec2.hpp"
#include "classes/vec3.hpp"
#include "classes/vec4.hpp"

template <typename T>
[[ nodiscard ]] vec2<T> normalize(const vec2<T> &vec) {
    return vec / vec.getLen();
}

template <typename T>
[[ nodiscard ]] vec3<T> normalize(const vec3<T> &vec) {
    return vec / vec.getLen();
}

template <typename T>
[[ nodiscard ]] vec4<T> normalize(const vec4<T> &vec) {
    return vec / vec.getLen();
}


#endif // F_HPP
