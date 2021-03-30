//
// Created by EGor on 30.03.2021.
//

#ifndef MIPT2021_2SEM_CONTROL_TEST_H
#define MIPT2021_2SEM_CONTROL_TEST_H

namespace control {
    int task1();
    int task2();
    int task3();
    int task4();
    int task5();
    int task6();
    int task7();
    int task8();
    int task9();

    int task(char index){
        switch(index) {
            case '1': return task1();
            case '2': return task2();
            case '3': return task3();
            case '4': return task4();
            case '5': return task5();
            case '6': return task6();
            case '7': return task7();
            case '8': return task8();
            case '9': return task9();
            default: return 1;
        }
    }
}

#endif //MIPT2021_2SEM_CONTROL_TEST_H
