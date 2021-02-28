//
// Created by Meevere on 2/19/2021.
//

#include <iostream>

namespace contest3 {

    class Map{
    private:
        int* map;
        int sizeX, sizeY;

    public:
        // stands for get_pointer
        int* getp(int x, int y){
            if ( x < 0 or x >= sizeX )
                throw std::out_of_range("bad index at row range");
            if ( y < 0 or y >= sizeY )
                throw std::out_of_range("bad index at col range");
            return &map[y*sizeY + x];
        }

        int get(int x, int y){
            return *getp(x,y);
        }

        void set(int x, int y, int value){
            *getp(x,y) = value;
        }

        Map( int N, int M ){
            map = new int [N*M];
            sizeX = N; sizeY = M;

            for( int i=0; i<N; i++ )
                for( int j=0; j<M; j++ )
                    set(i,j,0);
        }

        ~Map(){
            delete [] map;
        }

        void add_mine(int x, int y){
            *getp(x,y) = -1;
            for( int i=-1; i<=1; i++ )
                for( int j=-1; j<=1; j++ ){
                    if( i == 0 and j == 0 )
                        continue;
                    try {
                        if( *getp(x+i,y+j) == -1 )
                            continue;
                        (*getp(x+i,y+j))++;
                    } catch (std::out_of_range &e) {}
                }
        }

        void print(){
            for( int i=0; i<sizeX; i++ ) {
                for (int j = 0; j < sizeY; j++)
                    std::cout << get(i, j) << ' ';
                std::cout << '\n';
            }
        }

    };

    int taskB(){
        // N - number of rows, M - number of columns
        int N, M;
        std::cin >> N >> M;

        Map map(N,M);

        // K - number of mines
        int K;
        std::cin >> K;

        int x, y;
        for(int i=0;i<K;i++){
            std::cin >> x >> y;
            map.add_mine(x-1,y-1);
        }

        map.print();

        return 0;
    }

}