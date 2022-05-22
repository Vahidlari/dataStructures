#ifndef WEIGHTEDEDGEGRAPH_INCLUDED_
#define WEIGHTEDEDGEGRAPH_INCLUDED_

#include <vector>
#include "weightedEdge.hpp"

class CWeightedEdgeGraph
{
public:
    using edge_t = CEdge;
    using adjacency_list_t = std::vector<edge_t>;
    using adjacency_list_array_t = std::vector<adjacency_list_t>;

    CWeightedEdgeGraph(int numberOfVertices);
    CWeightedEdgeGraph(const CWeightedEdgeGraph& _graph);
    CWeightedEdgeGraph(const adjacency_list_array_t& _adjancencyListArray);

    void        addEdge(const edge_t& edge);
    void        print();
    uint32_t    getVertixCount();
    uint32_t    getEdgeCount();
    const adjacency_list_t&  getAdjacents(int v);

private:
    adjacency_list_array_t adjacencyListArray;
};

#endif //WEIGHTEDEDGEGRAPH_INCLUDED_