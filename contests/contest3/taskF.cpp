//
// Created by Meevere on 3/1/2021.
//

#include <iostream>

namespace contest3 {

    int* my_slightly_dumb_reallocation(int* source, unsigned int n_old, unsigned int n_new);

    int* my_slightly_dumb_reallocation(int* source, unsigned int n_old, unsigned int n_new){
        if( n_new == 0 )
            return nullptr;

        int* output = new int[n_new];

        if( source != nullptr)
            for(int i = 0; i < n_old; i++)
                output[i] = source[i];
        return output;
    }

    int taskF() {
        unsigned int n, i;
        std::cin >> n;
        int *a = my_slightly_dumb_reallocation(nullptr, 0, n / 2);

        for (i = 0; i < n / 2; i++)
            std::cin >> a[i];

        a = my_slightly_dumb_reallocation(a, n / 2, n);

        for (; i < n; i++)
            std::cin >> a[i];

        int sum = 0;
        for (i = 0; i < n; i++)
            sum += a[i];

        std::cout << sum << std::endl;
        a = my_slightly_dumb_reallocation(a, n, n / 2);
        a = my_slightly_dumb_reallocation(a, n / 2, 0);
        a = my_slightly_dumb_reallocation(a, 0, 0);

        return 0;
    }
}