#ifndef GMATH_VEC_BASE_H
#define GMATH_VEC_BASE_H

#include <ostream>
#include <stdexcept>
#include <array>

#include "../../../setup.hpp"

GMATH_START

namespace Vec {

using vec_default_type = double;

template <length_t n, typename T = vec_default_type>
using vec_data_t = std::array<T, n>;

template <length_t n, typename T = vec_default_type>
struct vec_base {
protected:
    vec_data_t<n, T> m_els;
public:

    vec_base() : m_els{} {
        if (n < 2) {
            const char msg[]{
                "Count of vector elements must be >= 2! vec_base::n"
            };
            throw std::invalid_argument(msg);
        }
    }

    explicit vec_base(const vec_data_t<n, T> &els) : vec_base() {
        m_els = els;
    }

    explicit vec_base(const T val) : vec_base() {
        for (T &el : m_els) {
            el = val;
        }
    }

    [[ nodiscard ]]
    T &at(const std::size_t index) {
        return m_els.at(index);
    }

    [[ nodiscard ]]
    const T &at(const std::size_t index) const {
        return m_els.at(index);
    }

    [[ nodiscard ]]
    std::size_t getSize() const {
        return n;
    }

    [[ nodiscard ]]
    T &operator[](const std::size_t index) {
        return at(index);
    }

    [[ nodiscard ]]
    const T &operator[](const std::size_t index) const {
        return at(index);
    }

    vec_base<n, T> &operator+=(const vec_base<n, T> &other);
    vec_base<n, T> &operator-=(const vec_base<n, T> &other);
    vec_base<n, T> &operator*=(const double other);
    vec_base<n, T> &operator/=(const double other);

    [[ nodiscard ]] vec_base<n, T> operator+(const vec_base<n, T> &other);
    [[ nodiscard ]] vec_base<n, T> operator-(const vec_base<n, T> &other);
    [[ nodiscard ]] vec_base<n, T> operator*(const double other);
    [[ nodiscard ]] vec_base<n, T> operator/(const double other);

    [[ nodiscard ]] bool operator==(const vec_base<n, T> &other);
    [[ nodiscard ]] bool operator!=(const vec_base<n, T> &other);
};

template <length_t n, typename T>
std::ostream &operator<<(std::ostream &os, const vec_base<n, T> &vec);

}

GMATH_END

#endif // GMATH_VEC_BASE_H
