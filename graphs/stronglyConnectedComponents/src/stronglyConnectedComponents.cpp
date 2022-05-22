#include "../inc/stronglyConnectedComponents.hpp"
#include <iostream>

CStronglyConnectedComponents::CStronglyConnectedComponents(CDirectedGraph& _graph){
    graph = &_graph;
    uint32_t vertixCount = graph->getVertixCount();
    visited.resize(vertixCount);
    visitedFrom.resize(vertixCount);
    componentId.resize(vertixCount);
    componentCount = 0;
    CDepthFirstOrder dfo;
    CDirectedGraph reverseGraph = _graph.reverse();
    stack_t reversePostOrderList = dfo.postOrderList(reverseGraph);
    print(reversePostOrderList);

    for(auto& v : reversePostOrderList)
    {
        if(!visited[v])
        {
            ++componentCount;
            dfs(_graph, v);
        }
    }
}

void CStronglyConnectedComponents::dfs(CDirectedGraph& graph, vertix_index_t src)
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

bool CStronglyConnectedComponents::areConnected(vertix_index_t first, vertix_index_t second){
    return componentId[first] == componentId[second];
}

uint32_t CStronglyConnectedComponents::getNumberOfComponents(){
    return componentCount;
}

void CStronglyConnectedComponents::printConnectedComponents(){
    for(uint32_t idx = 0; idx < componentCount; ++idx){
        std::cout << "Component " << idx  << ": ";
        for(uint32_t i = 0; i < componentId.size(); ++i){
            if(idx == componentId[i]){
                std::cout << i << ", ";
            }
        }
        std::cout << std::endl;
    }
}
