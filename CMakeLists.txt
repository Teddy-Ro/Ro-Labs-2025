cmake_minimum_required(VERSION 3.21.1)
project(lab8)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_CLANG_TIDY "clang-tidy")

# Source files
set(SOURCES
    main_l8.cpp
    tasks.cpp
)

# Если tasks.h лежит рядом с исходниками:
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(${PROJECT_NAME} ${SOURCES})

target_compile_options(${PROJECT_NAME} PRIVATE
    -Wall
    -Wextra
    -Werror
    -Wpedantic
)

if(ENABLE_DEBUG)
    target_compile_options(${PROJECT_NAME} PRIVATE -g)
endif()

# Formatting check (поиск всех .cpp и .h файлов в корне проекта)
file(GLOB_RECURSE ALL_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h
)

add_custom_target(
    clang-format
    COMMAND clang-format --dry-run -Werror ${ALL_SOURCES}
)
