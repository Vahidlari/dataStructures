#include "../inc/weightedEdge.hpp"
#include <iostream>

const typename CEdge::vertix_index_t CEdge::either(){
    return srcV;
}

const typename CEdge::vertix_index_t CEdge::other(vertix_index_t v){
    return (v == srcV)? dstV: srcV;
}

const typename CEdge::edge_weight_t CEdge::weight(){
    return w;
}

void CEdge::print(){
    std::cout << "(" << srcV << ", " << dstV << " | " << w << ")";
}

bool CEdge::operator>(const CEdge& other){
    return w > other.w;
}

bool CEdge::operator<(const CEdge& other){
    return w < other.w;
}

bool CEdge::operator==(const CEdge& other){
    return w == other.w;
}

CEdge& CEdge::operator=(const CEdge& other){
    w = other.w;
    srcV = other.srcV;
    dstV = other.dstV;
}