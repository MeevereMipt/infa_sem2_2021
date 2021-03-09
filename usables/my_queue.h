//
// Created by Meevere on 3/8/2021.
//

#ifndef MIPT2021_2SEM_MY_QUEUE_H
#define MIPT2021_2SEM_MY_QUEUE_H

struct QueueNode {
    explicit Node(int x){
        prev = nullptr;
        data = x;
        next = nullptr;
    }

    int data;
    QueueNode* next;
    QueueNode* prev;
};

class Queue {
public:
    int length;

    Queue(){
        length = 0;
        top = bottom = middle = nullptr;
    }

    void push_top(){
        auto elem = new QueueNode(n);
        elem->prev = top;

        if( length != 0 )
            top->next = elem;
        else {
            bottom = elem;
            middle = elem;
        }

        top = elem;
        length++;

    }
    void push_bottom(){
        auto elem = new QueueNode(n);
        elem->next = bottom;
        top->next = elem;
        top = elem;
        length++;
    }



protected:
    QueueNode* top;
    QueueNode* bottom;
    QueueNode* middle;

    void insert_after(QueueNode* node, QueueNode* insert_node){
        QueueNode* temp;
        temp = node->next;
        node->next = insert_node;
        insert_node->prev = node;
        insert_node->next = temp;
        length++;
    }
};

#endif //MIPT2021_2SEM_MY_QUEUE_H
