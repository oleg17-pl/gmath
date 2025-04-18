#ifndef VEC_OPERATORS_HPP
#define VEC_OPERATORS_HPP

#include "../../constants.hpp"
#include "../classes/vec2.hpp"
#include "../classes/vec3.hpp"
#include "../classes/vec4.hpp"

#include "gen.hpp"

GENERATE_PARAM_APPLY_OPERATORS_ALL
GENERATE_PARAM_OPERATORS_ALL

template <std::size_t n, typename T>
[[ nodiscard ]]
bool operator==(const vec_base<n, T> &first, const vec_base<n, T> &second) {
    return vec_base<n, T>{ first - second }.getLen() < Constants::EPS;
}

template <std::size_t n, typename T>
[[ nodiscard ]]
bool operator!=(const vec_base<n, T> &first, const vec_base<n, T> &second) {
    return !(first == second);
}

#endif // VEC_OPERATORS_HPP
