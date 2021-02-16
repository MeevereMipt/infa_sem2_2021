cmake_minimum_required(VERSION 3.15)
project(mipt2021-2sem)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        mipt2021-2sem
            contests/contest2/contest2.h
            contests/contest3/contest3.h

        contests/contests.h

        main.cpp
        lab2/task1/factorial.hpp
        lab2/task2/fibonnaci.hpp
)

