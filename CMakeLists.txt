cmake_minimum_required(VERSION 3.8)
project(gba_emulator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")

add_subdirectory(core)
add_subdirectory(platform/desktop)

