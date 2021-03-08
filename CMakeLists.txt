cmake_minimum_required(VERSION 3.16)

project(main)

add_executable(main merged)

install(TARGETS main)

enable_testing()
add_test(NAME main COMMAND main)