//
// Created by Meevere on 2/26/2021.
//
#include <iostream>

namespace contest2 {

    int taskC() {
        int input, count = 0;
        while(true){
            std::cin >> input;
            if( input == 0 )
                break;

            if( input % 2 == 0 )
                ++count;
        }
        std::cout << count << "\n";
        return 0;
    }

}