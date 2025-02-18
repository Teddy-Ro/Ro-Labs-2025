cmake_minimum_required(VERSION 3.23)

set(project "lab_1_2")
project(${project})

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/include)

link_directories(${CMAKE_SOURCE_DIR}/lib)

set(${project}_SOURCES
        main_lab_1_2.cpp)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES})

add_executable(${project}
        ${${project}_SOURCE_LIST})

target_link_libraries(${project}
    myprint)
