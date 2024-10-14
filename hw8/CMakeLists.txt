cmake_minimum_required(VERSION 3.10)

#project name
project(PascalTriangle)

#set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#add the executable using pascal.cpp
add_executable(pascal pascal.cpp)
