cmake_minimum_required(VERSION 3.20)
project(homework4 VERSION 1.0)

#print a message indicating the source file used
message("Using sources: newton_rootfd_hw.cpp")

#add an executable target named 'homework4'
add_executable(homework4 newton_rootfd_hw.cpp)

#specify the C++ standard to use
target_compile_features(homework4 PRIVATE cxx_std_17)

