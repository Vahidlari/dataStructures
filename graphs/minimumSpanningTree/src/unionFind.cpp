#include "../inc/unionFind.hpp"
#include <util.hpp>
#include <numeric>

CUnionFind::CUnionFind(uint32_t numberOfVertices){
    vertices.resize(numberOfVertices);
    std::iota(vertices.begin(), vertices.end(), 0);
}

void CUnionFind::addUnion(vertix_index_t src, vertix_index_t dst){
    vertix_index_t srcRoot = root(src);
    vertix_index_t dstRoot = root(dst);
    vertices[srcRoot] = dstRoot;
    print(vertices);
}

bool CUnionFind::connected(vertix_index_t src, vertix_index_t dst){
    return root(src) == root(dst);
}

typename CUnionFind::vertix_index_t CUnionFind::root(vertix_index_t v){
    int i = v;
    while(i != vertices[i])
    {
        i = vertices[i];
    }
    return i;
}
