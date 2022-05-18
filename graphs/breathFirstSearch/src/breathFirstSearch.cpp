#include "../inc/breathFirstSearch.hpp"
#include <iostream>
#include <queue>

CBfs::CBfs(CUndirectedGraph& _graph, vertix_index_t _src){
    graph = &_graph;
    src = _src;
    uint32_t vertixCount = graph->getVertixCount();
    visited.resize(vertixCount);
    visitedFrom.resize(vertixCount);
    bfs(_graph, src);
}

void CBfs::bfs(CUndirectedGraph& graph, vertix_index_t src)
{
    //#ifdef PRINT_ENABLED
    std::cout << "** Finding adjancent vertices close to " << src << "\n";
    //#endif
    visited[src] = true;
    queue<vertix_index_t> vertixQueue;
    vertixQueue.push(src);
    visited[src] = true;
    vertix_index_t v = 0;
    while(!vertixQueue.empty())
    {
        v = vertixQueue.front();
        vertixQueue.pop();
        std::cout << "poped vertix " << v << ": ";
        for(auto& adj : graph.getAdjacents(v)){
            if(!visited[adj])
            {
                std::cout << "CHK " << adj << ", ";
                visitedFrom[adj] = v;
                visited[adj] = true;
                vertixQueue.push(adj);
            } else {
                std::cout << "NCHK " << adj << ", ";
            }
        }  
        std::cout << std::endl;      
    }
}

bool CBfs::hasPathTo(vertix_index_t dst)
{
    return visited[dst];
}

deque<typename CBfs::vertix_index_t> CBfs::getPathTo(vertix_index_t dst)
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