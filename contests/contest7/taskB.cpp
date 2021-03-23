//
// Created by EGor on 23.03.2021.
//

#include <iostream>

namespace contest7{

    int first_digit(int number){
        int temp;
        while( (temp = number / 10) > 0 )
            number = temp;
        return number;
    }

    bool check_int(int number){
        int temp;

        temp = first_digit(number);

        // is false when Petya wouldn't like the digit
        // bool div_4 = !((number % 4 == 0) and (temp != 4) and (temp != 5));
        bool div_4 = (number % 4 != 0) or (temp == 4) or (temp == 5);
        bool div_7 = (number % 7 != 0) or (temp == 7) or (temp == 1);
        bool div_9 = (number % 9 != 0) or (temp == 9) or (temp == 8);

        return div_4 and div_7 and div_9;
    }

    int taskB(){
        int n, input = -1;

        // without std it looks horrible
        std::cin >> n;

        for(int i=0; i<n; i++){
            std::cin >> input;
            if (!check_int(input)){
                std::cout << input << ' ';
            }
        }
        if (input == -1)
            std::cout << 0 << std::endl;

        return 0;
    }

}