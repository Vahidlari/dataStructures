#ifndef DIRECTEDGRAPH_INCLUDCED_
#define DIRECTEDGRAPH_INCLUDCED_

#include <vector>

using namespace std;

class CDirectedGraph
{
public:
    using  vertix_index_t = uint32_t;
    using  adjacencyList_t = vector<vertix_index_t>;
    using  adjacencyListArray_t = vector<adjacencyList_t>;

    CDirectedGraph() = default;
    CDirectedGraph(int numberOfVertices);
    CDirectedGraph(const CDirectedGraph& _graph);
    CDirectedGraph(const adjacencyListArray_t& _adjancencyListArray);

    void        addEdge(int src, int dst);
    void        print();
    uint32_t    getVertixCount();
    uint32_t    getEdgeCount();
    const adjacencyList_t&  getAdjacents(int v);

    CDirectedGraph  reverse();
    CDirectedGraph& operator=(const CDirectedGraph& right);

private:
    adjacencyListArray_t adjacencyListArray;
    adjacencyListArray_t getReverseAdjListArray();
};
#endif //DIRECTEDGRAPH_INCLUDCED_