#ifndef GMATH_VEC_GEN_OPERS_HPP
#define GMATH_VEC_GEN_OPERS_HPP

#include "../../../setup.hpp"
#include "../../../constants.hpp"

#include "../classes/vec2.hpp"
#include "../classes/vec3.hpp"
#include "../classes/vec4.hpp"

GMATH_START

namespace Vec {

#define GENERATE_VEC_PARAM_APPLY_OPERATOR_VEC(param_ch, vec_size_num) \
\
    template <typename T> \
    vec##vec_size_num<T> \
    &operator param_ch##=( \
        vec##vec_size_num<T> &first, \
        const vec##vec_size_num<T> &second \
    ) { \
        for (std::size_t i{}; i < vec_size_num; ++i) { \
            first[i] param_ch##= second[i]; \
        } \
        return first; \
    }

#define GENERATE_NUM_PARAM_APPLY_OPERATOR_VEC(param_ch, vec_size_num) \
\
    template <typename T> \
    vec##vec_size_num<T> \
    &operator param_ch##=( \
        vec##vec_size_num<T> &vec, \
        const double num \
    ) { \
        for (std::size_t i{}; i < vec_size_num; ++i) { \
            vec[i] param_ch##= num; \
        } \
        return vec; \
    }

#define GENERATE_VEC_PARAM_OPERATOR_VEC(param_ch, vec_size_num) \
\
    template <typename T> \
    [[ nodiscard ]] \
    vec##vec_size_num<T> \
    &operator param_ch( \
        const vec##vec_size_num<T> &first, \
        const vec##vec_size_num<T> &second \
    ) { \
        vec##vec_size_num tmp{ first }; \
        return tmp param_ch##= second; \
    }

#define GENERATE_NUM_PARAM_OPERATOR_VEC(param_ch, vec_size_num) \
\
    template <typename T> \
    [[ nodiscard ]] \
    vec##vec_size_num<T> \
    &operator param_ch( \
        const vec##vec_size_num<T> &vec, \
        const double num \
    ) { \
        vec##vec_size_num tmp{ vec }; \
        return tmp param_ch##= num; \
    }

#define GENERATE_VEC_PARAM_APPLY_OPERATORS_ALL \
\
    GENERATE_VEC_PARAM_APPLY_OPERATOR_VEC(+, 2) \
    GENERATE_VEC_PARAM_APPLY_OPERATOR_VEC(+, 3) \
    GENERATE_VEC_PARAM_APPLY_OPERATOR_VEC(+, 4) \
\
    GENERATE_VEC_PARAM_APPLY_OPERATOR_VEC(-, 2) \
    GENERATE_VEC_PARAM_APPLY_OPERATOR_VEC(-, 3) \
    GENERATE_VEC_PARAM_APPLY_OPERATOR_VEC(-, 4) \
\
    GENERATE_NUM_PARAM_APPLY_OPERATOR_VEC(*, 2) \
    GENERATE_NUM_PARAM_APPLY_OPERATOR_VEC(*, 3) \
    GENERATE_NUM_PARAM_APPLY_OPERATOR_VEC(*, 4) \
\
    GENERATE_NUM_PARAM_APPLY_OPERATOR_VEC(/, 2) \
    GENERATE_NUM_PARAM_APPLY_OPERATOR_VEC(/, 3) \
    GENERATE_NUM_PARAM_APPLY_OPERATOR_VEC(/, 4)

#define GENERATE_VEC_PARAM_OPERATORS_ALL \
\
    GENERATE_VEC_PARAM_OPERATOR_VEC(+, 2) \
    GENERATE_VEC_PARAM_OPERATOR_VEC(+, 3) \
    GENERATE_VEC_PARAM_OPERATOR_VEC(+, 4) \
\
    GENERATE_VEC_PARAM_OPERATOR_VEC(-, 2) \
    GENERATE_VEC_PARAM_OPERATOR_VEC(-, 3) \
    GENERATE_VEC_PARAM_OPERATOR_VEC(-, 4) \
\
    GENERATE_NUM_PARAM_OPERATOR_VEC(*, 2) \
    GENERATE_NUM_PARAM_OPERATOR_VEC(*, 3) \
    GENERATE_NUM_PARAM_OPERATOR_VEC(*, 4) \
\
    GENERATE_NUM_PARAM_OPERATOR_VEC(/, 2) \
    GENERATE_NUM_PARAM_OPERATOR_VEC(/, 3) \
    GENERATE_NUM_PARAM_OPERATOR_VEC(/, 4)

}

GMATH_END

#endif // GMATH_VEC_GEN_OPERS_HPP
