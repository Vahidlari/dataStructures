#ifndef BASEGRAPH_INCLUDED_
#define BASEGRAPH_INCLUDED_

#include <vector>

using namespace std;

class CUndirectedGraph
{
public:
    using  vertix_index_t = uint32_t;

    CUndirectedGraph() = default;
    CUndirectedGraph(int numberOfVertices);

    void        addEdge(int src, int dst);
    void        print();
    uint32_t    getVertixCount();
    uint32_t    getEdgeCount();
    const vector<vertix_index_t>&  getAdjacents(int v);

private:
    vector<vector<vertix_index_t> > adjacencyListArray;
};
#endif //BASEGRAPH_INCLUDED_