cmake_minimum_required(VERSION 3.16)

project(libvec VERSION 1.0.0 LANGUAGES C)

set_property(GLOBAL PROPERTY C_STANDARD 11)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_library(vec 
    src/vec.c
)

add_executable(Main 
    src/main.c
    src/test.c
)

target_include_directories(vec
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)


target_link_libraries(Main PRIVATE vec)
