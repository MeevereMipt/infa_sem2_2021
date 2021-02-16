#include "lab2/task1/factorial.hpp"
#include "lab2/task2/fibonnaci.hpp"

#include <iostream>

#include "contests/contests.h"

//typedef int my_int;
//typedef void (*p_func)();

int main() {
//    factorial_main();
    int n;
    contest5::task('A');
    std::cin >> n;
    fibbonaci_main(n);
    return 0
}