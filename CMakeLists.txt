cmake_minimum_required(VERSION 3.21.1)
project(lab7)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_CLANG_TIDY "clang-tidy")  # Раскомментируйте если установлен clang-tidy

# Source files (убедитесь что stack.cpp существует)
set(SOURCES
    main_l7.cpp
    lib/stack.cpp
)

# Include directories
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/lib
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(${PROJECT_NAME} ${SOURCES})

# Compiler options
target_compile_options(${PROJECT_NAME} PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)

# Debug options
if(ENABLE_DEBUG)
    target_compile_options(${PROJECT_NAME} PRIVATE -g)
endif()

# Formatting check (обновите пути)
file(GLOB_RECURSE ALL_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/main_l7.cpp
)

add_custom_target(
    clang-format
    COMMAND clang-format --dry-run -Werror ${ALL_SOURCES}
)
