//
// Created by EGor on 13.04.2021.
//

#include <iostream>
#include "containers/array.h"
#include "containers/list.h"
#include "playground.h"
#include "graph.h"

using namespace graph;
using containers::array::Array;
using containers::list::List;

namespace playground {
//     chess square
    struct Square: public NodeAbstract {
        int x, y;
        typedef Array<Array<Square>> map;
        map* chess;
        List<pair<NodeAbstract*,int>>* nodes;

        Square(int _x, int _y){
            x = _x; y = _y; chess = nullptr; nodes = nullptr;
        }

        Square():Square(0,0){};

        ~Square(){
            if(nodes)
                delete nodes;
        }

        void set_board_ptr(map* ptr){
            chess = ptr;
        }

        List<pair<NodeAbstract*,int>>* getNodes(){
            if (!nodes)
                setNodes();
            return nodes;
        }

        ostream& print(ostream& os) const{
            return os << '(' << x << ' ' << y << ')';
        }

    protected:
        void setNodes() {
            delete [] nodes;
            nodes = new List<pair<NodeAbstract*,int>>;
            for(int i=-1; i<2; i+=2)
                for(int j=-1; j<2; j+=2)
                    for(int k=-1; k<1; k++)
                        try {
                            Square* temp;
                            temp = &((*chess)[x+(1-k)*i][y+(2+k)*j]);

                            pair<NodeAbstract*,int> temp2;
                            temp2.first = temp; temp2.second = 1;
                            (*nodes) << temp2;
                        } catch (std::out_of_range &exp) {}

        }

    };

    int test() {

        int size = 3;

        Array<Array<Square>> map(size,Array<Square>(size));
        for(int i=0; i<size; i++)
            for(int j=0; j<size; j++){
                Square* temp = &map[i][j];
                temp->chess = &map;
                temp->x = i; temp->y = j;
            }

        std::cout << map << std::endl;
        map[0][0].print_nodes(std::cout); std::cout << std::endl;

        Array<NodeAbstract*> lin_map(size*size);
        for(int i=0; i<size; i++)
            for(int j=0; j<size; j++){
                lin_map[i+size*j] = &map[i][j];
            }

        Graph graph(lin_map);
        graph.print();

        auto path = graph.closest_path(&map[0][0], &map[1][0]);
        for( auto elem : path ){
            std::cout << *elem << ' ';
        }

        return 0;
    }
}