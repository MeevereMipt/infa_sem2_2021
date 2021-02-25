#include "lab2/task1/factorial.hpp"
#include "lab2/task2/fibonnaci.hpp"

#include <iostream>

#include "contests/contests.h"
#include <iostream>

//typedef int my_int;
//typedef void (*p_func)();

#define WRONG_CONTEST_NUMBER 2

int contest_task( int num, char index ){
    switch (num) {
        case 2: return contest2::task(index);
        case 3: return contest3::task(index);
        case 4: return contest4::task(index);
        case 5: return contest5::task(index);
        case 6: return contest6::task(index);
        default: return WRONG_CONTEST_NUMBER;
    }
}

int main() {
    int contest_num; char task_index;

    std::cout << "Enter contest number and the symbol of the task like: 2 A\n";
    while(true) {
        std::cin >> contest_num >> task_index;

        switch (contest_task(contest_num, task_index)) {
            case WRONG_CONTEST_NUMBER:
                std::cout << "Wrong contest number, try again\n";
                break;
            case 1:    
                std::cout << "Wrong task index/task isn't done yet. Try again\n";
                break;
            case 0:
                goto LOOP_EXIT;
            default:
                std::cout << "Something went wrong. Exiting the reply loop\n";
                goto LOOP_EXIT;
        }

    }
    LOOP_EXIT:
    return 0;
}