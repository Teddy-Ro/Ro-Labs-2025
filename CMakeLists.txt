cmake_minimum_required(VERSION 3.21.1)
project(lab6)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_CLANG_TIDY "clang-tidy")

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main_l6.cpp
    # ${CMAKE_CURRENT_SOURCE_DIR}/Polynomial.cpp
    # ${CMAKE_CURRENT_SOURCE_DIR}/term.cpp
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

target_link_libraries(${PROJECT_NAME} PRIVATE vecLib)

add_custom_target(
    clang-format
    COMMAND clang-format --dry-run -Werror ${SOURCES}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
