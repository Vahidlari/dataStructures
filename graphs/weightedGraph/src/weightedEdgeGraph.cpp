#include "../inc/weightedEdgeGraph.hpp"
#include <iostream>

CWeightedEdgeGraph::CWeightedEdgeGraph(int numberOfVertices){
    adjacencyListArray.resize(numberOfVertices);
}

CWeightedEdgeGraph::CWeightedEdgeGraph(const CWeightedEdgeGraph& _graph){
    adjacencyListArray = _graph.adjacencyListArray;
}

CWeightedEdgeGraph::CWeightedEdgeGraph(const adjacency_list_array_t& _adjancencyListArray){
    adjacencyListArray = _adjancencyListArray;
}

void CWeightedEdgeGraph::addEdge(const edge_t& edge){
    CEdge tmp = edge;

    int v = tmp.either();
    int w = tmp.other(v);
    adjacencyListArray[v].push_back(tmp);
    adjacencyListArray[w].push_back(tmp);
}

void CWeightedEdgeGraph::print(){
    for(int v = 0; v < adjacencyListArray.size(); v++)
    {
        std::cout << v << ": ";
        for(auto& edge : adjacencyListArray[v])
        {
            edge.print();
            std::cout << ", ";
        }
        std::cout << std::endl;
    }
}

uint32_t CWeightedEdgeGraph::getVertixCount(){
    return adjacencyListArray.size();
}

uint32_t CWeightedEdgeGraph::getEdgeCount(){
    int size = 0;
    for(auto& vertixAdjacencyList: adjacencyListArray)
    {
        size += vertixAdjacencyList.size();
    }
    return size;
}

const typename CWeightedEdgeGraph::adjacency_list_t&  CWeightedEdgeGraph::getAdjacents(int v){
    return adjacencyListArray[v];
}
