//
// Created by EGor on 16.03.2021.
//



#ifndef MIPT2021_2SEM_MY_ARRAY_H
#define MIPT2021_2SEM_MY_ARRAY_H

#include <iostream>
using std::ostream;
using std::istream;

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

    T operator [] (int i) const{
        if( i < 0 ){
            i = _size-(-i)%_size;
        }
        return _arr[i % _size];
    }

    Array& operator=(const Array& other){
        if( &other != this ) {
            int size = other.get_size();
            for (int i = 0; i < size; i++) {
                (*this)[i] = other[i];
            }
        }
        return *this;
    }

    // wtf why clion said to make it [[nodiscard]]
    [[nodiscard]] int get_size() const {
        return _size;
    }

    friend ostream & operator << (ostream &out, const Array &arr) {
        out << "[ ";
        for(int i=0; i<arr.get_size(); i++){
            out << arr[i] << ' ';
        }
        out << ']';
        return out;
    }

    friend istream & operator >> (istream &in, Array &arr) {
        for(int i=0; i<arr.get_size(); i++){
            in >> arr[i];
        }
        return in;
    }
};

#endif //MIPT2021_2SEM_MY_ARRAY_H
