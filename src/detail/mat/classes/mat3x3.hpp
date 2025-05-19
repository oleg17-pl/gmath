#ifndef GMATH_MAT3X3_HPP
#define GMATH_MAT3X3_HPP

#include "mat_base.hpp"

GMATH_START

namespace Mat {

template <typename T = default_mat_type>
using mat3x3 = mat_base<3, 3, T>;

template <typename T = default_mat_type>
using mat3 = mat3x3<T>;

}

GMATH_END

#endif // GMATH_MAT3X3_HPP
