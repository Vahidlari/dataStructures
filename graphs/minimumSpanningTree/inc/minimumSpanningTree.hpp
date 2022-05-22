#ifndef MINIMUMSPANNINGTREE_INCLUDED_
#define MINIMUMSPANNINGTREE_INCLUDED_

#include <deque>
#include <unordered_set>
#include <weightedEdgeGraph.hpp>
#include <util.hpp>

class CMinimumSpanningTree
{
public: 
    using adjacency_list_t = CWeightedEdgeGraph::adjacency_list_t;
    using edge_weight_t = CEdge::edge_weight_t;
    using vertix_index_t = CEdge::vertix_index_t;

    CMinimumSpanningTree(CWeightedEdgeGraph& graph);

    adjacency_list_t edges();
    void printMst();


private:
    void kruskalMts(CWeightedEdgeGraph graph);
    
    adjacency_list_t mstEdges;

};

#endif //MINIMUMSPANNINGTREE_INCLUDED_