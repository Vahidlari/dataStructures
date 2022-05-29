#ifndef DIRECTEDWEIGHTEDEDGEGRAPH_INCLUDED_
#define DIRECTEDWEIGHTEDEDGEGRAPH_INCLUDED_

#include <vector>
#include "directedWeightedEdge.hpp"
#include <set>

auto directedWeightedEdgeCompare = [](const CDWEdge& a, const CDWEdge& b) 
{ 
    return CDWEdge::compareTo(a, b) == -1; 
};


class CDirectedWeightedEdgeGraph
{
public:
    using edge_t = CDWEdge;
    using virtex_index_t = edge_t::vertix_index_t;
    using adjacency_list_t = std::vector<edge_t>;
    using adjacency_list_array_t = std::vector<adjacency_list_t>;
    using sorted_edge_list_t = std::set<edge_t, decltype(directedWeightedEdgeCompare)>;

    CDirectedWeightedEdgeGraph(int numberOfVertices);
    CDirectedWeightedEdgeGraph(const CDirectedWeightedEdgeGraph& _graph);
    CDirectedWeightedEdgeGraph(const adjacency_list_array_t& _adjancencyListArray);

    void        addEdge(const edge_t& edge);
    void        print();
    uint32_t    getVertixCount();
    uint32_t    getEdgeCount();
    const adjacency_list_t&  getAdjacents(virtex_index_t v);
    sorted_edge_list_t getWeightSortedEdges();

private:
    adjacency_list_array_t adjacencyListArray;
};

#include "directedWeightedEdgeGraph.inl"
//  typename CWeightedEdgeGraph::sorted_edge_list_t CWeightedEdgeGraph::getWeightSortedEdges()
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

#endif //DIRECTEDWEIGHTEDEDGEGRAPH_INCLUDED_