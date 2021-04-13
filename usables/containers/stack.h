//
// Created by Meevere on 3/6/2021.
//

#ifndef MIPT2021_2SEM_STACK_H
#define MIPT2021_2SEM_STACK_H

namespace containers::stack {

        template<typename T>
        struct StackNode {
            explicit StackNode(T x) {
                data = x;
                next = nullptr;
            }

            T data;
            StackNode *next;
        };

        template<typename T>
        class Stack {
        protected:
            StackNode<T> *top;
        public:
            // for decorative purposes
            int length;

            Stack() {
                top = nullptr;
                length = 0;
            }

            ~Stack() {
                while (!is_empty()) {
                    pop();
                }
            }

            void push(T n);
            T pop();

            bool is_empty() {
                return top == nullptr;
            }

        };
    }

#endif //MIPT2021_2SEM_STACK_H
