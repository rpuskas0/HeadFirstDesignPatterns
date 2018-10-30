cmake_minimum_required (VERSION 3.9)

project (WeatherStation CXX) 

set (CMAKE_CXX_STANDARD 14)
set (CXX_STANDARD_REQUIRED 14)

set (CMAKE_CXX_FLAGS "-g -Og ${CMAKE_CXX_FLAGS}")


add_executable (wstation main.cpp weatherdisplay.cpp weatherdata.cpp)

install (TARGETS wstation DESTINATION ${CMAKE_CURRENT_LIST_DIR}/bin)
