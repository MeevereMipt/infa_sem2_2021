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

        explicit Array(){
            _size = 0;
            _arr = nullptr;
        }

        explicit Array(int size){
            _size = size;
            _arr = new T[size];
        }

        Array(std::initializer_list<T> list){
            _size = list.size();
            _arr = new T[_size];
            int i=0;
            for( auto elem : list ){
                _arr[i] = elem;
                i++;
            }
        }

        explicit Array(int size, T def){
            _size = size;
            _arr = new T[size];
            for( int i=0; i<size; i++){
                _arr[i] = def;
            }
        }

        ~Array(){
            delete [] _arr;
        }

        int find( T value ) const;

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
                int size = other.get_size() > size ? size : other.get_size();
                for (int i = 0; i < size; i++) {
                    (*this)[i] = other[i];
                }
            }
            return *this;
        }

        T* begin(){
            return _arr;
        }

        T* end(){
            return _arr + _size;
        }

        // wtf why clion said to make it [[nodiscard]]
        // works nevertheless
        // it's just a tip for the compiler that this value should not be discarded
        [[nodiscard]] int get_size() const {
            return _size;
        }

    };

    template<typename T>
    ostream & operator << (ostream &out, const Array<T> &arr);
    template<typename T>
    istream & operator >> (istream &in, Array<T> &arr);

    ////////////////////////////////////////////////////
    /////AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
    //AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
    //ya like this separation block???AAAAAAAAAAAAAAAAAA

    template <typename T>
    int Array<T>::find(T value) const {
        int i=-1;
        for( i=0; i < _size; i++ ){
            if( (*this)[i] == value)
                return i;
        }
        return i;
    }

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

}



#endif //MIPT2021_2SEM_ARRAY_H
