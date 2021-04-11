//
// Created by Meevere on 2/26/2021.
//

#include <iostream>

namespace contest2 {

#define N 25
    const int first_couple_primes[] =
            {2, 3, 5, 7, 11, 13, 17, 19, 23,
            29, 31, 37, 41, 43, 47, 53, 59,
            61, 67, 71, 73, 79, 83, 89, 97};

    bool is_prime( int num ){
        int k = 0;
        for(; k<N; k++){
            if (num % first_couple_primes[k] != 0)
                return false;
        }
        k = 100;
        for(; k*k<num; k++){
            if (num % k != 0)
                return false;
        }
        return true;
    }

    int taskG() {
        int input;
        std::cin >> input;
        std::cout << int(is_prime(input));
        return 0;
    }

}