//
// Created by EGor on 16.02.2021.
//

#include <iostream>

namespace contest3 {
    int taskA(){


        return 0;
    }

    int stupid_taskA(){
        unsigned int array[255];

        unsigned int N;
        unsigned long sum = 0, out_sum = 0;

        std::cin >> N;
        for( int i=0; i<N; i++ ){
            std::cin >> array[i];
            sum += array[i];
        }

        for( int i=0; i<N; i++ ){
            if( N*array[i] > sum )
                out_sum += array[i]
        }

        return 0;
    }
}