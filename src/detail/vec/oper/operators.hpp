#ifndef GMATH_VEC_OPERATORS_HPP
#define GMATH_VEC_OPERATORS_HPP

#include <ostream>

#include "../../../setup.hpp"
#include "../../../constants.hpp"

#include "gen.hpp"

GMATH_START

namespace Vec {

GENERATE_VEC_PARAM_APPLY_OPERATORS_ALL
GENERATE_VEC_PARAM_OPERATORS_ALL

template <length_t n, typename T>
[[ nodiscard ]] bool operator==(const vec_base<n, T> &first, const vec_base<n, T> &second) {
    for (std::size_t i{}; i < n; ++i) {
        if ((first[i] - second[i]) > Constants::EPS) {
            return false;
        }
    }
    return true;
}

template <length_t n, typename T>
[[ nodiscard ]] bool operator!=(const vec_base<n, T> &first, const vec_base<n, T> &second) {
    return !(first == second);
}

template <length_t n, typename T>
std::ostream &operator<<(std::ostream &os, const vec_base<n, T> &vec) {
    for (std::size_t i{}; i < vec.getSize(); ++i) {
        os << vec[i] << " ";
    }
    os << std::endl;
    return os;
}

}

GMATH_END

#endif // GMATH_VEC_OPERATORS_HPP
