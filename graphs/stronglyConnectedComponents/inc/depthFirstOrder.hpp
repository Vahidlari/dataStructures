#ifndef DEPTHFIRSTORDER_INCLUDED_
#define DEPTHFIRSTORDER_INCLUDED_

#include <deque>
#include <unordered_set>
#include <directedGraph.hpp>
#include <util.hpp>

class CDepthFirstOrder
{
public: 
    using vertix_index_t = CDirectedGraph::vertix_index_t;
    using vertix_list_t = unordered_set<vertix_index_t>;
    using stack_t = deque<vertix_index_t>; 

    CDepthFirstOrder() = default;
    stack_t postOrderList();
    /// Provides a list of reverse post order of the visited nodes during a DFS. 
    /// Basically, the reverse post order list represent the topological order of a 
    /// Directed Acyclic Graph (DAG). Note, a topological order can be derived only and if only 
    /// a graph is a DAG.
    /// Reverse post order vetices are derived once a node is fully visited, including its edges.
    stack_t postOrderList(CDirectedGraph& graph);

private:
    void dfs(CDirectedGraph& graph, vertix_index_t src);

    vertix_list_t visitedList;
    vertix_list_t vertixRecursionStack;
    stack_t postOrder;
    bool isGraphCyclic;
};

#endif //DEPTHFIRSTORDER_INCLUDED_