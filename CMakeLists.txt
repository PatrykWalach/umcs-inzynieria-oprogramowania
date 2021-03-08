cmake_minimum_required(VERSION 3.16)

project(main)

file(GLOB SOURCES src/*.cpp)

add_executable(main ${SOURCES})

install(TARGETS main)

enable_testing()
add_test(NAME main COMMAND main)