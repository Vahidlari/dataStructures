#include "../inc/depthFirstSearch.hpp"
#include <iostream>

CDfs::CDfs(CUndirectedGraph& _graph, vertix_index_t _src){
    graph = &_graph;
    src = _src;
    uint32_t vertixCount = graph->getVertixCount();
    visited.resize(vertixCount);
    visitedFrom.resize(vertixCount);
    dfs(_graph, src);
}

void CDfs::dfs(CUndirectedGraph& graph, vertix_index_t src)
{
    //#ifdef PRINT_ENABLED
    std::cout << "** Finding adjancent vertices close to " << src << "\n";
    //#endif
    visited[src] = true;
    for(auto& adjacentVertix : graph.getAdjacents(src))
    {
        if(!visited[adjacentVertix])
        {
            //#ifdef PRINT_ENABLED
            std::cout << "CHK " << adjacentVertix << "\n";
            //#endif
            visitedFrom[adjacentVertix] = src;
            dfs(graph, adjacentVertix);
        }
        //#ifdef PRINT_ENABLED
        else {
            std::cout << "NCHK " << adjacentVertix << "\n";
        }
        //#endif
    }
}

bool CDfs::hasPathTo(vertix_index_t dst)
{
    return visited[dst];
}

deque<typename CDfs::vertix_index_t> CDfs::getPathTo(vertix_index_t dst)
{
    deque<vertix_index_t> path;
    if(hasPathTo(dst))
    {
        vertix_index_t tmp = dst; 
        while(tmp != src){
            path.push_front(tmp);
            tmp = visitedFrom[tmp];
        }
        path.push_front(src);
    }
    return path;
}