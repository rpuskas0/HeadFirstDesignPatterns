cmake_minimum_required (VERSION 3.9)

project (SimUDuck CXX)

set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_STANDARD_REQUIRED 14)

set (CMAKE_CXX_FLAGS "-g -Og ${CMAKE_CXX_FLAGS}")

set (SOURCES
     main.cpp
     adapters.cpp
     composite.cpp
     decorators.cpp
     ducks.cpp
     factories.cpp
     geese.cpp
     interfaces.cpp
     observables.cpp
     observers.cpp)

add_executable (simuduck ${SOURCES})
