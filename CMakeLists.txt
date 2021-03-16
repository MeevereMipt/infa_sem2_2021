cmake_minimum_required(VERSION 3.15)
project(mipt2021-2sem)

set(CMAKE_CXX_STANDARD 17)
set(APP_USABLES usables/)

include_directories(${APP_USABLES})

set(CONTEST_FILES
        contests/contest2/contest2.h
            contests/contest2/taskA.cpp
            contests/contest2/taskB.cpp
            contests/contest2/taskC.cpp
            contests/contest2/taskD.cpp
            contests/contest2/taskE.cpp
            contests/contest2/taskF.cpp
            contests/contest2/taskG.cpp
            contests/contest2/taskJ.cpp
        contests/contest3/contest3.h
            contests/contest3/taskA.cpp
            contests/contest3/taskB.cpp
            contests/contest3/taskC.cpp
            contests/contest3/taskD.cpp
            contests/contest3/taskE.cpp
            contests/contest3/taskF.cpp
        contests/contest4/contest4.h
        contests/contest5/contest5.h
            contests/contest5/taskA.cpp
            contests/contest5/taskB.cpp
            contests/contest5/taskC.cpp
        contests/contest6_2020/contest6.h
            contests/contest6_2020/taskA.cpp
            contests/contest6_2020/taskB.cpp

        contests/contests.h
        )

set(SOURCE_FILES
        usables/my_stack.h
        usables/my_queue.h
        )

add_executable(
        mipt2021-2sem

        ${CONTEST_FILES}

        main.cpp
        lab2/task1/factorial.hpp
        lab2/task2/fibonnaci.hpp

        ${SOURCE_FILES}
)
