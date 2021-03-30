//
// Created by EGor on 30.03.2021.
//

#include <iostream>
#include <vector>

namespace control {

    int task3() {

        int nx, ny;
        std::cin >> ny >> nx;

        std::vector<std::vector<char>> array(nx, std::vector<char>(ny, '*'));

        int n; int temp1, temp2;
        std::cin >> n;
        for( int i=0; i<n; i++ ){
            std::cin >> temp2 >> temp1;
            array[temp1][temp2] = 'T';
        }

        for( int i=0; i<nx; i++ ) {
            for (int j = 0; j < ny; j++) {
                std::cout << array[i][j];
            }
            std::cout << '\n';
        }

        return 0;
    }

}
