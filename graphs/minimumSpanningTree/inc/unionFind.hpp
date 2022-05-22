#ifndef UNIONFIND_INCLUDED_
#define UNIONFIND_INCLUDED_

#include <vector>

class CUnionFind
{
public:
    using vertix_index_t = uint32_t;
    using vertix_list_t = std::vector<uint32_t>;

    CUnionFind() = default;
    CUnionFind(uint32_t numberOfVertices);
    void addUnion(vertix_index_t src, vertix_index_t dst);
    bool connected(vertix_index_t src, vertix_index_t dst);

private:
    vertix_index_t root(vertix_index_t v);
    vertix_list_t vertices;
};

#endif //UNIONFIND_INCLUDED_