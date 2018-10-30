cmake_minimum_required (VERSION 3.9)

project(MiniDuckSimulator CXX)

set (CMAKE_CXX_STANDARD 14)
set (CXX_STANDARD_REQUIRED 14)

set (CMAKE_CXX_FLAGS "-g -Og ${CMAKE_CXX_FLAGS}")

add_executable(ducksim main.cpp)

install (TARGETS ducksim DESTINATION ${CMAKE_CURRENT_LIST_DIR}/bin)
