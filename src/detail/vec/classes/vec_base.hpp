#ifndef GMATH_VEC_BASE_H
#define GMATH_VEC_BASE_H

#include <array>
#include <stdexcept>

#include "../../../setup.hpp"

GMATH_START

namespace Vec {

using vec_default_type = double;

template <length_t n, typename T = vec_default_type>
using vec_data_t = std::array<T, n>;

template <length_t n, typename T = vec_default_type>
struct vec_base {
private:
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
};

}

GMATH_END

#endif // GMATH_VEC_BASE_H
