cmake_minimum_required(VERSION 2.8.4)
project(whatscookingNaive)


set(SOURCE_FILES main.c jsonParser.c)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -l json")

add_executable(naive ${SOURCE_FILES})
TARGET_LINK_LIBRARIES(naive /lib/x86_64-linux-gnu/libjson.so.0)
