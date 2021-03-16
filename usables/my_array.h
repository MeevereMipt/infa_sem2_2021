//
// Created by EGor on 16.03.2021.
//

#ifndef MIPT2021_2SEM_MY_ARRAY_H
#define MIPT2021_2SEM_MY_ARRAY_H

template <typename T>

class Array {
    T* _arr;
    int _size;
public:

    explicit Array(int size){
        _size = size;
        _arr = new T[size];
    }

    ~Array(){
        delete [] _arr;
    }

    T& operator [] (int i){
        if( i < 0 ){
            i = _size-(-i)%_size;
        }
        return _arr[i % _size];
    }

    int get_size(){
        return _size;
    }
};

#endif //MIPT2021_2SEM_MY_ARRAY_H
