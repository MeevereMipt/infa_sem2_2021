//
// Created by EGor on 16.02.2021.
//

#ifndef MIPT2021_2SEM_CONTEST2_H
#define MIPT2021_2SEM_CONTEST2_H

namespace contest2 {
    int taskA();
    int taskB();
    int taskC();
    int taskD();
    int taskE();
    int taskF();
    int taskG();
    int taskH();
    int taskI();
    int taskJ();

    int task(char index){
        switch(index) {
            case 'A': return taskA();
            case 'B': return taskB();
            case 'C': return taskC();
            case 'D': return taskD();
            case 'E': return taskE();
            case 'F': return taskF();
//            case 'G': return taskG();
//            case 'H': return taskH();
//            case 'I': return taskI();
//            case 'J': return taskJ();
            default: return 1;
        }
    }
}

#endif //MIPT2021_2SEM_CONTEST2_H
