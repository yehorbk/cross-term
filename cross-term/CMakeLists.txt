cmake_minimum_required(VERSION 3.16)
project(cross-term)

set(PROJECT_DIRECTORY src)

include_directories(${PROJECT_DIRECTORY})

file(GLOB_RECURSE HEADERS ${PROJECT_DIRECTORY}/*.hpp)
file(GLOB_RECURSE SOURCES ${PROJECT_DIRECTORY}/*.cpp")

add_executable(crossterm ${HEADERS} ${SOURCES})
