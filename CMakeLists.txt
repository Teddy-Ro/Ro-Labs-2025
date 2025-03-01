cmake_minimum_required(VERSION 3.23)
project(lab3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_CLANG_TIDY "clang-tidy")

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main_l3.cpp
)



add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_STANDARD 20)

target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -Wall -Wextra -Werror -Wpedantic)

if(ENABLE_DEBUG)
    target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -g)
endif()

add_custom_target(
    clang-format
    COMMAND clang-format --dry-run -Werror ${SOURCES}
)
