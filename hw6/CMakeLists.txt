cmake_minimum_required(VERSION 3.10)
project(PerfNumProject)

# Use C++20 standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(perfNum ../perfNum.cpp)  # Adjust path if needed
