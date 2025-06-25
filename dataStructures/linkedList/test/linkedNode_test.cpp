#include <gtest/gtest.h>
#include <dataStructures/linkedNode.hpp>

class BaseSingleLinkedNodeTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code that will be called before each test
    }

    void TearDown() override {
        // Cleanup code that will be called after each test
    }
};

TEST_F(BaseSingleLinkedNodeTest, DefaultConstructor) {
    dataStructures::CLinkedNode<int> node;
    EXPECT_EQ(node.getData(), 0);
    EXPECT_EQ(node.getNext(), nullptr);
}

TEST_F(BaseSingleLinkedNodeTest, ParameterizedConstructor) {
    dataStructures::CLinkedNode<int> node(42);
    EXPECT_EQ(node.getData(), 42);
    EXPECT_EQ(node.getNext(), nullptr);
}

TEST_F(BaseSingleLinkedNodeTest, CopyConstructor) {
    dataStructures::CLinkedNode<int> node(42);
    dataStructures::CLinkedNode<int> node2(node);
    EXPECT_EQ(node2.getData(), 42);
    EXPECT_EQ(node2.getNext(), nullptr);
}

TEST_F(BaseSingleLinkedNodeTest, AssignmentOperator) {
    dataStructures::CLinkedNode<int> node(42);
    dataStructures::CLinkedNode<int> node2 = node;
    EXPECT_EQ(node2.getData(), 42);
    EXPECT_EQ(node2.getNext(), nullptr);
}

TEST_F(BaseSingleLinkedNodeTest, SetData) {
    dataStructures::CLinkedNode<int> node;
    node.setData(42);
    EXPECT_EQ(node.getData(), 42);
}

TEST_F(BaseSingleLinkedNodeTest, GetSetNext) {
    dataStructures::CLinkedNode<int, std::shared_ptr> node(42);
    dataStructures::CLinkedNode<int, std::shared_ptr> node2(43);
    auto nextPtr = std::make_shared<dataStructures::CLinkedNode<int, std::shared_ptr>>(node2);
    node.setNext(nextPtr);
    EXPECT_EQ(node.getNext(), nextPtr);
    EXPECT_EQ(node.getNext()->getData(), 43);
}

TEST_F(BaseSingleLinkedNodeTest, GetSetPrevious) {
    dataStructures::CLinkedNode<int, std::shared_ptr> node(42);
    dataStructures::CLinkedNode<int, std::shared_ptr> node2(43);
    auto prevPtr = std::make_shared<dataStructures::CLinkedNode<int, std::shared_ptr>>(node2);
    node.setPrevious(prevPtr);
    EXPECT_EQ(node.getPrevious(), prevPtr);
    EXPECT_EQ(node.getPrevious()->getData(), 43);
}

TEST_F(BaseSingleLinkedNodeTest, GetSetNextAsRawPointer) {
    dataStructures::CLinkedNode<int, dataStructures::raw_ptr> node(42);
    dataStructures::CLinkedNode<int, dataStructures::raw_ptr> node2(43);
    node.setNext(&node2);
    EXPECT_EQ(node.getNext(), &node2);
    EXPECT_EQ(node.getNext()->getData(), 43);
}


