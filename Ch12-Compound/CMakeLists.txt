cmake_minimum_required (VERSION 3.9 FATAL_ERROR)

project (DJbeatController CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED 14)

set(CMAKE_CXX_FLAGS "-g -Og ${CMAKE_CXX_FLAGS}")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Core Widgets Multimedia REQUIRED)

set(SOURCES
    main.cpp
    beatcontrol.cpp
    beatcontrol.ui
    beatmodel.cpp
    beatview.cpp
    beatview.ui
    controllers.cpp
    djview.cpp
    tonegenerator.cpp)

add_executable(djbeat ${SOURCES})
target_link_libraries(djbeat Qt5::Widgets Qt5::Multimedia)
