//
// Created by Meevere on 4/14/2021.
//

#include "graph.h"

using namespace graph;
using containers::deque::Deque;
using containers::array::Array;

void NodeAbstract::print_nodes(ostream &os) {
    auto nodes = this->getNodes();
    for( auto elem : *nodes ){
        os << '{' << *elem.first << '|' << elem.second << '}';
    }
}

Graph::Graph(const Array<NodeAbstract *>& arr): matrix(arr.get_size()), vertices(arr) {
    for(int i=0; i<arr.get_size(); i++){
        auto temp = arr[i]->getNodes();
        {
            Array<int> temp2(arr.get_size(), 0);
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

void Graph::_search_width(int index, Array<int>& parents){

    Deque<int> check;
    auto used = Array<bool>(matrix.get_size(), false);

    if (parents.get_size() != matrix.get_size())
        throw std::invalid_argument("wrong size of parent's array");
    for( auto &elem : parents ) {elem = NODE_NO_CONNECTION;}
    parents[index] = NODE_STARTING;

    check << index;

    int cur_index;
    while( check.length > 0 ){
        cur_index << check;
        if(!used[cur_index]){
            used[cur_index] = true;
        }

        for( int i=0; i < matrix[cur_index].get_size(); i++ ){
            if( matrix[cur_index][i] != 0)
                if(!used[i]) {
                    check << i;
                    parents[i] = cur_index;
                }
        }
    }
}

void Graph::_recover_path(Array<int> &arr, int index, List<NodeAbstract *>& deque) {
    std::cout << "Recovering path... : " << *vertices[index] << std::endl;
    if( arr[index] == NODE_NO_CONNECTION )
        return;

    vertices[index] >> deque;

    if( arr[index] == NODE_STARTING)
        return;

    _recover_path(arr, arr[index], deque);
}

List<NodeAbstract*> Graph::closest_path( NodeAbstract* start, NodeAbstract* end){
    int start_index = vertices.find(start);
    int end_index = vertices.find(end);

    List<NodeAbstract*> list;

    if( start_index != -1 and end_index != -1 ) {
        Array<int> parents(matrix.get_size());
        _search_width(start_index, parents);
        std::cout << "Parents array: " << parents << std::endl;
        _recover_path(parents, end_index, list);
    }
    return list;
}