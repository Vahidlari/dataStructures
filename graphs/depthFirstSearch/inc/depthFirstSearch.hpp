#ifndef DEPTHFIRSTSEARCH_INCLUDED_   
#define DEPTHFIRSTSEARCH_INCLUDED_

#include <undirectedGraph.hpp>

class CDfs
{
public:
    using vertix_index_t = typename CUndirectedGraph::vertix_index_t;

    CDfs() = default;
    CDfs(CUndirectedGraph& _graph, vertix_index_t src);

private:
    void dfs(CUndirectedGraph& graph, vertix_index_t src);
    
    vector<bool> visited;
    vector<vertix_index_t> visitedFrom;
    CUndirectedGraph *graph;
};

#endif  //DEPTHFIRSTSEARCH_INCLUDED_