#include "chapter2/palindrome_checker.hpp"

CPalindromeChecker::CPalindromeChecker(const std::string& str) {
    for (char ch : str) {
        if (std::isalnum(ch)) { // Only consider alphanumeric characters
            this->pushBack(std::tolower(ch)); // Convert to lowercase and add to the list
        }
    }
}

bool CPalindromeChecker::isPalindrome_usingStack() const {
    dataStructures::CSinglyLinkedList<char> stack;

    // Use fast and slow pointers to find the midpoint
    node_ptr_t fastRunner = head;
    node_ptr_t slowRunner = head;

    // Push the first half of the list onto the stack
    while (fastRunner != nullptr && fastRunner->getNext() != nullptr) {
        stack.pushFront(slowRunner->getData());
        slowRunner = slowRunner->getNext();
        fastRunner = fastRunner->getNext()->getNext();
    }

    // Handle odd-sized lists: skip the middle element
    if (fastRunner != nullptr) {
        slowRunner = slowRunner->getNext();
    }

    bool isPalindrome = true;

    // Compare the second half of the list with the stack
    while (slowRunner != nullptr && isPalindrome) {
        if (stack.popFront() != slowRunner->getData()) {
            isPalindrome = false;
        }
        slowRunner = slowRunner->getNext();
    }

    return isPalindrome;
}

bool CPalindromeChecker::isPalindrome_compareWithReversal() const {
    dataStructures::CSinglyLinkedList<char> reverseTmp = *this;
    reverseTmp.reverse();

    return (*this == reverseTmp);
}

CPalindromeChecker::result_t CPalindromeChecker::isPalindrome_recursive(node_ptr_t currentNode, size_t index) const {
    // Base case: if index < 1 or currentNode is null, we've reached the end (even-length) or null node.
    if (index < 1 || currentNode == nullptr) {
        return result_t(currentNode, true);
    }
    // Base case: if index == 1, we're at the middle node of an odd-length list.
    // Skip the middle node and continue.
    if (index == 1) {
        return result_t(currentNode->getNext(), true);
    }

    // Recursive call: move two steps forward to reach the mirrored node.
    result_t res = isPalindrome_recursive(currentNode->getNext(), index - 2);

    // If a mismatch was found deeper in recursion, propagate false.
    // Otherwise, compare current node's data with its mirrored counterpart.
    if (!res.second || currentNode == nullptr) {
        return result_t(currentNode, false);
    }
    return result_t(res.first->getNext(), currentNode->getData() == res.first->getData());
}