#include <gtest/gtest.h>
#include "chapter1/permutation_checker.hpp"

class PermutationCheckerTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Any setup code would go here
    }
};

TEST_F(PermutationCheckerTest, BasicCases) {
    // Test basic permutations
    EXPECT_TRUE(isPermutation<PermutationMethod::CharCount>("abc", "bca"));
    EXPECT_TRUE(isPermutation<PermutationMethod::Sort>("abc", "bca"));
    EXPECT_TRUE(isPermutation<PermutationMethod::HashTable>("abc", "bca"));
}

TEST_F(PermutationCheckerTest, EmptyAndSingleChar) {
    // Test empty strings
    EXPECT_TRUE(isPermutation<PermutationMethod::CharCount>("", ""));
    EXPECT_TRUE(isPermutation<PermutationMethod::Sort>("", ""));
    EXPECT_TRUE(isPermutation<PermutationMethod::HashTable>("", ""));
    
    // Test single character
    EXPECT_TRUE(isPermutation<PermutationMethod::CharCount>("a", "a"));
    EXPECT_TRUE(isPermutation<PermutationMethod::Sort>("a", "a"));
    EXPECT_TRUE(isPermutation<PermutationMethod::HashTable>("a", "a"));
}

TEST_F(PermutationCheckerTest, NonPermutations) {
    // Different lengths
    EXPECT_FALSE(isPermutation<PermutationMethod::CharCount>("abc", "ab"));
    EXPECT_FALSE(isPermutation<PermutationMethod::Sort>("abc", "ab"));
    EXPECT_FALSE(isPermutation<PermutationMethod::HashTable>("abc", "ab"));
    
    // Same length but different characters
    EXPECT_FALSE(isPermutation<PermutationMethod::CharCount>("abc", "def"));
    EXPECT_FALSE(isPermutation<PermutationMethod::Sort>("abc", "def"));
    EXPECT_FALSE(isPermutation<PermutationMethod::HashTable>("abc", "def"));
}

TEST_F(PermutationCheckerTest, CaseSensitivity) {
    // Test case sensitivity
    EXPECT_FALSE(isPermutation<PermutationMethod::CharCount>("abc", "ABC"));
    EXPECT_FALSE(isPermutation<PermutationMethod::Sort>("abc", "ABC"));
    EXPECT_FALSE(isPermutation<PermutationMethod::HashTable>("abc", "ABC"));
}

TEST_F(PermutationCheckerTest, SpecialCharacters) {
    // Test with special characters
    EXPECT_TRUE(isPermutation<PermutationMethod::CharCount>("a!b@c#", "c#b@a!"));
    EXPECT_TRUE(isPermutation<PermutationMethod::Sort>("a!b@c#", "c#b@a!"));
    EXPECT_TRUE(isPermutation<PermutationMethod::HashTable>("a!b@c#", "c#b@a!"));
}

TEST_F(PermutationCheckerTest, Whitespace) {
    // Test whitespace handling
    EXPECT_TRUE(isPermutation<PermutationMethod::CharCount>("abc ", " abc"));
    EXPECT_TRUE(isPermutation<PermutationMethod::Sort>("abc ", " abc"));
    EXPECT_TRUE(isPermutation<PermutationMethod::HashTable>("abc ", " abc"));
    
    EXPECT_FALSE(isPermutation<PermutationMethod::CharCount>("abc", "abc "));
    EXPECT_FALSE(isPermutation<PermutationMethod::Sort>("abc", "abc "));
    EXPECT_FALSE(isPermutation<PermutationMethod::HashTable>("abc", "abc "));
}

TEST_F(PermutationCheckerTest, RepeatedCharacters) {
    // Test strings with repeated characters
    EXPECT_TRUE(isPermutation<PermutationMethod::CharCount>("aabb", "abab"));
    EXPECT_TRUE(isPermutation<PermutationMethod::Sort>("aabb", "abab"));
    EXPECT_TRUE(isPermutation<PermutationMethod::HashTable>("aabb", "abab"));
    
    EXPECT_FALSE(isPermutation<PermutationMethod::CharCount>("aabb", "aaab"));
    EXPECT_FALSE(isPermutation<PermutationMethod::Sort>("aabb", "aaab"));
    EXPECT_FALSE(isPermutation<PermutationMethod::HashTable>("aabb", "aaab"));
}

TEST_F(PermutationCheckerTest, LongStrings) {
    // Test with longer strings
    std::string s1(1000, 'a');
    std::string s2(1000, 'a');
    EXPECT_TRUE(isPermutation<PermutationMethod::CharCount>(s1, s2));
    EXPECT_TRUE(isPermutation<PermutationMethod::Sort>(s1, s2));
    EXPECT_TRUE(isPermutation<PermutationMethod::HashTable>(s1, s2));
    
    s2[500] = 'b';  // Make strings different
    EXPECT_FALSE(isPermutation<PermutationMethod::CharCount>(s1, s2));
    EXPECT_FALSE(isPermutation<PermutationMethod::Sort>(s1, s2));
    EXPECT_FALSE(isPermutation<PermutationMethod::HashTable>(s1, s2));
}