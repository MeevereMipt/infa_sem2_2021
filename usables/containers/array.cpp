//
// Created by Meevere on 4/13/2021.
//

#include "array.h"

using namespace containers::array;

template <typename T>
ostream & operator << (ostream &out, const Array<T> &arr) {
    out << "[ ";
    for(int i=0; i<arr.get_size(); i++){
        out << arr[i] << ' ';
    }
    out << ']';
    return out;
}

template <typename T>
istream & operator >> (istream &in, Array<T> &arr) {
    for(int i=0; i<arr.get_size(); i++){
        in >> arr[i];
    }
    return in;
}