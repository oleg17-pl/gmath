#ifndef F_HPP
#define F_HPP

#include "../vec.hpp"

template <std::size_t n, class T>
[[ nodiscard ]] vec_base<n, T> normalized(const vec_base<n, T> &vec) {
    vec_base<n, T> norm_vec{ vec };
    float len{ norm_vec.getLen() };

    for (T &el : norm_vec.els) {
        el /= len;
    }
    return norm_vec;
}

template <class T>
[[ nodiscard ]] vec2<T> normalized(const vec2<T> &vec) {
    vec_base<2, T> norm_vec{
        normalized(static_cast<vec_base<2, T>>(vec))
    };
    return static_cast<vec2<T>>(norm_vec);
}

template <class T>
[[ nodiscard ]] vec3<T> normalized(const vec3<T> &vec) {
    vec_base<3, T> norm_vec{
        normalized(static_cast<vec_base<3, T>>(vec))
    };
    return static_cast<vec3<T>>(norm_vec);
}

template <class T>
[[ nodiscard ]] vec4<T> normalized(const vec4<T> &vec) {
    vec_base<4, T> norm_vec{
        normalized(static_cast<vec_base<4, T>>(vec))
    };
    return static_cast<vec4<T>>(norm_vec);
}

#endif // F_HPP
