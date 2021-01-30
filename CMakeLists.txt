cmake_minimum_required(VERSION 3.17)
project(MatrixTemplate)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(test)

set(SOURCE_FILES main.cpp Matrix.h)
add_executable(Matrix ${SOURCE_FILES})
add_library(core ${SOURCE_FILES})
target_link_libraries(Matrix core)