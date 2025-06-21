#include <gtest/gtest.h>
#include "chapter2/remove_middle_node.hpp"

class RemoveMiddleNodeTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Any setup code would go here
    }
};

TEST_F(RemoveMiddleNodeTest, RemoveMiddleNode) {
    CRemoveMiddleNode<int> list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.pushBack(4);
    list.pushBack(5);
    EXPECT_TRUE(list.removeMiddleNode(3));
    EXPECT_EQ(list.size(), 4);
    EXPECT_EQ(list.at(0), 1);
    EXPECT_EQ(list.at(1), 2);
    EXPECT_EQ(list.at(2), 4);
    EXPECT_EQ(list.at(3), 5);
}

TEST_F(RemoveMiddleNodeTest, RemoveFirstNode) {
    CRemoveMiddleNode<int> list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.pushBack(4);
    list.pushBack(5);
    EXPECT_TRUE(list.removeMiddleNode(1));
    EXPECT_EQ(list.size(), 4);
    EXPECT_EQ(list.at(0), 2);
    EXPECT_EQ(list.at(1), 3);
    EXPECT_EQ(list.at(2), 4);
    EXPECT_EQ(list.at(3), 5);
}

TEST_F(RemoveMiddleNodeTest, RemoveLastNode) {
    CRemoveMiddleNode<int> list;
    list.pushBack(1); 
    list.pushBack(2);
    list.pushBack(3);
    list.pushBack(4);
    list.pushBack(5);
    EXPECT_FALSE(list.removeMiddleNode(6));
}