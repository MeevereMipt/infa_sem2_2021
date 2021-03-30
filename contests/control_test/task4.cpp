//
// Created by EGor on 30.03.2021.
//

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

namespace control {

    struct Vehicle {
        unsigned int id;
        char name[20];
        bool is_visible;
        int type;        // 0 - car, 1 - bike, 2 - horse, 3 - human
        float x, y, z;        // coordinates
        float vx, vy, vz;    // velocity
    };

    unsigned int is_an_invisible_bike(Vehicle *v, unsigned int n) {
        unsigned int counter = 0;
        for (unsigned int i = 0; i < n; i++) {
            if (!v[i].is_visible and v[i].type == 1)
                counter++;
        }
        return counter;
    }

    int task4() {
        Vehicle stat[5] = {
                {48678, "Astra",     true,  0, 0,   0,   0, 1,  1,  0},
                {23455, "Kusanagi",  false, 1, 100, 0,   0, 1,  1,  0},
                {35463, "Chevalier", false, 0, 0,   0,   0, 1,  1,  0},
                {82634, "Scorpion",  true,  1, 0,   0,   0, 10, 10, 0},
                {23434, "Excalibur", false, 0, 1,   100, 0, 0,  0,  0}
        };
        cout << is_an_invisible_bike(stat, 5) << endl; // ваша функция должна найти тут один невидимый мотоцикл
        return 0;
    }

}