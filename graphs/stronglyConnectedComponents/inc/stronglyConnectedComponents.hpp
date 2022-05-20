#ifndef CONNECTEDCOMPONENTS_INCLUDED_   
#define CONNECTEDCOMPONENTS_INCLUDED_

#include <directedGraph.hpp>
#include <deque>

class CStronglyConnectedComponents
{
public:
    using vertix_index_t = typename CDirectedGraph::vertix_index_t;

    CStronglyConnectedComponents() = default;
    CStronglyConnectedComponents(CDirectedGraph& _graph);
    bool areConnected(vertix_index_t first, vertix_index_t second);
    uint32_t getNumberOfComponents();
    void printConnectedComponents();

private:
    void dfs(CDirectedGraph& graph, vertix_index_t src);
    
    vector<bool> visited;
    vector<vertix_index_t> visitedFrom;
    vector<vertix_index_t> componentId;
    CDirectedGraph *graph;
    uint32_t componentCount;
};

#endif  //CONNECTEDCOMPONENTS_INCLUDED_