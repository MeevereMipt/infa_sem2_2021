//
// Created by Meevere on 2/26/2021.
//

#include <iostream>

namespace contest2 {

    int taskF() {
        int input, max=0, max_count=0;

        while(true){
            std::cin >> input;
            if( input == 0 )
                break;

            if( input > max_count ){
                max = input;
                max_count = 1;
            } else
                if ( input == max_count)
                    max_count++;
        }
        std::cout << max_count;
        return 0;
    }

}