//
// Created by Meevere on 4/13/2021.
//

#include "stack.h"
#include <iostream>

using namespace containers::stack;

template <typename T>
void Stack<T>::push(T n) {
    auto *elem = new StackNode<T>(n);
    elem->next = top;
    top = elem;
    length++;
}

template <typename T>
T Stack<T>::pop() {
    if (top == nullptr)
        throw std::underflow_error("pop with nullptr");

    int out;
    StackNode<T>* prev_top = top;

    out = top->data;
    top = top->next;

    length--;
    delete prev_top;
    return out;
}