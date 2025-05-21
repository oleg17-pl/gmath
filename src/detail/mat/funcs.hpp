#ifndef GMATH_MAT_FUNCS_HPP
#define GMATH_MAT_FUNCS_HPP

#include "classes/mat_base.hpp"
#include "../../constants.hpp"

GMATH_START

namespace Mat {

template <length_t size, typename T = default_mat_type>
[[ nodiscard ]]
mat_base<size, size, T> get_single() {
    mat_base<size, size, T> mat;
    for (std::size_t i{}; i < size; ++i) {
        mat.at(i, i) = 1;
    }
    return mat;
}

template <length_t rows, length_t colums, typename T>
[[ nodiscard ]]
mat_base<colums, rows, T> transpose(const mat_base<rows, colums, T> &mat) {
    mat_base<colums, rows, T> result;
    for (std::size_t y{}; y < rows; ++y) {
        for (std::size_t x{}; x < colums; ++x) {
            result.at(x, y) = mat.at(y, x);
        }
    }
    return result;
}

template <length_t rows, length_t colums, typename T>
[[ nodiscard ]]
mat_base<colums - 1, rows - 1, T> get_minor(
    const mat_base<rows, colums, T> &mat,
    const length_t y,
    const length_t x
) {
    if (rows < 3 || colums < 3) {
        throw std::invalid_argument("Colums and rows of mat must be > 2! Mat::get_minor()");
    }
    mat_base<colums - 1, rows - 1, T> result;
    bool skipped_y{};
    for (std::size_t iy{}; iy < rows; ++iy) {
        if (iy == y) {
            skipped_y = true;
            continue;
        }
        bool skipped_x{};
        for (std::size_t ix{}; ix < colums; ++ix) {
            if (ix == x) {
                skipped_x = true;
                continue;
            }
            std::size_t minor_y{ skipped_y ? iy - 1 : iy };
            std::size_t minor_x{ skipped_x ? ix - 1 : ix };
            result.at(minor_y, minor_x) = mat.at(iy, ix);
        }
    }
    return result;
}

template <length_t size, typename T>
[[ nodiscard ]]
double get_determinant(const mat_base<size, size, T> &mat) {
    if constexpr (size == 2) {
        return(
            mat.at(0, 0) * mat.at(1, 1) -
            mat.at(1, 0) * mat.at(0, 1)
        );
    }
    else {
        double result{};
        for (std::size_t i{}; i < size; ++i) {
            mat_base<size - 1, size - 1, T> minor{ get_minor(mat, 0, i) };
            T el{ mat.at(0, i) };

            double solved_minor{ el * get_determinant(minor) };
            if (i % 2 != 0) {
                solved_minor *= -1;
            }
            result += solved_minor;
        }
        return result;
    }
}

template <length_t size, typename T>
[[ nodiscard ]]
mat_base<size, size, T> inverse(const mat_base<size, size, T> &mat) {
    double det{ get_determinant(mat) };
    if (std::abs(det) < Constants::EPS) {
        throw std::domain_error("Determinant of matrix must be > 0! Mat::inverse()");
    }

    mat_base<size, size, T> A;
    for (std::size_t y{}; y < size; ++y) {
        for (std::size_t x{}; x < size; ++x) {
            double el;
            if constexpr (size > 2) {
                el = get_determinant(get_minor(mat, y, x));
            }
            else {
                std::size_t el_y{ y == 0 ? y + 1 : y - 1 };
                std::size_t el_x{ x == 0 ? x + 1 : x - 1 };
                el = mat.at(el_y, el_x);
            }
            if (y % 2 != 0) {
                el *= -1;
            }
            if (x % 2 != 0) {
                el *= -1;
            }
            A.at(x, y) = el; // transposed
        }
    }
    return A / det;
}

}

GMATH_END

#endif // GMATH_MAT_FUNCS_HPP
