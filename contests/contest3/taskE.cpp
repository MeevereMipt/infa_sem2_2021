//
// Created by Meevere on 3/1/2021.
//

#include <iostream>

namespace contest3 {

    int do_some_awesome_work(int* a, int* b);

    int do_some_awesome_work(int* a, int* b){
        (*a)++;
        (*b)++;
        return *a + *b;
    }

    int taskE() {
        int a, b;
        std::cin >> a >> b;
        std::cout << do_some_awesome_work(&a,&b);
        return 0;
    }
}