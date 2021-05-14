cmake_minimum_required(VERSION 3.15)
project(mipt2021-2sem)

set(CMAKE_CXX_STANDARD 17)
set(APP_USABLES usables/)

include_directories(${APP_USABLES})

set(PLAYGROUND_FILES
        playground/playground.h
        playground/test.cpp)

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
            contests/contest6_2020/taskC.cpp
            contests/contest6_2020/taskD.cpp
            contests/contest6_2020/taskE.cpp
        contests/contest7/contest7.h
            contests/contest7/taskA.cpp
            contests/contest7/taskB.cpp
            contests/contest7/taskC.cpp
            contests/contest7/taskD.cpp
            contests/contest7/taskE.cpp
            contests/contest7/taskF.cpp
            contests/contest7/taskG.cpp
            contests/contest7/taskH.cpp
        contests/control_test/control_test.h
            contests/control_test/task1.cpp
            contests/control_test/task2.cpp
            contests/control_test/task3.cpp
            contests/control_test/task4.cpp
            contests/control_test/task5.cpp
            contests/control_test/task6.cpp
            contests/control_test/task8.cpp
            contests/control_test/task7.cpp
            contests/control_test/task9.cpp

        contests/contests.h
        contests/contest2/taskH.cpp contests/control_test_2/contest_test_2.h contests/control_test_2/task1.cpp contests/control_test_2/task6.cpp)

set(SOURCE_FILES
        usables/containers/stack.h
        usables/containers/deque.h
        usables/my_tree.cpp
        usables/my_tree.h
        usables/containers/array.h
        usables/graph.h
        usables/graph.cpp
        usables/containers/cyclic_array.h
        usables/containers/list.h)

add_executable(
        mipt2021-2sem

        ${SOURCE_FILES}
        ${CONTEST_FILES}

        main.cpp
        lab2/task1/factorial.hpp
        lab2/task2/fibonnaci.hpp

        ${PLAYGROUND_FILES}
)
