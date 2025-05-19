#ifndef GMATH_MAT4X4_HPP
#define GMATH_MAT4X4_HPP

#include "mat_base.hpp"

GMATH_START

namespace Mat {

template <typename T = default_mat_type>
using mat4x4 = mat_base<4, 4, T>;

template <typename T = default_mat_type>
using mat4 = mat4x4<T>;

}

GMATH_END

#endif // GMATH_MAT4X4_HPP
