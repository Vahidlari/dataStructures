#include <algorithm> 

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
int CBinarySearchTree<Tkey, Tvalue>::height()
{
    return height(root);
}

template<typename Tkey, typename Tvalue>
inline
int CBinarySearchTree<Tkey, Tvalue>::height(cnode_t node)
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