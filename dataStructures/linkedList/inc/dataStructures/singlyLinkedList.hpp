#ifndef SINGLEY_LINKED_LIST_INCLUDED_
#define SINGLEY_LINKED_LIST_INCLUDED_

#include "dataStructures/linkedNode.hpp"

namespace dataStructures {

template <typename Ttype>
class CSinglyLinkedList {
public:
    using data_t = Ttype;
    using node_t = CLinkedNode<data_t>;
    using node_ptr_t = node_t*;
    using size_t = std::size_t;

    /**
     * @brief Default Constructor
     */
    CSinglyLinkedList(); 

    /**
     * @brief Copy Constructor
     * @param other The other list to copy from
     */
    CSinglyLinkedList(const CSinglyLinkedList& other);

    /**
     * @brief Default destructor
     */
    ~CSinglyLinkedList();

    /**
     * @brief Assignment operator
     * @param other The other list to assign from
     * @return Reference to this list
     */
    CSinglyLinkedList& operator=(const CSinglyLinkedList& other);

    /**
     * @brief Adds a new element to the front of the list
     * @param value The value to add
     */
    void pushFront(const data_t& value);

    /**
     * @brief Adds a new element to the back of the list
     * @param value The value to add
     */
    void pushBack(const data_t& value);

    /**
     * @brief Removes and returns the first element
     * @return The value of the removed element
     */
    data_t popFront();

    /**
     * @brief Removes and returns the last element
     * @return The value of the removed element
     */
    data_t popBack();

    /**
     * @brief Removes the first occurrence of value in the list
     * @param value The value to remove
     * @return true if value was found and removed, false otherwise
     */
    bool remove(const data_t& value);

    /**
     * @brief Returns the element at the specified position
     * @param position The index of the element to return
     * @return Reference to the element at position
     */
    const data_t& at(size_t position) const;

    /**
     * @brief Checks if a value exists in the list
     * @param value The value to search for
     * @return true if value is found, false otherwise
     */
    bool contains(const data_t& value) const;

    /**
     * @brief Returns the number of elements in the list
     * @return Number of elements
     */
    size_t size() const;

    /**
     * @brief Checks if the list is empty
     * @return true if empty, false otherwise
     */
    bool empty() const;

    /**
     * @brief Reverses the order of elements in the list
     */
    void reverse();

    /**
     * @brief Removes all elements from the list
     */
    void clear();

    /**
     * @brief Inserts a new element at the specified position
     * @param position The index at which to insert the new element
     * @param value The value to insert
     */
    void insert(size_t position, const data_t& value);

protected:
    node_ptr_t head{}; ///< Pointer to the first node in the list
    node_ptr_t tail{}; ///< Pointer to the last node in the list
    size_t count{}; ///< Number of elements in the list

}; //class CSinglyLinkedList

} //namespace dataStructures

#include "dataStructures/singlyLinkedList.inl"

#endif // SINGLEY_LINKED_LIST_INCLUDED_
