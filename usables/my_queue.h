//
// Created by Meevere on 3/8/2021.
//

#ifndef MIPT2021_2SEM_MY_QUEUE_H
#define MIPT2021_2SEM_MY_QUEUE_H

#include <iostream>

template <typename T> struct QueueNode {
    T data;
    QueueNode* next;
    QueueNode* prev;

    explicit QueueNode(T x){
        prev = nullptr;
        data = x;
        next = nullptr;
    }

    void connect_next( QueueNode* node ) {
        this->next = node;
        if (node != nullptr)
            node->prev = this;
    }

    void connect_prev( QueueNode* node ) {
        this->prev = node;
        if (node != nullptr)
            node->next = this;
    }
};

template <typename T> class Queue {
protected:
    QueueNode<T>* top;
    QueueNode<T>* bottom;
public:
    int length;

    Queue(){
        this->top = this->bottom = nullptr;
        length = 0;
    }

    void push_top(T data){
        auto elem = new QueueNode(data);
        elem->connect_prev(this->top);

        if( length == 0 ) {
            bottom = elem;
        }

        top = elem;
        length++;
    }
    void push_bottom( T data ){
        auto elem = new QueueNode(data);
        elem->connect_next(bottom);

        if( length == 0 ) {
            top = elem;
        }

        bottom = elem;
        length++;
    }

    T pop_top() {
        auto prev_top = this->top;
        if( prev_top == nullptr )
            throw std::underflow_error("pop with empty queue");

        T data = prev_top->data;
        this->top = prev_top->prev;

        delete prev_top;
        length--;
        return data;
    }

    T pop_bottom() {
        auto prev_bottom = this->bottom;
        if( prev_bottom == nullptr )
            throw std::underflow_error("pop with empty queue");

        T data = prev_bottom->data;
        this->bottom = prev_bottom->prev;

        delete prev_bottom;
        length--;
        return data;
    }

};

#endif //MIPT2021_2SEM_MY_QUEUE_H
