//
// Created by EGor on 13.04.2021.
//

#ifndef MIPT2021_2SEM_MY_GRAPH_H
#define MIPT2021_2SEM_MY_GRAPH_H

#include "containers/array.h"
#include <iostream>

using std::pair;
using containers::array::Array;

namespace my_graph {

    class NodeAbstract{
    public:
        // array of adjasment nodes
        // like [B,C,D]
        virtual Array<pair<NodeAbstract*, int>>* getNodes() = 0;
        virtual bool operator== (const NodeAbstract& n) = 0;
    };

    class Graph{
    public:
        // visual example:
        // A: [(B,1), (C,1), D]
        // B: [(A, C];
        // C: [A, B];
        //
        Array<Array<pair<NodeAbstract*, int>>> list;

    };

}

#endif //MIPT2021_2SEM_MY_GRAPH_H
