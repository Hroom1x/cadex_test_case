cmake_minimum_required(VERSION 3.6)
project(cadex_test_case)

set(CMAKE_CXX_STANDARD 17)
set(COMPILE_FLAGS "-Wall -Werror -Wpedantic -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}")
set(SRCS ${PROJECT_SOURCE_DIR}/src/main.cpp
        ${PROJECT_SOURCE_DIR}/src/curves.cpp
        ${PROJECT_SOURCE_DIR}/src/parallel.cpp
        ${PROJECT_SOURCE_DIR}/src/random_filler.cpp
        ${PROJECT_SOURCE_DIR}/src/utility.cpp)

add_executable(cadex_test_case ${SRCS})

target_include_directories(cadex_test_case PUBLIC ${PROJECT_SOURCE_DIR}/include)
