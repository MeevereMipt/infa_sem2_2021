//
// Created by Meevere on 4/14/2021.
//

#ifndef MIPT2021_2SEM_LIST_H
#define MIPT2021_2SEM_LIST_H

#include "deque.h"
#include <iterator>

using containers::deque::Deque;
using containers::deque::DequeNode;

namespace containers::list {

    template <typename T>
    class List: public Deque<T>{
    public:
        List(): Deque<T>(){};
        List(std::initializer_list<T> list): Deque<T>(list){};

        struct Iterator {
        private:
            DequeNode<T>* ptr;
        public:
            using iterator_category = std::forward_iterator_tag;
            using difference_type   = std::ptrdiff_t;
            using value_type        = T;
            using pointer           = T*;
            using reference         = T&;

            explicit Iterator(DequeNode<T>* ptr) : ptr(ptr) {}

            reference operator*() const { return ptr->data; }
            pointer operator->() { return &(ptr->data); }

            // Prefix increment
            Iterator& operator++() { ptr = ptr->next; return *this; }

            // Postfix increment
            Iterator operator++(int) { Iterator temp = *this; ++(*this); return temp; }

            friend bool operator== (const Iterator& a, const Iterator& b) { return a.ptr == b.ptr; };
            friend bool operator!= (const Iterator& a, const Iterator& b) { return a.ptr != b.ptr; };

        };

        bool find( T data ){
            DequeNode<T> cur_node = this->top;
            while(cur_node){
                if (cur_node.data == data)
                    return true;
                cur_node = cur_node.prev;
            }
            return false;
        }

        Iterator begin(){ return Iterator(this->bottom); }
        Iterator end(){ return Iterator(this->top); }

    };

    template<typename T>
    ostream & operator << (ostream &out, const List<T> &ls);
    template<typename T>
    istream & operator >> (istream &in, List<T> &ls);

    template <typename T>
    ostream & operator << (ostream &out, List<T> &ls) {
        out << "| ";
        for( auto it = ls.begin() ; it != ls.end() ; it++ ){
            out << *it << ' ';
        }
        out << '|';
        return out;
    }

    template <typename T>
    istream & operator >> (istream &in, List<T> &ls) {
        T elem;
        in >> elem;
        elem >> ls;
        return in;
    }


}

#endif //MIPT2021_2SEM_LIST_H
