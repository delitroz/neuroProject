cmake_minimum_required(VERSION 2.6)
project(Neuro)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -std=c++11")

enable_testing()
add_subdirectory(gtest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(test1 test1.cpp neuron.cpp)

add_executable(main main.cpp network.cpp neuron.cpp)

add_executable(unittest unittest.cpp neuron.cpp network.cpp)
target_link_libraries(unittest gtest)
add_test(unittest unittest)




