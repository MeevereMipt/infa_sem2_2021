//
// Created by Meevere on 3/23/2021.
//

#include <iostream>
#include "my_array.h"

namespace contest6 {

    void swap( int& a, int& b ){
        int tmp;
        tmp = a;
        a = b;
        b = tmp;
    }

    void bubble_sort(Array<int>& arr){
        bool was_swapped = false;
        int size = arr.get_size();
        do {
            was_swapped = false;
            for(int i=0; i<size-1; i++){
                if( arr[i] > arr[i+1] ) {
                    swap(arr[i], arr[i + 1]);
                    was_swapped = true;
                }
            }
        } while (was_swapped);
    }


    int taskD() {

        int n;
        std::cin >> n;
        Array<int> arr(n);

        std::cin >> arr;
        bubble_sort(arr);
        std::cout << arr;

        return 0;
    }

}