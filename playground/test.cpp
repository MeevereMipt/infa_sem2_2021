//
// Created by EGor on 13.04.2021.
//

#include <iostream>
#include "containers/array.h"
#include "containers/list.h"
#include "playground.h"
#include "graph.h"

//using namespace graph;
using containers::array::Array;
using containers::list::List;

namespace playground {
//     chess square
//    struct Square: public NodeAbstract {
//        int x, y;
//        typedef Array<Array<Square*>> map;
//        map* chess;
//
//        Square(int _x, int _y){
//            x = _x; y = _y; chess = nullptr;
//        }
//
//        void set_board_ptr(map* ptr){
//            chess = ptr;
//        }
//
//        Deque<pair<NodeAbstract*,int>> getNodes(){
//
//            for(int i=-1; i<2; i+=2){
//                for(int j=-1; j<2; j+=2){
//                    for(int k=-1; k<2; k+=2){
//                        try {
//
//                        }
//                    }
//                }
//            }
//        }
//
//    };

    int test() {
        List ls = {1,2,3,6};

        std::cout << ls;

        return 0;
    }
}