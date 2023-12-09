cmake_minimum_required(VERSION 3.22)

set(SOURCE_EXE main.cpp)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input.txt ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
add_executable(airline-project ${SOURCE_EXE})
