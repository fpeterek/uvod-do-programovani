cmake_minimum_required(VERSION 3.20)
project(pikolang)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_FLAGS "-Wall -Wextra -Wconversion -pedantic")
set(CMAKE_C_FLAGS_RELEASE "-O3")
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)


include_directories(
    ./include/
)


add_executable(
    minesweeper

    src/main.c
)
