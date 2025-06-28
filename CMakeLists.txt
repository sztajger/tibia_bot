cmake_minimum_required(VERSION 3.10)

project(TibiaBot VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Dodaj katalog z nagłówkami (jeśli są w src/)
include_directories(src)

# Dodaj wszystkie pliki źródłowe
add_executable(TibiaBot
    src/main.cpp
    src/input_simulator.cpp
    src/memory_reader.cpp
    src/process_utils.cpp
    src/window_utils.cpp
)
