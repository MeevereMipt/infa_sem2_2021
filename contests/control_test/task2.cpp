//
// Created by EGor on 30.03.2021.
//

#include <iostream>
#include <cmath>

namespace control {

    int task2() {
        float k, h_0, m;
        std::cin >> k >> h_0 >> m;

        std::cout << std::fixed;
        std::cout.precision(1);

        std::cout << h_0 * sqrt( double(2*k / m) );

        return 0;
    }
}