//
// Created by Meevere on 3/26/2021.
//

#include "deque.h"

using namespace containers::deque;

template <typename T>
void DequeNode<T>::connect_next(DequeNode *node) {
    this->next = node;
    if (node != nullptr)
        node->prev = this;
}

template <typename T>
void DequeNode<T>::connect_prev(DequeNode<T> *node) {
    this->prev = node;
    if (node != nullptr)
        node->next = this;
}

template <typename T>
void Deque<T>::push_top(T const data) {
    auto elem = new DequeNode(data);
    elem->connect_prev(this->top);

    if (length == 0) {
        bottom = elem;
    }

    top = elem;
    length++;
}

template <typename T>
void Deque<T>::push_bottom(T const data) {
    auto elem = new DequeNode(data);
    elem->connect_next(bottom);

    if (length == 0) {
        top = elem;
    }

    bottom = elem;
    length++;
}

template <typename T>
T Deque<T>::pop_top() {
    auto prev_top = this->top;
    if (prev_top == nullptr)
        throw std::underflow_error("pop with empty Deque");

    T data = prev_top->data;
    this->top = prev_top->prev;

    delete prev_top;
    length--;
    return data;
}

template <typename T>
T Deque<T>::pop_bottom() {
    auto prev_bottom = this->bottom;
    if (prev_bottom == nullptr)
        throw std::underflow_error("pop with empty Deque");

    T data = prev_bottom->data;
    this->bottom = prev_bottom->prev;

    delete prev_bottom;
    length--;
    return data;
}

template <typename T>
Deque<T>& operator<<(Deque<T> &q, const T data) {
    DequeNode node(data);
    q.push_top(node);
    return q;
}

template <typename T>
Deque<T>& operator>>(Deque<T> &q, T &data) {
    data = q.pop_top();
    return q;
}

template <typename T>
Deque<T>& operator<<(T &data, Deque<T> &q) {
    data.pop_bottom();
    return q;
}

template <typename T>
Deque<T>& operator>>(const T data, Deque<T> &q) {
    DequeNode node(data);
    q.push_bottom(node);
    return q;
}