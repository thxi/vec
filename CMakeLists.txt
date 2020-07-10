cmake_minimum_required(VERSION 3.16)

project(libvec VERSION 1.0.0 LANGUAGES C)

set_property(GLOBAL PROPERTY C_STANDARD 11)
set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")
set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -fsanitize=address -fsanitize=undefined")

add_library(vec 
    src/vec.c
)

add_executable(vec_test 
    src/test/main.c
    src/test/test.c
)

target_include_directories(vec
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)


target_link_libraries(vec_test PRIVATE vec)


install(
    TARGETS vec
    ARCHIVE
)

install(
    DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
    DESTINATION include
)