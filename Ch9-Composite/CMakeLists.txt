cmake_minimum_required (VERSION 3.9)

project(DinerMerger2 CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED 14)

set (CMAKE_CXX_FLAGS "-g -Og ${CMAKE_CXX_FLAGS}")

add_executable(diner2 main.cpp menu.cpp)
