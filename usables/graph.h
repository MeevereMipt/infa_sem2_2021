//
// Created by EGor on 13.04.2021.
//

#ifndef MIPT2021_2SEM_GRAPH_H
#define MIPT2021_2SEM_GRAPH_H

#include "containers/array.h"
#include "containers/deque.h"
#include <iostream>


using std::pair;
using containers::array::Array;
using containers::deque::Deque;

namespace graph {

    class NodeAbstract{
    public:
        // array of adjacent nodes and weights
        // like [(B,2),(C,3),(D,4)]
        virtual Array<pair<NodeAbstract*, int>>* getNodes() = 0;
        virtual bool operator== (const NodeAbstract& n) = 0;
    };

    class Graph{
    public:
        // матрица смежности/adjacency matrix
        // value - weight of edge
        // if -1 - no edge

        Array<Array<int>> matrix;
        Array<NodeAbstract*> vertices;

        explicit Graph(const Array<NodeAbstract *>& arr);

        // closest in terms of number of vertices, not actual path-weights
        // returns deque of nodes such that neighbouring nodes have the connection
        Deque<NodeAbstract*>* closest_path( NodeAbstract* start, NodeAbstract* end );
        void print();

//        Deque<NodeAbstract*>* shortest_path( NodeAbstract* start, NodeAbstract* end );

    protected:

        // returns array of parents to each vertex (that correspond to the closest path to initial point)
        Array<int>* _search_width( int index );

        //
        void  _recover_path(Array<int>* arr, int index, Deque<NodeAbstract*>& deque);

    };

}

#endif //MIPT2021_2SEM_GRAPH_H
