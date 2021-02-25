//
// Created by Meevere on 2/26/2021.
//

#include <iostream>

namespace contest2 {

    int taskE() {
        int input, max = 0;

        // all input numbers are natural, so greater than 0
        while(true){
            std::cin >> input;
            if( input == 0 )
                break;

            if((input > max) and (input % 2 == 0))
                max = input;
        }
        std::cout << max;
        return 0;
    }

}