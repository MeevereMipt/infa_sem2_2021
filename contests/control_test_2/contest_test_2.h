//
// Created by Meevere on 5/14/2021.
//

#ifndef MIPT2021_2SEM_CONTEST_TEST_2_H
#define MIPT2021_2SEM_CONTEST_TEST_2_H

namespace control2 {
    int task1();
//    int task2();
//    int task3();
//    int task4();
//    int task5();
//    int task6();

    int task(char index){
        switch(index) {
            case '1': return task1();
//            case '2': return task2();
//            case '3': return task3();
//            case '4': return task4();
//            case '5': return task5();
//            case '6': return task6();
            default: return 1;
        }
    }
}


#endif //MIPT2021_2SEM_CONTEST_TEST_2_H
