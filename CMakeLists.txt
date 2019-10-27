cmake_minimum_required(VERSION 3.10)
project(t1icc2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(t1icc2
        .gitignore
        horario.c
        horario.h
        main.c
        Makefile
        process.c
        process.h
        mergesort.c
        mergesort.h)
