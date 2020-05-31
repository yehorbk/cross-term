cmake_minimum_required(VERSION 3.16)
project(cross-term)

include_directories(src)

set(SOURCES src/main.cpp)
file(GLOB SOURCES "src/**/*.cpp")
file(GLOB LIBS "src/lib/**/*.cpp")

add_executable(crossterm ${SOURCES} ${LIBS})
