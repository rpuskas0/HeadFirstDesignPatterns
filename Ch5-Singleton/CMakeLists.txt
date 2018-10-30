cmake_minimum_required (VERSION 3.9)

project(ChocolateBoiler CXX)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED 17)

set (CMAKE_CXX_FLAGS "-g -Og ${CMAKE_CXX_FLAGS}")

add_executable (boiler main.cpp chocoboiler.cpp)

