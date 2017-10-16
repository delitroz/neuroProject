cmake_minimum_required(VERSION 2.6)
project(Neuro)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -std=c++11")
add_executable(neurotest1 neuron.cpp test1.cpp)
add_executable(neurotest2 neuron.cpp test2.cpp)
