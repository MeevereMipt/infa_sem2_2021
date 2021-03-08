//
// Created by EGor on 02.03.2021.
//

#include <iostream>
#include "my_stack.h"

namespace contest5 {

    int taskB() {

        Stack stack;

//        std::istream::sync_with_stdio(false);
        std::cin.exceptions( std::ios_base::failbit );

        int int_input;
        char char_input;

        // Small костыль, every string must contain at start at least two integers
        std::cin >> int_input;
        stack.push(int_input);

        std::cin >> int_input;
        stack.push(int_input);

        while(true){
            try{

                std::cin >> int_input;
                stack.push(int_input);

            } catch( std::ios_base::failure &e ){
                // Clear the exception flags, the data in stream will remain
                std::cin.clear();
                // When + or - the stream doesnt get this symbol properly
                // shortly - magic to get this stuff working
                std::cin.unget();

                // Then read the operation thingy
                std::cin >> char_input;
                int a, b;
                b = stack.pop(); a = stack.pop();

                switch (char_input) {
                    case '+':
                        stack.push(a + b);
                        break;
                    case '-':
                        stack.push(a - b);
                        break;
                    case '*':
                        stack.push(a * b);
                        break;
                    case '/':
                        stack.push(a / b);
                        break;
                    default:
                        throw(std::invalid_argument("bad input, no matching operator"));
                }
            }

            if( std::cin.peek() == '\n' )
                break;
        }

        std::cout << stack.pop() << '\n';
        return 0;
    }
}