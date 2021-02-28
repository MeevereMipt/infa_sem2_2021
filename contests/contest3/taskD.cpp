//
// Created by Meevere on 3/1/2021.
//

#include <iostream>

namespace contest3 {

    int* now_get_me_some_bytes(unsigned int n){
        return new int[n];
    }

    void now_free_some_bytes(int* p){
        delete [] p;
    }

    int taskD() {
        unsigned int n;
        std::cin >> n;

        int *a = now_get_me_some_bytes(n);

        for (int i = 0; i < n; i++)
            std::cin >> a[i];

        int count = 0;
        for (int i = 0; i < n; i++)
            count += a[i];

        if (count % 2)
            std::cout << "NO" << '\n';
        else
            std::cout << "YES" << '\n';
        now_free_some_bytes(a);
        return 0;
    }
}