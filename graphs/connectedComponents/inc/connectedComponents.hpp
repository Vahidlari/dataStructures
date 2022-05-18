#ifndef CONNECTEDCOMPONENTS_INCLUDED_   
#define CONNECTEDCOMPONENTS_INCLUDED_

#include <undirectedGraph.hpp>
#include <deque>

class CConnectedComponents
{
public:
    using vertix_index_t = typename CUndirectedGraph::vertix_index_t;

    CConnectedComponents() = default;
    CConnectedComponents(CUndirectedGraph& _graph);
    bool areConnected(vertix_index_t first, vertix_index_t second);
    uint32_t getNumberOfComponents();
    void printConnectedComponents();

private:
    void dfs(CUndirectedGraph& graph, vertix_index_t src);
    
    vector<bool> visited;
    vector<vertix_index_t> visitedFrom;
    vector<vertix_index_t> componentId;
    CUndirectedGraph *graph;
    uint32_t componentCount;
};

#endif  //CONNECTEDCOMPONENTS_INCLUDED_