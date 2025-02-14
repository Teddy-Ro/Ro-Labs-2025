cmake_minimum_required(VERSION 3.23)

project(lab1)

set(CMAKE_CXX_STANDARD 20)  # Установка стандарта C++

# Опции для clang-tidy
set(CMAKE_CXX_CLANG_TIDY "clang-tidy")

# Исходные файлы
set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main_lab1.cpp
)

# Добавление подпроекта mymath
add_subdirectory(mymath)
add_subdirectory(myprint)

# Создание исполняемого файла
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

# Установка стандартов для целевого проекта
set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_STANDARD 20)

# Опции компиляции
target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -Wall -Wextra -Werror -Wpedantic)

if(ENABLE_DEBUG)
    target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -g)
endif()

# Подключение библиотеки mymath
target_link_libraries(${CMAKE_PROJECT_NAME} mymath myprint)

# Задача для clang-format
add_custom_target(
    clang-format
    COMMAND clang-format --dry-run -Werror ${SOURCES} ${HEADERS}
)
