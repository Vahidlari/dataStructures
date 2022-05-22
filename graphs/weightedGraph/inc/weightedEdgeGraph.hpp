#ifndef WEIGHTEDEDGEGRAPH_INCLUDED_
#define WEIGHTEDEDGEGRAPH_INCLUDED_

#include <vector>
#include "weightedEdge.hpp"
#include <set>

auto cmp = [](const CEdge& a, const CEdge& b) 
{ 
    return CEdge::compareTo(a, b) == -1; 
};


class CWeightedEdgeGraph
{
public:
    using edge_t = CEdge;
    using adjacency_list_t = std::vector<edge_t>;
    using adjacency_list_array_t = std::vector<adjacency_list_t>;
    using sorted_edge_list_t = std::set<edge_t, decltype(cmp)>;

    CWeightedEdgeGraph(int numberOfVertices);
    CWeightedEdgeGraph(const CWeightedEdgeGraph& _graph);
    CWeightedEdgeGraph(const adjacency_list_array_t& _adjancencyListArray);

    void        addEdge(const edge_t& edge);
    void        print();
    uint32_t    getVertixCount();
    uint32_t    getEdgeCount();
    const adjacency_list_t&  getAdjacents(int v);
    sorted_edge_list_t getWeightSortedEdges();

private:
    adjacency_list_array_t adjacencyListArray;
};

#include "weightedEdgeGraph.inl"
//  typename CWeightedEdgeGraph::sorted_edge_list_t CWeightedEdgeGraph::getWeightSortedEdges()
//  {
//     // auto cmp = [](edge_t a, edge_t b) { return CEdge::compareTo(a, b) == -1; };
//     // std::set<CEdge, decltype(cmp)> edgeSet;
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

#endif //WEIGHTEDEDGEGRAPH_INCLUDED_