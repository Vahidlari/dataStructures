#ifndef DEPTHFIRSTSEARCH_INCLUDED_   
#define DEPTHFIRSTSEARCH_INCLUDED_

#include <undirectedGraph.hpp>
#include <deque>

class CDfs
{
public:
    using vertix_index_t = typename CUndirectedGraph::vertix_index_t;

    CDfs() = default;
    CDfs(CUndirectedGraph& _graph, vertix_index_t src);
    bool hasPathTo(vertix_index_t dst);
    deque<vertix_index_t> getPathTo(vertix_index_t dst);

private:
    void dfs(CUndirectedGraph& graph, vertix_index_t src);
    
    vector<bool> visited;
    vector<vertix_index_t> visitedFrom;
    CUndirectedGraph *graph;
    vertix_index_t   src;
};

#endif  //DEPTHFIRSTSEARCH_INCLUDED_