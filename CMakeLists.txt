cmake_minimum_required(VERSION 3.5)
project(frequencycount)

set(CMAKE_CXX_STANDARD 11)

add_executable(frequencycount cpp/main.cpp cpp/FrequencyCountTest.cpp cpp/FrequencyCount.cpp cpp/FrequencyCount.h)