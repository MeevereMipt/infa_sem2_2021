//
// Created by EGor on 16.03.2021.
//

#include <iostream>
#include "containers/stack.h"

namespace contest6{

    int taskA(){

        int n, m, input;
        std::cin >> n >> m;

        Stack front, back;
        for(int i=0; i<m; i++){
            std::cin >> input;
            front.push(input);
        }

        for(int i=m; i<n; i++){
            std::cin >> input;
            back.push(input);
        }

        while(!back.is_empty()){
            std::cout << back.pop() << ' ';
        }
        while(!front.is_empty()){
            std::cout << front.pop() << ' ';
        }
        std::cout << std::endl;
        return 0;
    }
}