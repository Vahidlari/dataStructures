#include "../inc/minimumSpanningTree.hpp"

#include "../inc/minimumSpanningTree.hpp"
#include "../inc/unionFind.hpp"
#include <set>

CMinimumSpanningTree::CMinimumSpanningTree(CWeightedEdgeGraph& graph, EMstAlgorithm algorithm){
    switch(algorithm)
    {
        case EMstAlgorithm::kruskal:
            kruskalMst(graph);
            break;
        case EMstAlgorithm::prim:
            primMst(graph);
            break;
        default:
            break;
    }
}

typename CMinimumSpanningTree::adjacency_list_t CMinimumSpanningTree::edges(){
    return mstEdges;
}
/// receives a sorted list of edges in a graph, takes the smallest and checks if the edge does not 
/// create a cycle in the list of selected edges. The cycle creation check is performed by 
/// examining of the ends of an edge are already connected in the selected subtree. The check is 
/// performed using union find algorithm.
/// If not, the edge is added to the union find structure and as well as to the list of selected 
/// edges, and removed from the sorted list.

void CMinimumSpanningTree::kruskalMst(CWeightedEdgeGraph graph){
    sorted_edge_list_t sortedEdgeSet = graph.getWeightSortedEdges();
    sorted_edge_list_t::iterator it = sortedEdgeSet.begin();
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

/// The algorithm keeps a list of visited vetices and a sorted list of the edges connected to the selected edges.
/// Each time a new vertix is added, all its connected edges, except of those eding to a visiting vertix, shall be added to the sort list.
/// In each round, an edge with smallest weight is taken and the iteration continues till the sorted list is empty.
void CMinimumSpanningTree::primMst(CWeightedEdgeGraph graph){
    std::vector<bool> visited(graph.getVertixCount(), false);
    sorted_edge_list_t sortedEdgeSet;
    visit(0, graph.getAdjacents(0), visited, sortedEdgeSet);
    while(!sortedEdgeSet.empty())
    {
        sorted_edge_list_t::iterator it = sortedEdgeSet.begin();
        int v = (*it).either();
        int w = (*it).other(v);
        if(!visited[v] || !visited[w])
        {
            mstEdges.push_back(*it);
            std::cout << "Added ";
            it->print();
            std::cout << "to the MST\n";
            if(!visited[v])
            {
                visit(v, graph.getAdjacents(v), visited, sortedEdgeSet);
            }
            if(!visited[w])
            {
                visit(w, graph.getAdjacents(w), visited, sortedEdgeSet);
            }
        }
        sortedEdgeSet.erase(it);
    }
}

void CMinimumSpanningTree::visit(int vertix, adjacency_list_t vertixAdjacencyList, std::vector<bool>& visited, sorted_edge_list_t& sortedEdgeList)
{
    std::cout << "Visiting " << vertix << ", edges --> ";
    visited[vertix] = true;
    for (CEdge& edge: vertixAdjacencyList)
    {
        int w = edge.other(vertix);
        if(!visited[w])
        {
            edge.print();
            std::cout << ", ";
            sortedEdgeList.insert(edge);
        }
    }
    std::cout << "\n";
}