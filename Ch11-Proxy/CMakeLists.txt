cmake_minimum_required (VERSION 3.9)

project (CDCoverViewer CXX)

set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_STANDARD_REQUIRED 14)

set (CMAKE_CXX_FLAGS "-g -Og ${CMAKE_CXX_FLAGS}")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_definitions(-DQT_DEPRECATED_WARNINGS)

find_package(Qt5 COMPONENTS Core Widgets Network REQUIRED)

set(SOURCES
    main.cpp
    imageviewer.cpp
    imageproxy.cpp
    filedownloader.cpp)

add_executable(coverview ${SOURCES})
target_link_libraries(coverview Qt5::Widgets Qt5::Network)
