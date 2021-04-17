//
// Created by Meevere on 4/14/2021.
//

#include "graph.h"

using namespace graph;
using containers::deque::Deque;
using containers::array::Array;

Graph::Graph(const Array<NodeAbstract *>& arr): matrix(arr.get_size()), vertices(arr) {
    for(int i=0; i<arr.get_size(); i++){
        auto temp = arr[i]->getNodes();
        {
            Array<int> temp2(arr.get_size(), -1);
            matrix[i] = temp2;
        }
        for( auto node : *temp ){
            int index = arr.find(node.first);
            if( index != -1 ){
                matrix[i][index] = node.second;
            }
        }
    }
}

void Graph::print(){
    for( Array<int>& arr : matrix ){
        std::cout << arr << '\n';
    }
}

Array<int>* Graph::_search_width(int index){
    Deque<int> check;
    auto used = Array<bool>(matrix.get_size(), false);
    auto parents = new Array<int>(matrix.get_size(), -1);
    check << index;

    int cur_index;
    while( check.length > 0 ){
        cur_index << check;
        if(!used[cur_index]){
            used[cur_index] = true;
        }

        for( int i=0; i < matrix[cur_index].get_size(); i++ ){
            if( matrix[cur_index][i] != -1)
                if(!used[i]) {
                    check << i;
                    (*parents)[i] = cur_index;
                }
        }
    }
    return parents;
}

void Graph::_recover_path(Array<int> *arr, int index, Deque<NodeAbstract *>& deque) {
    if( (*arr)[index] == -1 )
        return;
    deque << vertices[index];
    _recover_path(arr, (*arr)[index], deque);
}

Deque<NodeAbstract*>* Graph::closest_path( NodeAbstract* start, NodeAbstract* end ){
    int start_index = vertices.find(start);
    int end_index = vertices.find(end);

    auto deque = new Deque<NodeAbstract*>;
    if( start_index != -1 and end_index != -1 ) {
        Array<int> *parents = _search_width(start_index);
        _recover_path(parents, end_index, *deque);
        return deque;
    }
    return nullptr;
}