cmake_minimum_required(VERSION 3.16)
project(cross-term)

include_directories(src)

set(SOURCES src/main.cpp)
file(GLOB SOURCES "src/**/*.cpp")
 
add_executable(crossterm ${SOURCES})
