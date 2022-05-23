#ifndef MINIMUMSPANNINGTREE_INCLUDED_
#define MINIMUMSPANNINGTREE_INCLUDED_

#include <deque>
#include <unordered_set>
#include <weightedEdgeGraph.hpp>
#include <util.hpp>

enum class EMstAlgorithm
{
    kruskal,
    prim
};

class CMinimumSpanningTree
{
public: 


    using adjacency_list_t = CWeightedEdgeGraph::adjacency_list_t;
    using edge_weight_t = CEdge::edge_weight_t;
    using vertix_index_t = CEdge::vertix_index_t;
    using sorted_edge_list_t = CWeightedEdgeGraph::sorted_edge_list_t;

    CMinimumSpanningTree(CWeightedEdgeGraph& graph, EMstAlgorithm algorithm);

    adjacency_list_t edges();
    void printMst();


private:
    void kruskalMst(CWeightedEdgeGraph graph);
    void primMst(CWeightedEdgeGraph graph);
    void visit(int vertix, adjacency_list_t vertixAdjacencyList, std::vector<bool>& visited, sorted_edge_list_t& sortedEdgeList);

    adjacency_list_t mstEdges;

};

#endif //MINIMUMSPANNINGTREE_INCLUDED_