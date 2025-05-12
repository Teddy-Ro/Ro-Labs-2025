cmake_minimum_required(VERSION 3.21.1)
project(lab7)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_CLANG_TIDY "clang-tidy")

# Source files
set(SOURCES
    main_l7.cpp
)

# Header files
include_directories(
    include
)

add_subdirectory(vecLib)

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

target_link_libraries(${PROJECT_NAME} vecLib)

# Formatting check
file(GLOB_RECURSE ALL_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

add_custom_target(
    clang-format
    COMMAND clang-format --dry-run -Werror ${ALL_SOURCES}
)
