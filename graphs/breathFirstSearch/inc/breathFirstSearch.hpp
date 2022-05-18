#ifndef BREATHFIRSTSEARCH_INCLUDED_   
#define BREATHFIRSTSEARCH_INCLUDED_

#include <undirectedGraph.hpp>
#include <deque>

class CBfs
{
public:
    using vertix_index_t = typename CUndirectedGraph::vertix_index_t;

    CBfs() = default;
    CBfs(CUndirectedGraph& _graph, vertix_index_t src);
    bool hasPathTo(vertix_index_t dst);
    deque<vertix_index_t> getPathTo(vertix_index_t dst);

private:
    void bfs(CUndirectedGraph& graph, vertix_index_t src);
    
    vector<bool> visited;
    vector<vertix_index_t> visitedFrom;
    CUndirectedGraph *graph;
    vertix_index_t   src;
};

#endif  //BREATHFIRSTSEARCH_INCLUDED_