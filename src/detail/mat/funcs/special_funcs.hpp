#ifndef GMATH_MAT_SPECIAL_FUNCS_HPP
#define GMATH_MAT_SPECIAL_FUNCS_HPP

#include "../classes/mat4x4.hpp"
#include "../../vec/classes/vec3.hpp"
#include "../../../angles.hpp"

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

template <typename T = default_mat_type>
mat4<T> get_rotation_x(const Angles::radians &a) {
    mat4<T> result{};
    double s{ std::sin(a) };
    double c{ std::cos(a) };
    s = s < Constants::EPS ? 0 : s;
    c = c < Constants::EPS ? 0 : c;

    result.at(0, 0) = 1;
    result.at(1, 1) = c;
    result.at(1, 2) = -s;
    result.at(2, 1) = s;
    result.at(2, 2) = c;
    result.at(3, 3) = 1;

    return result;
}

template <typename T = default_mat_type>
mat4<T> get_rotation_y(const Angles::radians &a) {
    mat4<T> result{};
    double s{ std::sin(a) };
    double c{ std::cos(a) };
    s = s < Constants::EPS ? 0 : s;
    c = c < Constants::EPS ? 0 : c;

    result.at(0, 0) = c;
    result.at(0, 2) = s;
    result.at(1, 1) = 1;
    result.at(2, 0) = -s;
    result.at(2, 2) = c;
    result.at(3, 3) = 1;

    return result;
}

template <typename T = default_mat_type>
mat4<T> get_rotation_z(const Angles::radians &a) {
    mat4<T> result{};
    double s{ std::sin(a) };
    double c{ std::cos(a) };
    s = s < Constants::EPS ? 0 : s;
    c = c < Constants::EPS ? 0 : c;

    result.at(0, 0) = c;
    result.at(0, 1) = -s;
    result.at(1, 0) = s;
    result.at(1, 1) = c;
    result.at(2, 2) = 1;
    result.at(3, 3) = 1;

    return result;
}

}

GMATH_END

#endif // GMATH_MAT_SPECIAL_FUNCS_HPP
