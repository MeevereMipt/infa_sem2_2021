//
// Created by EGor on 16.03.2021.
//

#include <iostream>
#include "containers/stack.h"

namespace contest6{

    int taskB(){
        int n, input;
        Stack stack;

        std::cin >> n;

        for(int i=0; i<n; i++){
            std::cin >> input;
            stack.push(input);
        }

        while(!stack.is_empty())
            std::cout << stack.pop() << ' ';
        std::cout << std::endl;

        return 0;
    }

}