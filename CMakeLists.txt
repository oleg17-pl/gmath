cmake_minimum_required(VERSION 3.16)

project(Math LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(MATRICES_PATH ./matrices)
set(VEC_PATH ./vec)

add_library (gmath INTERFACE

    ${MATRICES_PATH}/mat_base.hpp

    ${VEC_PATH}/classes/vec_base.hpp
    ${VEC_PATH}/classes/vec2.hpp
    ${VEC_PATH}/classes/vec3.hpp
    ${VEC_PATH}/classes/vec4.hpp
    ${VEC_PATH}/vec.hpp

    ${VEC_PATH}/funcs/f.hpp
)

target_include_directories(gmath INTERFACE .)
