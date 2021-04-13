//
// Created by Meevere on 3/8/2021.
//

#ifndef MIPT2021_2SEM_MY_Deque_H
#define MIPT2021_2SEM_MY_Deque_H

#include <iostream>

namespace containers::deque {

    template<typename T>
    struct DequeNode {
        T data;
        DequeNode *next;
        DequeNode *prev;

        explicit DequeNode(T x) {
            prev = nullptr;
            next = nullptr;
            data = x;
        }

        void connect_next(DequeNode *node);
        void connect_prev(DequeNode *node);
    };

    template<typename T>
    class Deque {
    protected:
        DequeNode<T> *top;
        DequeNode<T> *bottom;
    public:
        int length;

        Deque() {
            this->top = this->bottom = nullptr;
            length = 0;
        }

        void push_top(T data);
        void push_bottom(T data);

        T pop_top();
        T pop_bottom();

        friend Deque &operator<<(Deque &q, T data);
        friend Deque &operator>>(Deque &q, T &data);
        friend Deque &operator<<(T &data, Deque &q);
        friend Deque &operator>>(T data, Deque &q);

    };

}
#endif //MIPT2021_2SEM_MY_Deque_H
