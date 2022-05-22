#include "../inc/minimumSpanningTree.hpp"

#include "../inc/minimumSpanningTree.hpp"
#include "../inc/unionFind.hpp"
#include <set>

CMinimumSpanningTree::CMinimumSpanningTree(CWeightedEdgeGraph& graph){
    kruskalMts(graph);
}

typename CMinimumSpanningTree::adjacency_list_t CMinimumSpanningTree::edges(){
    return mstEdges;
}

void CMinimumSpanningTree::kruskalMts(CWeightedEdgeGraph graph){
    CWeightedEdgeGraph::sorted_edge_list_t sortedEdgeSet = graph.getWeightSortedEdges();
    CWeightedEdgeGraph::sorted_edge_list_t::iterator it = sortedEdgeSet.begin();
    CUnionFind myUf(graph.getVertixCount());
    while(!sortedEdgeSet.empty() && (mstEdges.size() < graph.getVertixCount() - 1))
    {
        it = sortedEdgeSet.begin();
        std::cout << "Evaluating ";
        it->print();
        std::cout << std::endl;

        vertix_index_t v = (*it).either();
        vertix_index_t w = (*it).other(v);
        if(!myUf.connected(v,w)){
            myUf.addUnion(v,w);
            mstEdges.push_back(*it);
            std::cout << "\tAdded a new edge to the MST list, size " << mstEdges.size() << std::endl;
        } else 
        {
            std::cout << "\tSkipped the edge, size " << mstEdges.size() << std::endl;
        }
        sortedEdgeSet.erase(it);
    }
}

void CMinimumSpanningTree::printMst()
{
    for(auto& edge : mstEdges)
    {
        edge.print();
    }
    std::cout << std::endl;
}