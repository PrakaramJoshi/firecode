cmake_minimum_required(VERSION 3.5)

project(firecode LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(firecode main.cpp making_change.cpp recursive_string_permutations.cpp codebase.cpp 1_800_problem.cpp)
