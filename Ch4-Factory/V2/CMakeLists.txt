cmake_minimum_required (VERSION 3.9)

project(PizzaStore CXX)

set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_STANDARD_REQUIRED 14)

set (CMAKE_CXX_FLAGS "-g -Og ${CMAKE_CXX_FLAGS}")

add_executable (pizza main.cpp
                        cheese.cpp
                        clams.cpp
                        doughs.cpp
                        ingredfactories.cpp
                        pepperoni.cpp
                        pizza.cpp
                        pizzastore.cpp
                        sauces.cpp
                        veggies.cpp)

