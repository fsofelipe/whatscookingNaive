cmake_minimum_required(VERSION 2.8.4)
project(whatscookingNaive)

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "/home/matheus/Desktop/Faculdade/IPPD/whatscookingNaive/Parallel")

set(SOURCE_FILES main.c jsonParser.c cuisine.c naive_bayes.c cronometro.c hash_table.c)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -l json ")

add_executable(naive ${SOURCE_FILES})
TARGET_LINK_LIBRARIES(naive /lib/x86_64-linux-gnu/libjson.so.0)
target_link_libraries(naive m)