//
// Created by EGor on 06.04.2021.
//

#include "my_tree.h"

using namespace bin_tree;

template<typename T>
Node<T>::Node(T _data) {
    height = 0;
    data = _data;
    left = nullptr;
    right = nullptr;
}

template<typename T>
BinTree<T>::BinTree() {
    head = nullptr;
    height = 0;
}

template<typename T>
void BinTree<T>::search(T data) {

}

template<typename T>
void BinTree<T>::insert(T data) {

}
