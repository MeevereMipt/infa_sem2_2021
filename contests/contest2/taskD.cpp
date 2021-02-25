//
// Created by Meevere on 2/26/2021.
//

#include <iostream>

namespace contest2 {

    int taskD() {
        int a, a_, b = 1;
        std::cin >> a_;
        a = a_;
        while(a > 1){
            a >>= 1;
            b <<= 1;
        }
        if( a_ == b )
            std::cout << "YES";
        else
            std::cout << "NO";

        return 0;
    }

}