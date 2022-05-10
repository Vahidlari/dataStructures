#include <gtest/gtest.h>
#include <vector>
#include "dataStructures/binaryHeap.hpp"

class BinaryHeapTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code that will be called before each test
    }

    void TearDown() override {
        // Cleanup code that will be called after each test
    }

    dataStructures::CBinaryHeap<int> heap;
};

TEST_F(BinaryHeapTest, InsertShouldMaintainHeapProperty) {
    heap.insert(5);
    heap.insert(3);
    heap.insert(7);
    heap.insert(1);
    heap.insert(4);

    // Verify heap property by removing elements
    // They should come out in descending order
    EXPECT_EQ(heap.delMax(), 7);
    EXPECT_EQ(heap.delMax(), 5);
    EXPECT_EQ(heap.delMax(), 4);
    EXPECT_EQ(heap.delMax(), 3);
    EXPECT_EQ(heap.delMax(), 1);
}

TEST_F(BinaryHeapTest, InsertInDescendingOrder) {
    // Insert elements in descending order
    heap.insert(7);
    heap.insert(6);
    heap.insert(5);
    heap.insert(4);
    heap.insert(3);

    // Verify heap property
    EXPECT_EQ(heap.delMax(), 7);
    EXPECT_EQ(heap.delMax(), 6);
    EXPECT_EQ(heap.delMax(), 5);
    EXPECT_EQ(heap.delMax(), 4);
    EXPECT_EQ(heap.delMax(), 3);
}

TEST_F(BinaryHeapTest, InsertInAscendingOrder) {
    // Insert elements in ascending order
    heap.insert(1);
    heap.insert(2);
    heap.insert(3);
    heap.insert(4);
    heap.insert(5);

    // Verify heap property
    EXPECT_EQ(heap.delMax(), 5);
    EXPECT_EQ(heap.delMax(), 4);
    EXPECT_EQ(heap.delMax(), 3);
    EXPECT_EQ(heap.delMax(), 2);
    EXPECT_EQ(heap.delMax(), 1);
}

TEST_F(BinaryHeapTest, InsertDuplicateValues) {
    heap.insert(5);
    heap.insert(5);
    heap.insert(3);
    heap.insert(3);
    heap.insert(5);

    // Verify that duplicates are handled correctly
    EXPECT_EQ(heap.delMax(), 5);
    EXPECT_EQ(heap.delMax(), 5);
    EXPECT_EQ(heap.delMax(), 5);
    EXPECT_EQ(heap.delMax(), 3);
    EXPECT_EQ(heap.delMax(), 3);
} 