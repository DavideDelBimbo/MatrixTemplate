cmake_minimum_required(VERSION 3.17)

add_subdirectory(./lib/googletest-master)
set(gtest_SOURCE_DIR, ./lib/googletest-master/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(SOURCE_TEST_FILES runAllTest.cpp MatrixTemplateTests.cpp)
add_executable(runMatrixTemplateTests ${SOURCE_TEST_FILES})
target_link_libraries(runMatrixTemplateTests gtest gtest_main core)