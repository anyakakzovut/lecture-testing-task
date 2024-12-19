cmake_minimum_required(VERSION 3.10)
project(stack)

set(GOOGLETEST_VERSION 1.15.2)
enable_testing()
add_subdirectory(googletest)
include_directories(googletest/include)

add_library(stack stack.cpp)
add_executable(tests tests.cpp)
target_link_libraries(tests PRIVATE gtest stack)

set(BENCHMARK_ENABLE_TESTING OFF)
add_subdirectory(benchmark)
include_directories(benchmark/include)

add_executable(benchmark benchmark.cpp)
target_link_libraries(bench PRIVATE benchmark::benchmark stack)

add_executable(main main.cpp)
target_link_libraries(main stack)