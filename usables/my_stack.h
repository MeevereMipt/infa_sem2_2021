//
// Created by Meevere on 3/6/2021.
//

#ifndef MIPT2021_2SEM_MY_STACK_H
#define MIPT2021_2SEM_MY_STACK_H

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
    int length;

    Stack() {
        top = nullptr;
        length = 0;
    }

    ~Stack(){
        while(!is_empty()){
            pop();
        }
    }

    void push(int n){
        Node* elem = new Node(n);
        elem->next = top;
        top = elem;
        length++;
    }

    int pop(){
        if(top == nullptr)
            throw std::underflow_error("pop with nullptr");

        int out;
        Node* prev_top = top;

        out = top->data;
        top = top->next;

        length--;
        delete prev_top;
        return out;
    }

    bool is_empty(){
        return top == nullptr;
    }

protected:
    Node* top;
};

#endif //MIPT2021_2SEM_MY_STACK_H
