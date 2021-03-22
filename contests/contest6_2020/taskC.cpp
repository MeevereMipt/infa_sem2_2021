//
// Created by EGor on 16.03.2021.
//
#include <iostream>
#include "my_array.h"

namespace contest6{

    Array<int>& smooth(const Array<int> &arr){
        auto temp = new Array<int>(arr.get_size());

        int size = arr.get_size();
        for( int i=0; i<size; i++ ){
            (*temp)[i] = (arr[i-1] + arr[i] + arr[i+1])/3;
        }

        return *temp;
    }


    int taskC(){

        int n;
        std::cin >> n;
        Array<int> test(n);

        std::cin >> test;
        test = smooth(test);
        std::cout << test;

        return 0;
    }
}