#include "chapter2/sum_lists.hpp"

// Helper function: forwardTraverseSumOfProduct
CSummableLists CSummableLists::forwardTraverseSumOfProduct(const CSummableLists& first, const CSummableLists& second) {
    CSummableLists result;
    int firstValue = first.forwardToInteger();
    int secondValue = second.forwardToInteger();
    result = CSummableLists::fromIntegerForward(firstValue + secondValue);
    return result;
}

// Helper function: forwardTraverseSumOfDigits
CSummableLists CSummableLists::forwardTraverseSumOfDigits(const CSummableLists& first, const CSummableLists& second) {
    
    CSummableLists result;
    auto firstNode = first.head;
    auto secondNode = second.head;
    uint8_t carry = 0;
    uint8_t carryNext = 0;
    while (firstNode != nullptr || secondNode != nullptr || carry != 0) {
        uint8_t firstDigit = (firstNode != nullptr)? firstNode->getData() : 0;
        uint8_t secondDigit = (secondNode != nullptr)? secondNode->getData() : 0;
        result.pushBack(addDigits(firstDigit, secondDigit, carry, carryNext));

        // Update carry for the next iteration
        carry = carryNext;
        carryNext = 0;

        if (firstNode != nullptr){
            firstNode = firstNode->getNext();
        }

        if (secondNode != nullptr){
            secondNode = secondNode->getNext();
        }

    } 
    return result;
}

// Helper function: reverseTraverseSumOfDigits
CSummableLists CSummableLists::reverseTraverseSumOfDigits(const CSummableLists& first, const CSummableLists& second) {
    CSummableLists result;
    CSummableLists temp;
    node_ptr_t firstNode, secondNode;
    if (first.size() > second.size()) {
        temp = second;
        for (size_t i = 0; i < first.size() - second.size(); i++) {
            temp.pushFront(0);
        }
        firstNode = first.head;
        secondNode = temp.head;
    } else if (first.size() < second.size()) {
        temp = first;
        for (size_t i = 0; i < second.size() - first.size(); i++) {
            temp.pushFront(0);
        }
        firstNode = temp.head;
        secondNode = second.head;
    } else {
        firstNode = first.head;
        secondNode = second.head;
    }
    uint8_t carry = reverseTraverseSumOfDigits_recursive(firstNode, secondNode, result);
    if (carry > 0) {
        result.pushFront(carry);
    }

    return result;
}

// Helper function: reverseTraverseSumOfDigits_recursive
uint8_t CSummableLists::reverseTraverseSumOfDigits_recursive(node_ptr_t first, node_ptr_t second, CSummableLists& result) {
    // Base case: if both nodes are null, no carry needed
    if (first == nullptr && second == nullptr) {
        return 0;
    }

    // Recursively process next nodes first (since we're going in reverse)
    // Continue recursion if either list has more nodes
    uint8_t carry = reverseTraverseSumOfDigits_recursive(
        first != nullptr ? first->getNext() : nullptr,
        second != nullptr ? second->getNext() : nullptr, 
        result);

    // Get digits from current nodes or use 0 if null
    uint8_t digit1 = first != nullptr ? first->getData() : 0;
    uint8_t digit2 = second != nullptr ? second->getData() : 0;

    // Add digits with carry from recursive call
    uint8_t carryNext = 0;
    uint8_t sum = addDigits(digit1, digit2, carry, carryNext);

    // Add result to front since we're building in reverse
    result.pushFront(sum);

    return carryNext;
}

// Helper function: addDigits
uint8_t CSummableLists::addDigits(uint8_t digit1, uint8_t digit2, uint8_t carry, uint8_t& carryResult) {
    uint8_t sum = digit1 + digit2 + carry;
    carryResult = sum / 10; // Calculate the new carry
    return sum % 10; // Return the resulting digit
}

CSummableLists CSummableLists::fromIntegerForward(int value) {
    CSummableLists list;
    if (value == 0) {
        list.pushBack(0);
        return list;
    }
    int valueCopy = value;
    while (valueCopy > 0) {
        list.pushBack(valueCopy % 10);
        valueCopy /= 10;
    }
    
    return list;
}

CSummableLists CSummableLists::fromIntegerReverse(int value) {
    CSummableLists list;
    if (value == 0) {
        list.pushBack(0);
        return list;
    }
    
    while (value > 0) {
        list.pushFront(value % 10);
        value /= 10;
    }
    
    return list;
}

int CSummableLists::forwardToInteger() const {
    int result = 0;
    int multiplier = 1;
    for (auto node = head; node != nullptr; node = node->getNext()) {
        result += node->getData() * multiplier;
        multiplier *= 10;
    }
    return result;
}

int CSummableLists::reverseToInteger() const {
    int result = 0;
    for (auto node = head; node != nullptr; node = node->getNext()) {
        result = result * 10 + node->getData();
    }
    return result;
}
