//
// Created by EGor on 23.03.2021.
//

#include <iostream>
//#include <iomanip>

using std::cin;
using std::cout;

namespace contest7{

    int taskA(){
        int a, b, c, d, x, grade;

        cin >> a >> b >> c >> d;
        cin >> x;

        bool first_equation, second_equation;
        first_equation = (a + x == b);
        second_equation = (c * x == d);

        if ( !first_equation and !second_equation )
            if (x == 1024)
                grade = 3;
            else
                grade = 2;
        else if( first_equation and second_equation )
            grade = 5;
        else
            grade = 4;

        cout << grade;

        return 0;
    }

}
