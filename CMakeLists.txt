cmake_minimum_required(VERSION 3.10)

project(CXXDSA)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

find_package(GTest REQUIRED)

add_subdirectory(src)
add_subdirectory(tests)