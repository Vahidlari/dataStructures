#include "../inc/connectedComponents.hpp"
#include <iostream>

CConnectedComponents::CConnectedComponents(CUndirectedGraph& _graph){
    graph = &_graph;
    uint32_t vertixCount = graph->getVertixCount();
    visited.resize(vertixCount);
    visitedFrom.resize(vertixCount);
    componentId.resize(vertixCount);
    componentCount = 0;
    for(int i = 0; i < vertixCount; ++i)
    {
        if(!visited[i])
        {
            ++componentCount;
            dfs(_graph, i);
        }
    }
}

void CConnectedComponents::dfs(CUndirectedGraph& graph, vertix_index_t src)
{
    //#ifdef PRINT_ENABLED
    std::cout << "** Finding adjancent vertices close to " << src << "\n";
    //#endif
    visited[src] = true;
    componentId[src] = componentCount-1;
    for(auto& adjacentVertix : graph.getAdjacents(src))
    {
        if(!visited[adjacentVertix])
        {
            //#ifdef PRINT_ENABLED
            std::cout << "CHK " << adjacentVertix << "\n";
            //#endif
            visitedFrom[adjacentVertix] = src;
            componentId[adjacentVertix] = componentCount-1;
            dfs(graph, adjacentVertix);
        }
        //#ifdef PRINT_ENABLED
        else {
            std::cout << "NCHK " << adjacentVertix << "\n";
        }
        //#endif
    }
}

bool CConnectedComponents::areConnected(vertix_index_t first, vertix_index_t second){
    return componentId[first] == componentId[second];
}

uint32_t CConnectedComponents::getNumberOfComponents(){
    return componentCount;
}

void CConnectedComponents::printConnectedComponents(){
    uint32_t idx = componentId.size() + 1;
    for(int i = 0; i < componentId.size(); ++i){
        if(idx != componentId[i]){
            idx = componentId[i];
            std::cout << std::endl << "Component " << idx << ": " << i << ", ";
        } else {
            std::cout << i << ", ";
        }
    }
    std::cout << std::endl;
}
