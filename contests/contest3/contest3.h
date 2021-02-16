//
// Created by EGor on 16.02.2021.
//

#ifndef MIPT2021_2SEM_CONTEST3_H
#define MIPT2021_2SEM_CONTEST3_H

namespace contest3 {
    int taskA();
    int taskB();
    int taskC();
    int taskD();
    int taskE();
    int taskF();
    int taskG();
    int taskH();

    int task(char index){
        switch(index) {
            case 'A': return taskA();
            case 'B': return taskB();
            case 'C': return taskC();
            case 'D': return taskD();
            case 'E': return taskE();
            case 'F': return taskF();
            case 'G': return taskG();
            case 'H': return taskH();
            default: return 1;
        }
    }
}

#endif //MIPT2021_2SEM_CONTEST3_H
