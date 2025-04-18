#ifndef VEC_BASE_H
#define VEC_BASE_H

#include <array>
#include <cmath>
#include <stdexcept>

using vec_default_type = float;

template <std::size_t n, typename T = vec_default_type>
struct vec_base {
protected:
    std::array<T, n> els;
public:

    vec_base() : els{} {
        if (n < 2) {
            const char msg[]{
                "Count of vector elements must be >= 2! vec_base::n"
            };
            throw std::invalid_argument(msg);
        }
    }

    [[ nodiscard ]]
    const T *value_ptr() const {
        return els.data();
    }

    [[ nodiscard ]]
    std::size_t getSize() const {
        return n;
    }

    [[ nodiscard ]]
    float getLen() const {
        T sum_els_sqrs{};
        for (T el : els) {
            sum_els_sqrs += el * el;
        }
        return sqrt(sum_els_sqrs);
    }

    T &operator[](const std::size_t index) {
        if (index >= n) {
            const char msg[]{
                "Index of vec is out of range! vec_base::operator[]::index"
            };
            throw std::out_of_range(msg);
        }
        return els.at(index);
    }
};

#endif // VEC_BASE_H
