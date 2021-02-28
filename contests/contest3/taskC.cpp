//
// Created by Meevere on 3/1/2021.
//
#include <iostream>

namespace contest3 {

    void print_array(int* a){
        for( int i=0; i<6; i++)
            std::cout << a[i];
    }

    int taskC() {
        int a[6];
        for (int & i : a)
            std::cin >> i;
        print_array(a);
        return 0;
    }
}