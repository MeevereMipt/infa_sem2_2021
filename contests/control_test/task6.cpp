//
// Created by EGor on 30.03.2021.
//

#include <iostream>
using std::cout;
using std::endl;

namespace control {

#define JOHNNY 0

    struct Track {
        char name[100];
        unsigned int album, number_on_album;
        unsigned int min, sec;
        int rating_critics, rating_people;
        unsigned int author; // 0 - Johnny, 1 - Kerry, 2 - Nancy, 3 - Denny, 4 - Henry
        unsigned long id;
    };

    void rip_samurai(const Track *all_songs, unsigned int all_n, Track **in_memoriam_johnny, unsigned int *johnny_n){
        unsigned int count = 0;

        // можно сделать по умному - один раз проходить (через листы мб, но я не буду это делать)
        for( unsigned int i=0; i < all_n; i++){
            if( all_songs[i].author == JOHNNY )
                count++;
        }

        auto johnny_tracks = new Track[count];
        count = 0;

        for( unsigned int i=0; i < all_n; i++){
            if( all_songs[i].author == JOHNNY ) {
                johnny_tracks[count] = all_songs[i]; //так можно делать, так как структура простая
                count++;
            }
        }

        *johnny_n = count;
        *in_memoriam_johnny = johnny_tracks; //does it work? yes!
    }
// Здесь ваша реализация функции

    int task6() {
        Track all_tracks[] = {
                {"Blistering Love", 2003, 3, 3, 23, 68, 97, 0, 465321},
                {"Five Rings",      2003, 7, 4, 33, 75, 80, 3, 538743},
                {"Bleed the Beat",  0,    0, 3, 12, 65, 76, 4, 52433},
                {"War Crisis",      2020, 4, 2, 58, 78, 67, 0, 587545},
                {"Chippin' In",     2020, 6, 4, 55, 95, 98, 0, 63587}
        };

        Track *in_memoriam_johnny = nullptr;
        unsigned int johnny_n = 0;
        rip_samurai(all_tracks, 5, &in_memoriam_johnny, &johnny_n);

        for (unsigned int i = 0; i < johnny_n; i++)
            cout << i << "\t" << in_memoriam_johnny[i].name << "\t" << in_memoriam_johnny[i].id << endl;

// ожидаемый результат:
// 0       Blistering Love 465321
// 1       War Crisis      587545
// 2       Chippin' In     63587

        delete[] in_memoriam_johnny;
        return 0;
    }
}