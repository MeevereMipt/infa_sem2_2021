//
// Created by EGor on 16.03.2021.
//
#include <iostream>
#include "containers/cyclic_array.h"

using containers::array::CyclicArray;

namespace contest6{

    CyclicArray<int>& smooth(const CyclicArray<int> &arr){
        CyclicArray<int> *temp;
        temp = new CyclicArray<int>(arr.get_size());

        int size = arr.get_size();
        for( int i=0; i<size; i++ ){
            (*temp)[i] = (arr[i-1] + arr[i] + arr[i+1])/3;
        }

        return *temp;
    }


    int taskC(){

        int n;
        std::cin >> n;
        CyclicArray<int> test(n);

        std::cin >> test;
        test = smooth(test);
        std::cout << test;

        return 0;
    }
}