//
// Created by Meevere on 4/13/2021.
//

#ifndef MIPT2021_2SEM_ARRAY_H
#define MIPT2021_2SEM_ARRAY_H

#include <iostream>
using std::ostream;
using std::istream;

namespace containers::array {

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

        virtual T& operator [] (int i) {
            if( i >= _size or i < 0 )
                throw std::out_of_range("out of bounds");
            return _arr[i];
        }

        // for not changing the array itself??
        virtual T operator [] (int i) const {
            if( i >= _size or i < 0 )
                throw std::out_of_range("out of bounds");
            return _arr[i];
        }

        Array& operator=(const Array& other){
            if( &other != this ) {
                int size = std::min<int,int>(other.get_size(),size);
                for (int i = 0; i < size; i++) {
                    (*this)[i] = other[i];
                }
            }
            return *this;
        }

        // wtf why clion said to make it [[nodiscard]]
        // works nevertheless
        // it's just a tip for the compiler that this value should not be discarded
        [[nodiscard]] int get_size() const {
            return _size;
        }

        friend ostream & operator << (ostream &out, const Array &arr);
        friend istream & operator >> (istream &in, Array &arr);
    };

}

#endif //MIPT2021_2SEM_ARRAY_H
