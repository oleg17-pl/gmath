#ifndef GMATH_MAT2X2_HPP
#define GMATH_MAT2X2_HPP

#include "mat_base.hpp"

GMATH_START

namespace Mat {

template <typename T = default_mat_type>
using mat2x2 = mat_base<2, 2, T>;

template <typename T = default_mat_type>
using mat2 = mat2x2<T>;

}

GMATH_END

#endif // GMATH_MAT2X2_HPP
