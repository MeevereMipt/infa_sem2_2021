//
// Created by Meevere on 2/25/2021.
//

#include <iostream>

namespace contest2 {

    int GCD(int a, int b) {
        if (a <= 0 or b <= 0) {
            if (a <= 0) return b;
            return a;
        }

        if (a > b) {
            return GCD(a - b, b);
        } else {
            return GCD(a, b - a);
        }
    }

    int taskA() {
        int a, b;
        std::cin >> a >> b;
        std::cout << GCD(a, b);
        return 0;
    }

}