#ifndef GMATH_VEC_OPERATORS_HPP
#define GMATH_VEC_OPERATORS_HPP

#include "classes/vec_base.hpp"
#include "../../constants.hpp"

GMATH_START

namespace Vec {

#define GENERATE_VEC_PARAM_APPLY_OPERATOR_VEC(param_ch) \
\
    template <length_t n, typename T> \
    vec_base<n, T> &vec_base<n, T>::operator param_ch##=( \
        const vec_base<n, T> &other \
    ) { \
        for (std::size_t i{}; i < n; ++i) { \
            this->at(i) += other.at(i); \
        } \
        return *this; \
    }

#define GENERATE_NUM_PARAM_APPLY_OPERATOR_VEC(param_ch) \
\
    template <length_t n, typename T> \
    vec_base<n, T> &vec_base<n, T>::operator param_ch##=( \
        const double num \
    ) { \
        for (std::size_t i{}; i < n; ++i) { \
            this->at(i) param_ch##= num; \
        } \
        return *this; \
    }

#define GENERATE_VEC_PARAM_OPERATOR_VEC(param_ch) \
\
    template <std::size_t n, typename T> \
    [[ nodiscard ]] \
    vec_base<n, T> \
    vec_base<n, T>::operator param_ch( \
        const vec_base<n, T> &other \
    ) { \
        vec_base<n, T> tmp{ *this }; \
        return tmp param_ch##= other; \
    }

#define GENERATE_NUM_PARAM_OPERATOR_VEC(param_ch) \
\
    template <std::size_t n, typename T> \
    [[ nodiscard ]] \
    vec_base<n, T> \
    vec_base<n, T>::operator param_ch( \
        const double other \
    ) { \
        vec_base<n, T> tmp{ *this }; \
        return tmp param_ch##= other; \
    }

GENERATE_VEC_PARAM_APPLY_OPERATOR_VEC(+)
GENERATE_VEC_PARAM_APPLY_OPERATOR_VEC(-)
GENERATE_NUM_PARAM_APPLY_OPERATOR_VEC(*)
GENERATE_NUM_PARAM_APPLY_OPERATOR_VEC(/)

GENERATE_VEC_PARAM_OPERATOR_VEC(+)
GENERATE_VEC_PARAM_OPERATOR_VEC(-)
GENERATE_NUM_PARAM_OPERATOR_VEC(*)
GENERATE_NUM_PARAM_OPERATOR_VEC(/)

template <length_t n, typename T>
[[ nodiscard ]]
bool vec_base<n, T>::operator==(const vec_base<n, T> &other) {
    for (std::size_t i{}; i < n; ++i) {
        if ((this->at(i) - other.at(i)) > Constants::EPS) {
            return false;
        }
    }
    return true;
}

template <length_t n, typename T>
[[ nodiscard ]]
bool vec_base<n, T>::operator!=(const vec_base<n, T> &other) {
    return !(*this == other);
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
