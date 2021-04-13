//
// Created by EGor on 02.03.2021.
//

#include <iostream>
#include "containers/stack.h"

using std::cin;
using std::cout;

namespace contest5 {

    int taskA() {
        Stack a;
        int input, top;

        while(true){
            cin >> input;
            if( input == 0 )
                break;

            if( input > 0 ){
                a.push(input);
                continue;
            }

            if( input < 0 ){
                if( a.is_empty() )
                    continue;

                top = a.pop();
                if( -input < top )
                    a.push( top + input );
            }
        }

        if(a.is_empty()) {
            cout << 0 << ' ' << -1 << '\n';
            return 0;
        }

        top = a.pop();

        int count = 1;
        while(!a.is_empty()){
            a.pop();
            count++;
        }

        cout << count << ' ' << top << '\n';
        return 0;
    }

}