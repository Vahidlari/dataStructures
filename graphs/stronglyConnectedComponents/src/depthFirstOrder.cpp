#include "../inc/depthFirstOrder.hpp"

typename CDepthFirstOrder::stack_t CDepthFirstOrder::reverseOrderList(){
    return reverseOrder;
}

typename CDepthFirstOrder::stack_t CDepthFirstOrder::reverseOrderList(CDirectedGraph& graph){
    for(int i = 0; i < graph.getVertixCount(); i++)
    {
        if(!visitedList.contains(i))
        {
            dfs(graph, i);
        }
    }
    return reverseOrder;
}

void CDepthFirstOrder::dfs(CDirectedGraph& graph, vertix_index_t src){
    visitedList.insert(src);
    for(auto& v: graph.getAdjacents(src))
    {
        if(!visitedList.contains(v))
        {
            dfs(graph, v);
        }
    }
    reverseOrder.push_front(src);
}

