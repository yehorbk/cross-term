cmake_minimum_required(VERSION 3.16)
project(cross-term)

include_directories("src" "src/*" "src/lib/*")

set(MAIN "src/main.cpp" "src/main.hpp")

file(GLOB HEADERS "src/**/*.hpp")
file(GLOB SOURCES "src/**/*.cpp")
file(GLOB LIBS "src/lib/**/*.hpp" "src/lib/**/*.cpp")

add_executable(crossterm ${LIBS} ${HEADERS} ${SOURCES} ${MAIN})
