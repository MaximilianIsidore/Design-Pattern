cmake_minimum_required(VERSION 3.14)
project(BenchmarkExample)

set(CMAKE_CXX_STANDARD 14)

# Set the path to Google Benchmark build folder
set(BENCHMARK_DIR "H:/cpp-roadmap/Design-Pattern/Hands-On-Design-Patterns-with-CPP-book/Chapter_01/benchmark/build")

# Make CMake find the benchmark package
list(APPEND CMAKE_PREFIX_PATH "${BENCHMARK_DIR}")
find_package(benchmark REQUIRED)

add_executable(benchmark_example 02_dynamic_cast.cpp)

# Link benchmark library
target_link_libraries(benchmark_example benchmark::benchmark)
