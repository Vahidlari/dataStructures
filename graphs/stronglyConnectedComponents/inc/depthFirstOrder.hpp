#ifndef DEPTHFIRSTORDER_INCLUDED_
#define DEPTHFIRSTORDER_INCLUDED_

#include <deque>
#include <unordered_set>
#include <directedGraph.hpp>

class CDepthFirstOrder
{
public: 
    using vertix_index_t = CDirectedGraph::vertix_index_t;
    using vertix_list_t = unordered_set<vertix_index_t>;
    using stack_t = deque<vertix_index_t>; 

    CDepthFirstOrder() = default;
    stack_t reverseOrderList();
    stack_t reverseOrderList(CDirectedGraph& graph);

private:
    void dfs(CDirectedGraph& graph, vertix_index_t src);

    vertix_list_t visitedList;
    stack_t reverseOrder;
};

#endif //DEPTHFIRSTORDER_INCLUDED_