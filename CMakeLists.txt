cmake_minimum_required(VERSION 3.16)

project(main)

file(GLOB SOURCES util.cpp Model/*.cpp main.cpp)

add_executable(main ${SOURCES})

install(TARGETS main)

enable_testing()
add_test(NAME main COMMAND main)