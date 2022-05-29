#include "../inc/vertixDistanceSet.hpp"
#include <iostream>

void CVertixDistancePriorityList::insert(vertix_index_t idx, edge_weight_t w)
{
    priorityList.insert(vertix_distance_pair_t(idx,w));
}

void CVertixDistancePriorityList::update(vertix_index_t idx, edge_weight_t w)
{
    vertix_distance_pair_list_t::iterator it = get(idx);
    priorityList.erase(it);
    insert(idx, w); 
}

typename CVertixDistancePriorityList::vertix_distance_pair_t CVertixDistancePriorityList::popMin()
{
    vertix_distance_pair_list_t::iterator it = priorityList.begin();
    vertix_distance_pair_t rtn = *it;
    priorityList.erase(it);
    return rtn;
}

typename CVertixDistancePriorityList::vertix_distance_pair_list_t::iterator CVertixDistancePriorityList::get(vertix_index_t idx)
{
    vertix_distance_pair_list_t::iterator it = priorityList.begin();
    while(it != priorityList.end() && it->first != idx)
    {
        ++it;
    }
    return it;
}

bool CVertixDistancePriorityList::contains(vertix_index_t idx)
{
    return get(idx) != priorityList.end();
}

bool CVertixDistancePriorityList::isEmpty()
{
    return priorityList.empty();
}

void CVertixDistancePriorityList::print()
{
    for(auto& element: priorityList)
    {
        std::cout << "Vertix: " << element.first << ", dist: " << element.second << std::endl;
    }
}


