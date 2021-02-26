cmake_minimum_required(VERSION 3.15)
project(mipt2021-2sem)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        mipt2021-2sem
            contests/contest2/contest2.h
                contests/contest2/taskA.cpp
                contests/contest2/taskB.cpp
            contests/contest3/contest3.h
                contests/contest3/taskA.cpp
                contests/contest3/taskB.cpp
            contests/contest4/contest4.h
            contests/contest5/contest5.h
            contests/contest6/contest6.h

        contests/contests.h

        main.cpp
        lab2/task1/factorial.hpp
        lab2/task2/fibonnaci.hpp
        contests/contest2/taskC.cpp contests/contest2/taskD.cpp contests/contest2/taskE.cpp contests/contest2/taskF.cpp contests/contest2/taskG.cpp contests/contest2/taskJ.cpp)

