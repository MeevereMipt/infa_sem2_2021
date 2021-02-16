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
            case 'A':
                taskA();
                break;
            case 'B':
                taskB();
                break;
            case 'C':
                taskC();
                break;
            case 'D':
                taskD();
                break;
            case 'E':
                taskE();
                break;
            case 'F':
                taskF();
                break;
            case 'G':
                taskG();
                break;
            case 'H':
                taskH();
                break;
            default:
                break;
        }

        return 0;
    }
}

#endif //MIPT2021_2SEM_CONTEST3_H
