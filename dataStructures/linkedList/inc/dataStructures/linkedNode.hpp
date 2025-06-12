#ifndef BASENODE_INCLUDED_
#define BASENODE_INCLUDED_

namespace dataStructures
{

/**
 * @brief A node for singly or doubly linked list
 * 
 * This class represents a node in a singly linked list.
 * 
 * @tparam Ttype The type of data stored in the node
 */
template<typename Ttype>
class CLinkedNode
{
public:
    using node_data_t = Ttype; // The type of data stored in the node

    /**
     * @brief Default constructor
     */
    CLinkedNode() = default;

    /**
     * @brief Destructor
     */
    virtual ~CLinkedNode() = default;

    /**
     * @brief Constructor
     * @param _data The data to store in the node
     */
    CLinkedNode(node_data_t _data) : data(_data) {}

    /**
     * @brief Copy constructor
     * @param other The node to copy
     */
    CLinkedNode(const CLinkedNode& other) : data(other.data) {}

    /**
     * @brief Assignment operator
     * @param other The node to assign
     * @return The assigned node
     */
    CLinkedNode& operator=(const CLinkedNode& other);

    /**
     * @brief Get the data stored in the node
     * @return The data stored in the node
     */
    const node_data_t& getData() const;

    /**
     * @brief Set the data stored in the node
     * @param _data The data to store in the node
     */
    void setData(node_data_t _data);

    /** 
     * @brief Set the data stored in the node
     * @param _data The data to store in the node
     */
    CLinkedNode* getNext() const;

    /**
     * @brief Set the next node in the list
     * @param _next The next node in the list
     */
    void setNext(CLinkedNode* _next);

    /**
     * @brief Get the previous node in the list
     * @return The previous node in the list
     */
    CLinkedNode* getPrevious() const;

    /**
     * @brief Set the previous node in the list
     * @param _previous The previous node in the list
     */
    void setPrevious(CLinkedNode* _previous);

    /**
     * @brief Print the data stored in the node
     */
    void print() const;

private:
    node_data_t data{}; // The data stored in the node
    CLinkedNode* next{nullptr}; // The next node in the list
    CLinkedNode* previous{nullptr}; // The previous node in the list

};
} // namespace dataStructures

#include "dataStructures/linkedNode.inl"

#endif //BASENODE_INCLUDED_