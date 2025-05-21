#ifndef GMATH_MAT_OPERATORS_HPP
#define GMATH_MAT_OPERATORS_HPP

#include <ostream>

#include "classes/mat_base.hpp"
#include "../vec/classes/vec_base.hpp"

GMATH_START

namespace Mat {

#define GENERATE_MAT_PARAM_APPLY_OPERATOR_MAT(param_ch) \
\
    template <length_t rows, length_t colums, typename T> \
    mat_base<rows, colums, T> &mat_base<rows, colums, T>::operator param_ch##=( \
        const mat_base<rows, colums, T> &other \
    ) { \
        for (std::size_t y{}; y < rows; ++y) { \
            for (std::size_t x{}; x < colums; ++x) { \
                this->at(y, x) param_ch##= other.at(y, x); \
            } \
        } \
        return *this; \
    }

#define GENERATE_NUM_PARAM_APPLY_OPERATOR_MAT(param_ch) \
\
    template <length_t rows, length_t colums, typename T> \
    mat_base<rows, colums, T> &mat_base<rows, colums, T>::operator param_ch##=( \
        const double other \
    ) { \
        for (std::size_t y{}; y < rows; ++y) { \
            for (std::size_t x{}; x < colums; ++x) { \
                this->at(y, x) param_ch##= other; \
            } \
        } \
        return *this; \
    }

#define GENERATE_MAT_PARAM_OPERATOR_MAT(param_ch) \
\
    template <length_t rows, length_t colums, typename T> \
    [[ nodiscard ]] \
    mat_base<rows, colums, T> mat_base<rows, colums, T>::operator param_ch( \
        const mat_base<rows, colums, T> &other \
    ) { \
        mat_base<rows, colums, T> tmp{ *this }; \
        return (tmp param_ch##= other); \
    }

#define GENERATE_NUM_PARAM_OPERATOR_MAT(param_ch) \
\
    template <length_t rows, length_t colums, typename T> \
    [[ nodiscard ]] \
    mat_base<rows, colums, T> mat_base<rows, colums, T>::operator param_ch( \
        const double other \
    ) { \
        mat_base<rows, colums, T> tmp{ *this }; \
        return (tmp param_ch##= other); \
    }

GENERATE_MAT_PARAM_APPLY_OPERATOR_MAT(+)
GENERATE_MAT_PARAM_APPLY_OPERATOR_MAT(-)
GENERATE_NUM_PARAM_APPLY_OPERATOR_MAT(*)
GENERATE_NUM_PARAM_APPLY_OPERATOR_MAT(/)

GENERATE_MAT_PARAM_OPERATOR_MAT(+)
GENERATE_MAT_PARAM_OPERATOR_MAT(-)
GENERATE_NUM_PARAM_OPERATOR_MAT(*)
GENERATE_NUM_PARAM_OPERATOR_MAT(/)

template <length_t Y, length_t X, length_t K, typename T>
[[ nodiscard ]]
mat_base<Y, X, T> operator*(
    const mat_base<Y, K, T> &first,
    const mat_base<K, X, T> &second
) {
    mat_base<Y, X, T> result;
    for (std::size_t y{}; y < Y; ++y) {
        for (std::size_t x{}; x < X; ++x) {
            T &result_el{ result.at(y, x) };
            for (std::size_t k{}; k < K; ++k) {
                result_el += first.at(y, k) * second.at(k, x);
            }
        }
    }
    return result;
}

template <length_t Y, length_t K, typename T>
[[ nodiscard ]]
Vec::vec_base<Y, T> operator*(
    const mat_base<Y, K, T> &first,
    const Vec::vec_base<K, T> &second
) {
    Vec::vec_base<Y, T> result;
    for (std::size_t y{}; y < Y; ++y) {
        T &result_el{ result.at(y) };
        for (std::size_t k{}; k < K; ++k) {
            result_el += first.at(y, k) * second.at(k);
        }
    }
    return result;
}

template <length_t K, length_t X, typename T>
[[ nodiscard ]]
Vec::vec_base<X, T> operator*(
    const Vec::vec_base<K, T> &first,
    const mat_base<K, X, T> &second
) {
    Vec::vec_base<X, T> result;
    for (std::size_t x{}; x < X; ++x) {
        T &result_el{ result.at(x) };
        for (std::size_t k{}; k < K; ++k) {
            result_el += first.at(k) * second.at(k, x);
        }
    }
    return result;
}

template <length_t rows, length_t colums, typename T>
std::ostream &operator<<(std::ostream &os, const mat_base<rows, colums, T> &mat) {
    for (std::size_t y{}; y < rows; ++y) {
        for (std::size_t x{}; x < colums; ++x) {
            os << mat.at(y, x) << " ";
        }
        os << std::endl;
    }
    return os;
}

}

GMATH_END

#endif // GMATH_MAT_OPERATORS_HPP
