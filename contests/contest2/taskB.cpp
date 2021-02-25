//
// Created by Meevere on 2/25/2021.
//

#include <iostream>

namespace contest2 {

    int taskB(){
        long year;

        std::cin >> year;

        if( year % 4 == 0 )
            if((year % 100 != 0) or (year % 400 == 0)){
                std::cout << "YES";
                return 0;
            }
        std::cout << "NO";
        return 0;
    }

}