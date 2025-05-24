#ifndef GMATH_MAT_BASE_HPP
#define GMATH_MAT_BASE_HPP

#include <array>
#include <stdexcept>

#include "../../../setup.hpp"

GMATH_START

namespace Mat {

using default_mat_type = double;

template<length_t rows, length_t colums, typename T = default_mat_type>
using mat_data_t = std::array<std::array<T, colums>, rows>;

template<length_t rows, length_t colums, typename T = default_mat_type>
struct mat_base {
private:
    mat_data_t<rows, colums, T> m_els;
public:
    mat_base() : m_els{} {
        if (rows < 2 || colums < 2) {
            static const char msg[]{
                "Rows and colums quantity must be >= 2! mat_base::rows, mat_base::colums"
            };
            throw std::invalid_argument(msg);
        }
    }

    explicit mat_base(const mat_data_t<rows, colums, T> &els) : mat_base() {
        m_els = els;
    }

    explicit mat_base(const T val) : mat_base() {
        for (auto &row : m_els) {
            for (T &el : row) {
                el = val;
            }
        }
    }

    [[ nodiscard ]]
    static mat_base<rows, colums, T> get_single() {
        if (rows != colums) {
            static const char msg[]{
                "Cant get non square single matrix! mat_base::get_single()"
            };
            throw std::domain_error(msg);
        }
        mat_base<rows, colums, T> mat;
        for (std::size_t i{}; i < rows; ++i) {
            mat.at(i, i) = 1;
        }
        return mat;
    }

    std::array<length_t, 2> getSize() const {
        return { colums, rows };
    }

    [[ nodiscard ]]
    T &at(const std::size_t y, const std::size_t x) {
        return m_els[y][x];
    }

    [[ nodiscard ]]
    const T &at(const std::size_t y, const std::size_t x) const {
        return m_els[y][x];
    }

    mat_base<rows, colums, T> &operator+=(const mat_base<rows, colums, T> &other);
    mat_base<rows, colums, T> &operator-=(const mat_base<rows, colums, T> &other);
    mat_base<rows, colums, T> &operator*=(const double other);
    mat_base<rows, colums, T> &operator/=(const double other);

    [[ nodiscard ]] mat_base<rows, colums, T> operator+(const mat_base<rows, colums, T> &other);
    [[ nodiscard ]] mat_base<rows, colums, T> operator-(const mat_base<rows, colums, T> &other);
    [[ nodiscard ]] mat_base<rows, colums, T> operator*(const double other);
    [[ nodiscard ]] mat_base<rows, colums, T> operator/(const double other);
};

}

GMATH_END

#endif // GMATH_MAT_BASE_HPP
