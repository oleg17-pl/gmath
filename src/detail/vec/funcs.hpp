#ifndef GMATH_VEC_FUNCS_HPP
#define GMATH_VEC_FUNCS_HPP

#include <cmath>

#include "../../setup.hpp"
#include "../../constants.hpp"

#include "classes/vec2.hpp"
#include "classes/vec3.hpp"
#include "classes/vec4.hpp"

GMATH_START

namespace Vec {

template <std::size_t n, typename T>
[[ nodiscard ]] float getLen(const vec_base<n, T> &vec) {
    T sum_els_sqrs{};
    for (std::size_t i{}; i < vec.getSize(); ++i) {
        const T el{ vec[i] };
        sum_els_sqrs += el * el;
    }
    return sqrt(sum_els_sqrs);
}

#define GENERATE_NORMALIZE_FUNC(vec_size_num) \
\
    template <typename T> \
    [[ nodiscard ]] vec##vec_size_num<T> normalize(const vec##vec_size_num<T> &vec) { \
        float len{ getLen(vec) }; \
        if (len > Constants::EPS) { \
            return vec / len;  \
        } \
        return vec##vec_size_num<T>{}; \
    }

GENERATE_NORMALIZE_FUNC(2)
GENERATE_NORMALIZE_FUNC(3)
GENERATE_NORMALIZE_FUNC(4)

template <std::size_t n, typename T>
[[ nodiscard ]] T dot(const vec_base<n, T> &first, const vec_base<n, T> &second) {
    T result{};
    for (std::size_t i{}; i < first.getSize(); ++i) {
        result += first[i] * second[i];
    }
    return result;
}

}

GMATH_END

#endif // GMATH_VEC_FUNCS_HPP
