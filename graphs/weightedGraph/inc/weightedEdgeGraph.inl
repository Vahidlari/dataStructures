
inline typename CWeightedEdgeGraph::sorted_edge_list_t CWeightedEdgeGraph::getWeightSortedEdges()
{
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