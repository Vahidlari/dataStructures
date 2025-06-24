#include <gtest/gtest.h>
#include "chapter2/palindrome_checker.hpp"

class PalindromeCheckerTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Any setup code would go here
    }
    void TearDown() override {
        // Any cleanup code would go here
    }
};

TEST_F(PalindromeCheckerTest, IsPalindromeUsingReversal) {
    CPalindromeChecker checker("racecar");
    EXPECT_TRUE(checker.isPalindrome<EPalindromeLinkedListCheckerMethod::COMPARE_WITH_REVERSAL>());

    CPalindromeChecker nonPalindromeChecker("hello");
    EXPECT_FALSE(nonPalindromeChecker.isPalindrome<EPalindromeLinkedListCheckerMethod::COMPARE_WITH_REVERSAL>());
}

TEST_F(PalindromeCheckerTest, IsPalindromeUsingStack) {
    CPalindromeChecker checker("madam");
    EXPECT_TRUE(checker.isPalindrome<EPalindromeLinkedListCheckerMethod::USING_STACK>());

    CPalindromeChecker nonPalindromeChecker("world");
    EXPECT_FALSE(nonPalindromeChecker.isPalindrome<EPalindromeLinkedListCheckerMethod::USING_STACK>());

    CPalindromeChecker emptyChecker("");
    EXPECT_TRUE(emptyChecker.isPalindrome<EPalindromeLinkedListCheckerMethod::USING_STACK>());

    CPalindromeChecker singleCharChecker("a");
    EXPECT_TRUE(singleCharChecker.isPalindrome<EPalindromeLinkedListCheckerMethod::USING_STACK>());

    CPalindromeChecker specialCharsChecker("adda");
    EXPECT_TRUE(specialCharsChecker.isPalindrome<EPalindromeLinkedListCheckerMethod::USING_STACK>());
}

TEST_F(PalindromeCheckerTest, IsPalindromeUsingRecursive) {
    CPalindromeChecker checker("noon");
    EXPECT_TRUE(checker.isPalindrome<EPalindromeLinkedListCheckerMethod::RECURSIVE>());

    CPalindromeChecker nonPalindromeChecker("example");
    EXPECT_FALSE(nonPalindromeChecker.isPalindrome<EPalindromeLinkedListCheckerMethod::RECURSIVE>());

    CPalindromeChecker emptyChecker("");
    EXPECT_TRUE(emptyChecker.isPalindrome<EPalindromeLinkedListCheckerMethod::RECURSIVE>());

    CPalindromeChecker singleCharChecker("b");
    EXPECT_TRUE(singleCharChecker.isPalindrome<EPalindromeLinkedListCheckerMethod::RECURSIVE>());

    CPalindromeChecker specialCharsChecker("abcba");
    EXPECT_TRUE(specialCharsChecker.isPalindrome<EPalindromeLinkedListCheckerMethod::RECURSIVE>());
}