//
// Created by EGor on 09.02.2021.
//
#pragma once

#include <iostream>

int fibb_non_rec( int n ){
    int n1,n2,n3;
    n1 = n2 = n3 = 1;

    for( int i=0; i<n; i++){
        n1 = n2 + n3;
        n3 = n2;
        n2 = n1;
    }
    return n1;
}

int fibb_rec( int n ){
    if( (n == 0) or (n == 1) )
        return 1;
    return fibb_rec(n-1) + fibb_rec(n-2);
}

int fibb_rec_opt( int n ){

}

int fibbonaci_main( int arg ) {
    std::cout << fibb_non_rec(arg);
    return 0;
}