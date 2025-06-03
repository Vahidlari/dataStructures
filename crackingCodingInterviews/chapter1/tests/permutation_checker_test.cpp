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
    EXPECT_TRUE(isPermutation_usingCharCount("abc", "bca"));
    EXPECT_TRUE(isPermutation_usingSort("abc", "bca"));
    EXPECT_TRUE(isPermutation_usingHashTable("abc", "bca"));
}

TEST_F(PermutationCheckerTest, EmptyAndSingleChar) {
    // Test empty strings
    EXPECT_TRUE(isPermutation_usingCharCount("", ""));
    EXPECT_TRUE(isPermutation_usingSort("", ""));
    EXPECT_TRUE(isPermutation_usingHashTable("", ""));
    
    // Test single character
    EXPECT_TRUE(isPermutation_usingCharCount("a", "a"));
    EXPECT_TRUE(isPermutation_usingSort("a", "a"));
    EXPECT_TRUE(isPermutation_usingHashTable("a", "a"));
}

TEST_F(PermutationCheckerTest, NonPermutations) {
    // Different lengths
    EXPECT_FALSE(isPermutation_usingCharCount("abc", "ab"));
    EXPECT_FALSE(isPermutation_usingSort("abc", "ab"));
    EXPECT_FALSE(isPermutation_usingHashTable("abc", "ab"));
    
    // Same length but different characters
    EXPECT_FALSE(isPermutation_usingCharCount("abc", "def"));
    EXPECT_FALSE(isPermutation_usingSort("abc", "def"));
    EXPECT_FALSE(isPermutation_usingHashTable("abc", "def"));
}

TEST_F(PermutationCheckerTest, CaseSensitivity) {
    // Test case sensitivity
    EXPECT_FALSE(isPermutation_usingCharCount("abc", "ABC"));
    EXPECT_FALSE(isPermutation_usingSort("abc", "ABC"));
    EXPECT_FALSE(isPermutation_usingHashTable("abc", "ABC"));
}

TEST_F(PermutationCheckerTest, SpecialCharacters) {
    // Test with special characters
    EXPECT_TRUE(isPermutation_usingCharCount("a!b@c#", "c#b@a!"));
    EXPECT_TRUE(isPermutation_usingSort("a!b@c#", "c#b@a!"));
    EXPECT_TRUE(isPermutation_usingHashTable("a!b@c#", "c#b@a!"));
}

TEST_F(PermutationCheckerTest, Whitespace) {
    // Test whitespace handling
    EXPECT_TRUE(isPermutation_usingCharCount("abc ", " abc"));
    EXPECT_TRUE(isPermutation_usingSort("abc ", " abc"));
    EXPECT_TRUE(isPermutation_usingHashTable("abc ", " abc"));
    
    EXPECT_FALSE(isPermutation_usingCharCount("abc", "abc "));
    EXPECT_FALSE(isPermutation_usingSort("abc", "abc "));
    EXPECT_FALSE(isPermutation_usingHashTable("abc", "abc "));
}

TEST_F(PermutationCheckerTest, RepeatedCharacters) {
    // Test strings with repeated characters
    EXPECT_TRUE(isPermutation_usingCharCount("aabb", "abab"));
    EXPECT_TRUE(isPermutation_usingSort("aabb", "abab"));
    EXPECT_TRUE(isPermutation_usingHashTable("aabb", "abab"));
    
    EXPECT_FALSE(isPermutation_usingCharCount("aabb", "aaab"));
    EXPECT_FALSE(isPermutation_usingSort("aabb", "aaab"));
    EXPECT_FALSE(isPermutation_usingHashTable("aabb", "aaab"));
}

TEST_F(PermutationCheckerTest, LongStrings) {
    // Test with longer strings
    std::string s1(1000, 'a');
    std::string s2(1000, 'a');
    EXPECT_TRUE(isPermutation_usingCharCount(s1, s2));
    EXPECT_TRUE(isPermutation_usingSort(s1, s2));
    EXPECT_TRUE(isPermutation_usingHashTable(s1, s2));
    
    s2[500] = 'b';  // Make strings different
    EXPECT_FALSE(isPermutation_usingCharCount(s1, s2));
    EXPECT_FALSE(isPermutation_usingSort(s1, s2));
    EXPECT_FALSE(isPermutation_usingHashTable(s1, s2));
} 