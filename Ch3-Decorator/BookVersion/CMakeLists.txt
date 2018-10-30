cmake_minimum_required (VERSION 3.9)

project (Starbuzz CXX)

set (CMAKE_CXX_STANDARD 14)
set (CXX_STANDARD_REQUIRED 14)

set (CMAKE_CXX_FLAGS "-g -Og ${CMAKE_CXX_FLAGS}")

add_executable (starbuzz main.cpp drinks.cpp condiments.cpp beverage.cpp)

install (TARGETS starbuzz DESTINATION ${CMAKE_CURRENT_LIST_DIR}/bin)
