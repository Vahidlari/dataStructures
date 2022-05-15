#ifndef BINARYSEARCHTREE_INCLUDED_
#define BINARYSEARCHTREE_INCLUDED_

#include "treeNode.hpp"

template<typename Tkey, typename Tvalue>
class CBinarySearchTree
{
public:
    using key_t = Tkey;
    using value_t = Tvalue;
    using cnode_t = CNode<key_t, value_t>*;
    using size_t = uint32_t;

    CBinarySearchTree()
        : root(nullptr)
    {
    };

    void    put(key_t key, value_t value);
    void    printLevelOrderedTraverse();
    bool    contains(key_t key);
    value_t     get(key_t key);
    uint32_t    rank(key_t key);
    uint32_t    height();
    uint32_t    size(key_t low, key_t high);
    //TODO: value_t floor(key_t key);
    //TODO: value_t ceiling(key_t key);


private:
    cnode_t     put(cnode_t node, key_t key, value_t value);
    void        printLevelOrderedTraverse(cnode_t node, int level);
    uint32_t    height(cnode_t node);
    uint32_t    rank(cnode_t node, key_t key);

    //TODO: value_t floor(cnode_t node, key_t key);
    //TODO: value_t ceiling(cnode_t node, key_t key);
    cnode_t root;

};

#include "binarySearchTree.inl"

#endif //BINARYSEARCHTREE_INCLUDED_