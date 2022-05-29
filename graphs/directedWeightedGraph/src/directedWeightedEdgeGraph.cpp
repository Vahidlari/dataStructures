#include "../inc/directedWeightedEdgeGraph.hpp"
#include <iostream>

CDirectedWeightedEdgeGraph::CDirectedWeightedEdgeGraph(int numberOfVertices){
    adjacencyListArray.resize(numberOfVertices);
}

CDirectedWeightedEdgeGraph::CDirectedWeightedEdgeGraph(const CDirectedWeightedEdgeGraph& _graph){
    adjacencyListArray = _graph.adjacencyListArray;
}

CDirectedWeightedEdgeGraph::CDirectedWeightedEdgeGraph(const adjacency_list_array_t& _adjancencyListArray){
    adjacencyListArray = _adjancencyListArray;
}

void CDirectedWeightedEdgeGraph::addEdge(const edge_t& edge){
    edge_t tmp = edge;

    int v = tmp.from();
    adjacencyListArray[v].push_back(tmp);
}

void CDirectedWeightedEdgeGraph::print(){
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

uint32_t CDirectedWeightedEdgeGraph::getVertixCount(){
    return adjacencyListArray.size();
}

uint32_t CDirectedWeightedEdgeGraph::getEdgeCount(){
    int size = 0;
    for(auto& vertixAdjacencyList: adjacencyListArray)
    {
        size += vertixAdjacencyList.size();
    }
    return size;
}

const typename CDirectedWeightedEdgeGraph::adjacency_list_t&  CDirectedWeightedEdgeGraph::getAdjacents(int v){
    return adjacencyListArray[v];
}

//  typename CDirectedWeightedEdgeGraph::sorted_edge_list_t CDirectedWeightedEdgeGraph::getWeightSortedEdges()
//  {
//     // auto cmp = [](edge_t a, edge_t b) { return CDWEdge::compareTo(a, b) == -1; };
//     // std::set<CDWEdge, decltype(cmp)> edgeSet;
//     sorted_edge_list_t edgeSet;

//     for(int v = 0; v < adjacencyListArray.size(); v++)
//     {
//         for(edge_t& edge : adjacencyListArray[v])
//         {
//             if(!edgeSet.contains(edge))
//             {
//                 edgeSet.insert(edge);
//             }
//         }
//     }
//     return edgeSet;  
//  }