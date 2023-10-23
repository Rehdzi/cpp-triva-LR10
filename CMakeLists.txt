cmake_minimum_required(VERSION 3.26)
project(LR10)

set(CMAKE_CXX_STANDARD 17)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(LR10 main.cpp)
target_link_libraries(LR10 ${CURSES_LIBRARIES})
