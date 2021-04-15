//
// Created by Meevere on 4/14/2021.
//

#ifndef MIPT2021_2SEM_LIST_H
#define MIPT2021_2SEM_LIST_H

#include "deque.h"

using containers::deque::Deque;
using containers::deque::DequeNode;

namespace containers::list {

    template <typename T>
    class List: public Deque<T>{
    public:
        using Deque<T>::Deque;

        bool find( T data ){
            DequeNode<T> cur_node = this->top;
            while(cur_node){
                if (cur_node.data == data)
                    return true;
                cur_node = cur_node.prev;
            }
            return false;
        }

    };

}

#endif //MIPT2021_2SEM_LIST_H
