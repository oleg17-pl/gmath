#ifndef GMATH_MAT_SPECIAL_FUNCS_HPP
#define GMATH_MAT_SPECIAL_FUNCS_HPP

#include "../classes/mat4x4.hpp"
#include "../../vec/classes/vec3.hpp"

#include "base_funcs.hpp"

#include "../../../constants.hpp"

GMATH_START

namespace Mat {

template <typename T = default_mat_type>
mat4<T> get_tranlation(const Vec::vec3<T> &t) {
    mat4<T> result{ mat4<T>::get_single() };
    result.at(0, 3) = t.at(0);
    result.at(1, 3) = t.at(1);
    result.at(2, 3) = t.at(2);
    return result;
}

template <typename T = default_mat_type>
mat4<T> get_scale(const Vec::vec3<T> &s) {
    mat4<T> result{};
    result.at(0, 0) = s.at(0);
    result.at(1, 1) = s.at(1);
    result.at(2, 2) = s.at(2);
    result.at(3, 3) = 1;
    return result;
}

}

GMATH_END

#endif // GMATH_MAT_SPECIAL_FUNCS_HPP
