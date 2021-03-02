//
// Created by EGor on 02.03.2021.
//

#include <iostream>

namespace contest5 {

    struct Node {
        explicit Node(int x){
            data = x;
            next = nullptr;
        }

        int data;
        struct Node* next;
    };

    class Stack {
    public:
        Stack() {
            top = nullptr;
        }

        ~Stack(){
            while(!if_empty()){
                pop();
            }
        }

        void push(int n){
            Node* elem = new Node(n);
            elem->next = top;
            top = elem;
        }

        int pop(){
            if(top == nullptr)
                throw std::underflow_error("pop with nullptr");

            int out;
            Node* prev_top = top;

            out = top->data;
            top = top->next;

            delete prev_top;
            return out;
        }

        bool if_empty(){
            return top == nullptr;
        }

    protected:
        Node* top;
    };

    int taskB() {

        Stack stack;

        int input;
        while(true){
            std::cin >> input;
            std::cout << input;
        }
        return 0;
    }
}