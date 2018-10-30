cmake_minimum_required (VERSION 3.9)

project(RemoteControl CXX)

set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_STANDARD_REQUIRED 14)

set (CMAKE_CXX_FLAGS "-g -Og ${CMAKE_CXX_FLAGS}")

add_executable (remote_test main.cpp appliances.cpp command.cpp simpleremote.cpp ) 
