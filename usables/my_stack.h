//
// Created by Meevere on 3/6/2021.
//

#ifndef MIPT2021_2SEM_MY_STACK_H
#define MIPT2021_2SEM_MY_STACK_H

struct StackNode {
    explicit StackNode(int x){
        data = x;
        next = nullptr;
    }

    int data;
    StackNode* next;
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
        StackNode* elem = new StackNode(n);
        elem->next = top;
        top = elem;
        length++;
    }

    int pop(){
        if(top == nullptr)
            throw std::underflow_error("pop with nullptr");

        int out;
        StackNode* prev_top = top;

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
    StackNode* top;
};

#endif //MIPT2021_2SEM_MY_STACK_H
