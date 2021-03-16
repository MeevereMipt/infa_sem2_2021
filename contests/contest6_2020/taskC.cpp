//
// Created by EGor on 16.03.2021.
//
#include <iostream>
#include "my_array.h"

namespace contest6{

    void smooth(Array<int>* &arr){
        Array<int> temp(arr->get_size());
        for( int i=0; i<temp.get_size(); i++ ){
            temp[i] = ((*arr)[i-1] + (*arr)[i] + (*arr)[i+1])/3;
        }
        delete arr;
        arr = &temp;
    }


    int taskC(){
        Array<int> test(2);

        return 0;
    }
}