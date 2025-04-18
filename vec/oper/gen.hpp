#ifndef VEC_GEN_OPERS_HPP
#define VEC_GEN_OPERS_HPP

#define GENERATE_PARAM_APPLY_OPERATORS(param_ch, vec_size_num) \
\
    template <typename T> \
    vec##vec_size_num<T> \
    &operator param_ch##=( \
        vec##vec_size_num<T> &first, \
        const vec##vec_size_num<T> &second \
    ) { \
        for (std::size_t i{ 0 }; i < first.getSize(); ++i) { \
            first[i] param_ch##= second.value_ptr()[i]; \
        } \
        return first; \
    } \
\
    template <typename T> \
    vec##vec_size_num<T> \
    &operator param_ch##=( \
        vec##vec_size_num<T> &vec, \
        const double num \
    ) { \
        for (std::size_t i{ 0 }; i < vec.getSize(); ++i) { \
            vec[i] param_ch##= num; \
        } \
        return vec; \
    }

#define GENERATE_PARAM_OPERATORS(param_ch, vec_size_num) \
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
    } \
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

#define GENERATE_PARAM_APPLY_OPERATORS_ALL \
\
    GENERATE_PARAM_APPLY_OPERATORS(+, 2); \
    GENERATE_PARAM_APPLY_OPERATORS(+, 3); \
    GENERATE_PARAM_APPLY_OPERATORS(+, 4); \
\
    GENERATE_PARAM_APPLY_OPERATORS(-, 2); \
    GENERATE_PARAM_APPLY_OPERATORS(-, 3); \
    GENERATE_PARAM_APPLY_OPERATORS(-, 4); \
\
    GENERATE_PARAM_APPLY_OPERATORS(*, 2); \
    GENERATE_PARAM_APPLY_OPERATORS(*, 3); \
    GENERATE_PARAM_APPLY_OPERATORS(*, 4); \
\
    GENERATE_PARAM_APPLY_OPERATORS(/, 2); \
    GENERATE_PARAM_APPLY_OPERATORS(/, 3); \
    GENERATE_PARAM_APPLY_OPERATORS(/, 4);

#define GENERATE_PARAM_OPERATORS_ALL \
\
    GENERATE_PARAM_OPERATORS(+, 2); \
    GENERATE_PARAM_OPERATORS(+, 3); \
    GENERATE_PARAM_OPERATORS(+, 4); \
\
    GENERATE_PARAM_OPERATORS(-, 2); \
    GENERATE_PARAM_OPERATORS(-, 3); \
    GENERATE_PARAM_OPERATORS(-, 4); \
\
    GENERATE_PARAM_OPERATORS(*, 2); \
    GENERATE_PARAM_OPERATORS(*, 3); \
    GENERATE_PARAM_OPERATORS(*, 4); \
\
    GENERATE_PARAM_OPERATORS(/, 2); \
    GENERATE_PARAM_OPERATORS(/, 3); \
    GENERATE_PARAM_OPERATORS(/, 4);

#endif // VEC_GEN_OPERS_HPP
