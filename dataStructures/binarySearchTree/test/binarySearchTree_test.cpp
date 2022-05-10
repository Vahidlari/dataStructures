#include <gtest/gtest.h>
#include <string>
#include "dataStructures/binarySearchTree.hpp"

class BinarySearchTreeTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code that will be called before each test
    }

    void TearDown() override {
        // Cleanup code that will be called after each test
    }

    // The tree we will use for testing
    dataStructures::CBinarySearchTree<int, std::string> tree;
};

TEST_F(BinarySearchTreeTest, EmptyTreeShouldHaveZeroSize) {
    EXPECT_EQ(tree.size(0, 100), 0);
}

TEST_F(BinarySearchTreeTest, PutShouldStoreAndRetrieveValue) {
    tree.put(5, "five");
    EXPECT_EQ(tree.get(5), "five");
    
    tree.put(3, "three");
    EXPECT_EQ(tree.get(3), "three");
}

TEST_F(BinarySearchTreeTest, ContainsShouldFindExistingKeys) {
    tree.put(5, "five");
    tree.put(3, "three");
    tree.put(7, "seven");

    EXPECT_TRUE(tree.contains(5));
    EXPECT_TRUE(tree.contains(3));
    EXPECT_TRUE(tree.contains(7));
    EXPECT_FALSE(tree.contains(1));
}

TEST_F(BinarySearchTreeTest, RankShouldReturnCorrectPosition) {
    /**
     * Insert in this order to create a balanced tree:
     *       4
     *     /   \
     *    2     6
     *   / \   / \
     *  1   3 5   7
     */
    
    tree.put(4, "four");   // Root
    tree.put(2, "two");    // Left of 4
    tree.put(6, "six");    // Right of 4
    tree.put(1, "one");    // Left of 2
    tree.put(3, "three");  // Right of 2
    tree.put(5, "five");   // Left of 6
    tree.put(7, "seven");  // Right of 6

    // Rank should return the number of keys less than the given key
    EXPECT_EQ(tree.rank(1), 0);  // Nothing less than 1
    EXPECT_EQ(tree.rank(2), 1);  // Just 1 is less than 2
    EXPECT_EQ(tree.rank(4), 3);  // 1,2,3 are less than 4
    EXPECT_EQ(tree.rank(7), 6);  // 1,2,3,4,5,6 are less than 7
}

TEST_F(BinarySearchTreeTest, HeightShouldReflectTreeStructure) {
    EXPECT_EQ(tree.height(), 0);

    tree.put(5, "five");
    EXPECT_EQ(tree.height(), 1);

    tree.put(3, "three");
    tree.put(7, "seven");
    EXPECT_EQ(tree.height(), 2);
} 