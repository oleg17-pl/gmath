cmake_minimum_required(VERSION 3.16)

project(Math LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(INCLUDE_PATH ./include)
set(SRC_PATH ./src)

set(MAT_PATH ${SRC_PATH}/detail/mat)
set(VEC_PATH ${SRC_PATH}/detail/vec)

add_library(gmath INTERFACE

    ${SRC_PATH}/setup.hpp
    ${SRC_PATH}/constants.hpp

    #####################################

    ${VEC_PATH}/classes/vec_base.hpp
    ${VEC_PATH}/classes/vec2.hpp
    ${VEC_PATH}/classes/vec3.hpp
    ${VEC_PATH}/classes/vec4.hpp

    ${VEC_PATH}/oper/gen.hpp
    ${VEC_PATH}/oper/operators.hpp
    ${VEC_PATH}/funcs.hpp

    #####################################

    ${MAT_PATH}/classes/mat_base.hpp
    ${MAT_PATH}/classes/mat2x2.hpp
    ${MAT_PATH}/classes/mat3x3.hpp
    ${MAT_PATH}/classes/mat4x4.hpp

    ${MAT_PATH}/operators.hpp
    ${MAT_PATH}/funcs.hpp

    #####################################

    ${INCLUDE_PATH}/vec.hpp
    ${INCLUDE_PATH}/mat.hpp
)
