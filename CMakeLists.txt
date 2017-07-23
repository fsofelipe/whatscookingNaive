cmake_minimum_required(VERSION 2.8.4)
project(whatscookingNaive)

set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c)
add_executable(naive ${SOURCE_FILES})