#ifndef GMATH_VEC_FUNCS_HPP
#define GMATH_VEC_FUNCS_HPP

#include <cmath>

#include "../../constants.hpp"
#include "classes/vec_base.hpp"

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

template <std::size_t n, typename T> \
[[ nodiscard ]] vec_base<n, T> normalize(const vec_base<n, T> &vec) {
    float len{ getLen(vec) };
    if (len > Constants::EPS) {
        return vec / len;
    }
    return vec_base<n, T>{};
}

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
