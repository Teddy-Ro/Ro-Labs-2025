cmake_minimum_required(VERSION 3.20)

project(lab1)

set(CMAKE_CXX_CLANG_TIDY "clang-tidy")

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main_lab1.cpp
)

set(HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/head_lab1.hpp
)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES} ${HEADERS})
set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_STANDARD 20)
target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -Wall -Wextra -Werror -Wpedantic)

if(ENABLE_DEBUG)
    target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -g)
endif()

add_custom_target(
    clang-format
    COMMAND clang-format
    --dry-run
    -Werror
    ${SOURCES}
    ${HEADERS}
)
