#include <algorithm> 
#include <limits>

namespace dataStructures
{
template<typename Tkey, typename Tvalue>
inline
void CBinarySearchTree<Tkey, Tvalue>::put(CBinarySearchTree::key_t key, CBinarySearchTree::value_t value)
{
    root = put(root, key, value);
    root->printLineBreaked();
}

template<typename Tkey, typename Tvalue>
inline
CNode<Tkey, Tvalue>* CBinarySearchTree<Tkey, Tvalue>::put(cnode_t node, key_t key, value_t value)
{
    if(node == nullptr){
        return new CNode<key_t, value_t>(key, value);
    } else if (key < node->key){
        node->left = put(node->left, key, value);
    } else if (key > node->key){
        node->right = put(node->right, key, value);
    } else {
        node->value = value;
    }
    node->updateSize();
    return node;
}

template<typename Tkey, typename Tvalue>
inline
void CBinarySearchTree<Tkey, Tvalue>::printLevelOrderedTraverse()
{
    int h = height();
    std::cout << "Height of the tree is " << h << std::endl;
    for(int i = 0; i < h; i++){
        printLevelOrderedTraverse(root, i);
        std::cout << std::endl;
    }
}

template<typename Tkey, typename Tvalue>
inline
void CBinarySearchTree<Tkey, Tvalue>::printLevelOrderedTraverse(cnode_t node, int level)
{
    if(node == nullptr)
    {
        return;
    } else if (level == 0)
    {
        node->print();
    } else
    {
        printLevelOrderedTraverse(node->left, level - 1);
        printLevelOrderedTraverse(node->right, level - 1);
    }
}

template<typename Tkey, typename Tvalue>
inline
uint32_t CBinarySearchTree<Tkey, Tvalue>::height()
{
    return height(root);
}

template<typename Tkey, typename Tvalue>
inline
uint32_t CBinarySearchTree<Tkey, Tvalue>::height(cnode_t node)
{
    int totalHeight = 0, lheight = 0, rheight = 0;
    if(node == nullptr)
    {
        return totalHeight;
    } else {
        lheight = height(node->left);
        rheight = height(node->right);
    }
    totalHeight = std::max(lheight, rheight) + 1;
    return totalHeight;
}

template<typename Tkey, typename Tvalue>
inline
Tvalue CBinarySearchTree<Tkey, Tvalue>::get(key_t key)
{
    value_t rtn = std::numeric_limits<value_t>::max();
    cnode_t node = root;

    while (node != nullptr)
    {
        if(key < node->key){
            node = node->left;
        } else if (key > node->key){
            node = node->right;
        } else {
            rtn = node->value;
            break;
        }
    }
    return rtn;
}

template<typename Tkey, typename Tvalue>
inline
bool CBinarySearchTree<Tkey, Tvalue>::contains(key_t key)
{
    return std::numeric_limits<value_t>::max() != get(key);
}

template<typename Tkey, typename Tvalue>
inline
uint32_t CBinarySearchTree<Tkey, Tvalue>::rank(key_t key){
    return rank(root, key);
}

template<typename Tkey, typename Tvalue>
inline
uint32_t CBinarySearchTree<Tkey, Tvalue>::rank(cnode_t node, key_t key){
    if(node == nullptr){
        return 0;
    }
    if(key < node->key)
    {
        return rank(node->left, key);
    } else if(key > node->key)
    {
        uint32_t lsize = (node->left != nullptr)? node->left->size(): 0;
        return rank(node->right, key) + lsize + 1;
    } else 
    {
        return (node->left != nullptr) ? node->left->size() : 0;
    }
}

template<typename Tkey, typename Tvalue>
inline
uint32_t CBinarySearchTree<Tkey, Tvalue>::size(key_t low, key_t high)
{
    uint32_t count = rank(root, high) - rank(root, low);
    if(contains(high))
    {
        ++count;
    }
    return count;
}

// template<typename Tkey, typename Tvalue>
// inline
// Tvalue CBinarySearchTree<Tkey, Tvalue>::floor(key_t key)
// {
//     return floor(root, key);
// }

// template<typename Tkey, typename Tvalue>
// inline
// Tvalue CBinarySearchTree<Tkey, Tvalue>::floor(cnode_t node, key_t key)
// {
//     if(node == nullptr)
//     {
//         return std::numeric_limits<value_t>::max();
//     }
//     if(key == node->key)
//     {
//         return node->value;
//     } else if (key < node->key){
//         return floor(node->left, key);
//     } 
//     value_t rtn = floor(node->right, key);
//     if(rtn != std::numeric_limits<value_t>::max())
//     {
//         return rtn;
//     } else 
//     {
//         return node->value;
//     }

// }

}