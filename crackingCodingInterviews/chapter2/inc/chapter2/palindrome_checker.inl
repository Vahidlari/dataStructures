
template <EPalindromeLinkedListCheckerMethod method>
bool CPalindromeChecker::isPalindrome() const {
    if (head == nullptr || head->getNext() == nullptr) {
        return true; // An empty list or a single element list is a palindrome
    }
    
    if constexpr (method == EPalindromeLinkedListCheckerMethod::USING_STACK) {
        return isPalindrome_usingStack();
    } else if constexpr (method == EPalindromeLinkedListCheckerMethod::COMPARE_WITH_REVERSAL) {
        return isPalindrome_compareWithReversal();
    } else if constexpr (method == EPalindromeLinkedListCheckerMethod::RECURSIVE) {
        return isPalindrome_recursive(head, count).second;
    } else {
        static_assert("Unknown method for palindrome checking");
    }
}