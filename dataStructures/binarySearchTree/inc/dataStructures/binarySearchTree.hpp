#ifndef BINARYSEARCHTREE_INCLUDED_
#define BINARYSEARCHTREE_INCLUDED_

#include "dataStructures/treeNode.hpp"

namespace dataStructures
{
/**
 * @brief Binary search tree implementation with key-value storage
 * 
 * This class implements a binary search tree where:
 * - Each node stores a key-value pair
 * - All keys in the left subtree are less than the node's key
 * - All keys in the right subtree are greater than the node's key
 * - The tree supports operations like rank and range queries
 * 
 * @tparam Tkey Key type that must support operator< for comparisons
 * @tparam Tvalue Value type to be stored
 */
template<typename Tkey, typename Tvalue>
class CBinarySearchTree
{
public:
    using key_t = Tkey;      ///< Type alias for keys
    using value_t = Tvalue;  ///< Type alias for values
    using cnode_t = CNode<key_t, value_t>*;  ///< Type alias for node pointers
    using size_t = uint32_t; ///< Type alias for size calculations

    /**
     * @brief Constructs an empty binary search tree
     */
    CBinarySearchTree()
        : root(nullptr)
    {
    };

    /**
     * @brief Inserts or updates a key-value pair in the tree
     * 
     * @param[in] key Key to insert or update
     * @param[in] value Value to associate with the key
     * @note Time complexity: O(log n) average case, O(n) worst case
     */
    void put(key_t key, value_t value);

    /**
     * @brief Prints the tree in level-order traversal
     */
    void printLevelOrderedTraverse();

    /**
     * @brief Checks if a key exists in the tree
     * 
     * @param[in] key Key to search for
     * @return bool True if key exists, false otherwise
     * @note Time complexity: O(log n) average case, O(n) worst case
     */
    bool contains(key_t key);

    /**
     * @brief Retrieves the value associated with a key
     * 
     * @param[in] key Key to look up
     * @return value_t Value associated with the key
     * @note Time complexity: O(log n) average case, O(n) worst case
     */
    value_t get(key_t key);

    /**
     * @brief Returns the number of keys less than the given key
     * 
     * @param[in] key Key to find rank for
     * @return uint32_t Number of keys less than the given key
     * @note Time complexity: O(log n) average case, O(n) worst case
     */
    uint32_t rank(key_t key);

    /**
     * @brief Returns the height of the tree
     * 
     * @return uint32_t Height of the tree (0 for empty tree)
     * @note Time complexity: O(n)
     */
    uint32_t height();

    /**
     * @brief Returns the number of keys in the given range
     * 
     * @param[in] low Lower bound key (inclusive)
     * @param[in] high Upper bound key (inclusive)
     * @return uint32_t Number of keys in range [low, high]
     * @note Time complexity: O(log n + k) where k is size of the range
     */
    uint32_t size(key_t low, key_t high);
    //TODO: value_t floor(key_t key);
    //TODO: value_t ceiling(key_t key);


private:
    /**
     * @brief Helper function for recursive insertion
     * 
     * @param[in] node Current node in recursion
     * @param[in] key Key to insert
     * @param[in] value Value to associate with key
     * @return cnode_t Pointer to the current node (may be new or updated)
     */
    cnode_t put(cnode_t node, key_t key, value_t value);

    /**
     * @brief Helper function for level-order traversal
     * 
     * @param[in] node Current node in traversal
     * @param[in] level Current level in the tree
     */
    void printLevelOrderedTraverse(cnode_t node, int level);

    /**
     * @brief Helper function for height calculation
     * 
     * @param[in] node Current node in recursion
     * @return uint32_t Height of the subtree rooted at node
     */
    uint32_t height(cnode_t node);

    /**
     * @brief Helper function for rank calculation
     * 
     * @param[in] node Current node in recursion
     * @param[in] key Key to find rank for
     * @return uint32_t Number of keys less than given key in subtree
     */
    uint32_t rank(cnode_t node, key_t key);

    //TODO: value_t floor(cnode_t node, key_t key);
    //TODO: value_t ceiling(cnode_t node, key_t key);
    cnode_t root;
};
}

#include "dataStructures/binarySearchTree.inl"

#endif //BINARYSEARCHTREE_INCLUDED_