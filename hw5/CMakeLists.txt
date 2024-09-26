#specify the minimum CMake version required
cmake_minimum_required(VERSION 3.10)

#set the project name
project(FizzBuzz)

#sdd the executable target (this will compile fizzbuzz.cpp)
add_executable(fizzbuzz fizzbuzz.cpp)

#set the output directory for the compiled binary
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
