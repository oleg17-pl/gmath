#ifndef GMATH_MAT_OPERATORS_HPP
#define GMATH_MAT_OPERATORS_HPP

#include <ostream>

#include "../../setup.hpp"
#include "classes/mat2x2.hpp"
#include "classes/mat3x3.hpp"
#include "classes/mat4x4.hpp"

#include "../vec/classes/vec2.hpp"
#include "../vec/classes/vec3.hpp"
#include "../vec/classes/vec4.hpp"

GMATH_START

namespace Mat {

#define GENERATE_MAT_PARAM_APPLY_OPERATOR_MAT(param_ch) \
\
    template <length_t rows, length_t colums, typename T> \
    mat_base<rows, colums, T> operator param_ch##=( \
        mat_base<rows, colums, T> &first, \
        const mat_base<rows, colums, T> &second \
    ) { \
        for (std::size_t y{}; y < rows; ++y) { \
            for (std::size_t x{}; x < colums; ++x) { \
                first.at(y, x) param_ch##= second.at(y, x); \
            } \
        } \
        return first; \
    }

#define GENERATE_MAT_PARAM_OPERATOR_MAT(param_ch) \
\
    template <length_t rows, length_t colums, typename T> \
    [[ nodiscard ]] \
    mat_base<rows, colums, T> operator param_ch( \
        const mat_base<rows, colums, T> &first, \
        const mat_base<rows, colums, T> &second \
    ) { \
        mat_base<rows, colums, T> tmp{ first }; \
        return (tmp param_ch##= second); \
    }

#define GENERATE_NUM_PARAM_APPLY_OPERATOR_MAT(param_ch) \
\
    template <length_t rows, length_t colums, typename T> \
    mat_base<rows, colums, T> operator param_ch##=( \
        mat_base<rows, colums, T> &mat, \
        const double num \
    ) { \
        for (std::size_t y{}; y < rows; ++y) { \
            for (std::size_t x{}; x < colums; ++x) { \
                mat.at(y, x) param_ch##= num; \
            } \
        } \
        return mat; \
    }

#define GENERATE_NUM_PARAM_OPERATOR_MAT(param_ch) \
\
    template <length_t rows, length_t colums, typename T> \
    [[ nodiscard ]] \
    mat_base<rows, colums, T> operator param_ch( \
        const mat_base<rows, colums, T> &mat, \
        const double num \
    ) { \
        mat_base<rows, colums, T> tmp{ mat }; \
        return (tmp param_ch##= num); \
    }

#define GENERATE_MATVEC_MULTIPLY_OPERATOR_MAT(size_num) \
\
    template <typename T> \
    [[ nodiscard ]] \
    Vec::vec##size_num<T> operator*( \
        const mat##size_num<T> &first, \
        const Vec::vec##size_num<T> &second \
    ) { \
        Vec::vec##size_num<T> result{ second }; \
        for (std::size_t y{}; y < size_num; ++y) { \
            T &result_el{ result.at(y) }; \
            for (std::size_t k{}; k < size_num; ++k) { \
                result_el += first.at(y, k) * second.at(k); \
            } \
        } \
        return result; \
    }

#define GENERATE_VECMAT_MULTIPLY_OPERATOR_MAT(size_num) \
\
    template <typename T> \
    [[ nodiscard ]] \
    Vec::vec##size_num<T> operator*( \
        const Vec::vec##size_num<T> &first, \
        const mat##size_num<T> &second \
    ) { \
        Vec::vec##size_num<T> result{ first }; \
        for (std::size_t x{}; x < size_num; ++x) { \
            T &result_el{ result.at(x) }; \
            for (std::size_t k{}; k < size_num; ++k) { \
                result_el += first.at(k) * second.at(k, x); \
            } \
        } \
        return result; \
    }

GENERATE_MAT_PARAM_APPLY_OPERATOR_MAT(+)
GENERATE_MAT_PARAM_APPLY_OPERATOR_MAT(-)
GENERATE_MAT_PARAM_OPERATOR_MAT(+)
GENERATE_MAT_PARAM_OPERATOR_MAT(-)

GENERATE_NUM_PARAM_APPLY_OPERATOR_MAT(*)
GENERATE_NUM_PARAM_APPLY_OPERATOR_MAT(/)
GENERATE_NUM_PARAM_OPERATOR_MAT(*)
GENERATE_NUM_PARAM_OPERATOR_MAT(/)

GENERATE_MATVEC_MULTIPLY_OPERATOR_MAT(2)
GENERATE_MATVEC_MULTIPLY_OPERATOR_MAT(3)
GENERATE_MATVEC_MULTIPLY_OPERATOR_MAT(4)

GENERATE_VECMAT_MULTIPLY_OPERATOR_MAT(2)
GENERATE_VECMAT_MULTIPLY_OPERATOR_MAT(3)
GENERATE_VECMAT_MULTIPLY_OPERATOR_MAT(4)

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
