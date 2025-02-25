cmake_minimum_required(VERSION 3.23)

set(project "planet")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
        planet.cpp)

set(${project}_HEADERS
        planet.hpp)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES}
        ${${project}_HEADERS})

add_library(${project}
        STATIC
        ${${project}_SOURCE_LIST})
