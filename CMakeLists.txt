cmake_minimum_required(VERSION 3.10)

project(Assignment)

file(GLOB SOURCES "*.cpp")

add_executable(Assignment ${SOURCES})
target_link_libraries(Assignment m)
