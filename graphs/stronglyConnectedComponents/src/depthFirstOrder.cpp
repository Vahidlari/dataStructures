#include "../inc/depthFirstOrder.hpp"

typename CDepthFirstOrder::stack_t CDepthFirstOrder::postOrderList(){
    return postOrder;
}

typename CDepthFirstOrder::stack_t CDepthFirstOrder::postOrderList(CDirectedGraph& graph){
    for(int i = 0; i < graph.getVertixCount(); i++)
    {
        if(!visitedList.contains(i))
        {
            dfs(graph, i);
        }
    }
    return postOrder;
}

void CDepthFirstOrder::dfs(CDirectedGraph& graph, vertix_index_t src){
    visitedList.insert(src);
    vertixRecursionStack.insert(src);
    std::cout << std::endl << "Added " << src << " to the visited List and running dfs: ";
    for(auto& v: graph.getAdjacents(src))
    {
        if(!visitedList.contains(v) && !isGraphCyclic)
        {
            dfs(graph, v);
        } else if(vertixRecursionStack.contains(v))
        {
            isGraphCyclic = true;
            std::cout << "Graph is cyclic! Node " << v << " is in the recursion stack!\n";
            return;
        }
    }
    vertixRecursionStack.erase(src);
    postOrder.push_front(src);
    std::cout << "Pushed " << src << " to the post order List\n";
}

