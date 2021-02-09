//
// Created by EGor on 09.02.2021.
//
#pragma once

#include <iostream>
#include <limits>

int factorial( int n ){
    if ( n == 0 )
        return 1;
    return factorial(n-1)*n;
}

int factorial_check_int(){
    int n = 1; int out = 1;
    while(true){
        if (out > std::numeric_limits<int>::max() / n)
            break;
        out = out * n;
        n++;
    }
    return n;
}

int factorial_check_long(){
    int n = 1; long out = 1;
    while(true){
        if (out > std::numeric_limits<long>::max() / n)
            break;
        out = out * n;
        n++;
    }
    return n;
}

int factorial_check_long_long(){
    int n = 1; long long out = 1;
    while(true){
//        std::cout << (n-1) << ';' << out << std::endl;
        if (out > std::numeric_limits<long long>::max() / n)
            break;
        out = out * n;
        n++;
    }
    return n;
}

int factorial_main() {
    std::cout << factorial_check_int() << std::endl;
    std::cout << factorial_check_long() << std::endl;
    std::cout << factorial_check_long_long() << std::endl;
    return 0;
}