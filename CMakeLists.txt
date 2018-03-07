cmake_minimum_required(VERSION 3.5)
project(frequencycount)

set(CMAKE_CXX_STANDARD 11)

add_executable(frequencycount cpp/main.cpp)
add_executable(frequencycount_test cpp/MainTest.cpp cpp/catch.hpp)