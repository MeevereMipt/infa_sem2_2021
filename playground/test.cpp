//
// Created by EGor on 13.04.2021.
//

#include <iostream>
#include "containers/array.h"
#include "playground.h"

using containers::array::Array;
namespace playground {
    int test() {
        Array<int> a(5);
        std::cout << a.get_size();
        return 0;
    }
}