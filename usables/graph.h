//
// Created by EGor on 13.04.2021.
//

#ifndef MIPT2021_2SEM_GRAPH_H
#define MIPT2021_2SEM_GRAPH_H

#include "containers/array.h"
#include "containers/deque.h"
#include "containers/list.h"
#include <iostream>

using std::pair;
using containers::list::List;
using containers::array::Array;
using containers::deque::Deque;

namespace graph {

#define NODE_NO_CONNECTION -1
#define NODE_STARTING -2

    class NodeAbstract{
    public:
        // array of adjacent nodes and weights
        // like [(B,2),(C,3),(D,4)]
        virtual List<pair<NodeAbstract*, int>>* getNodes() = 0;
//        virtual bool operator== (const NodeAbstract& n) = 0;

        virtual ostream& print(ostream& os) const = 0;
        void print_nodes(ostream& os);

        friend ostream& operator << (ostream& out, const NodeAbstract& node);
    };

    inline ostream& operator << (ostream& out, const NodeAbstract& node){
        return node.print(out);
    }

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
        List<NodeAbstract*> closest_path( NodeAbstract* start, NodeAbstract* end );
        List<NodeAbstract*> hamiltonian_path();

        void print();

//        Deque<NodeAbstract*>* shortest_path( NodeAbstract* start, NodeAbstract* end );

    protected:

        // returns array of parents to each vertex (that correspond to the closest path to initial point)
        void _search_width( int index, Array<int>& parents);

//        void _search_depth( int index, Array<int>& parents);

        void _recover_path(Array<int>& arr, int index, List<NodeAbstract*>& deque);

    };

}

#endif //MIPT2021_2SEM_GRAPH_H
