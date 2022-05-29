
inline typename CDirectedWeightedEdgeGraph::sorted_edge_list_t CDirectedWeightedEdgeGraph::getWeightSortedEdges()
{
    // auto cmp = [](edge_t a, edge_t b) { return CEdge::compareTo(a, b) == -1; };
    // std::set<CEdge, decltype(cmp)> edgeSet;
    sorted_edge_list_t edgeSet;

    for(int v = 0; v < adjacencyListArray.size(); v++)
    {
        for(edge_t& edge : adjacencyListArray[v])
        {
            if(!edgeSet.contains(edge))
            {
                edgeSet.insert(edge);
            }
        }
    }
    return edgeSet;  
}