#include <gtest/gtest.h>
#include "chapter3/queue_using_stacks.hpp"

class QueueUsingStacksTest : public ::testing::Test {
protected:
    void SetUp() override {
        queue = new CQueueUsingStacks<int>(100);
    }
    void TearDown() override {
        delete queue;
    }
    CQueueUsingStacks<int>* queue;
};

TEST_F(QueueUsingStacksTest, SimpleEnqueueDequeue) {
    queue->enqueue(1);
    queue->enqueue(2);
    queue->enqueue(3);
    
    EXPECT_EQ(queue->dequeue(), 1);
    EXPECT_EQ(queue->dequeue(), 2);
    EXPECT_EQ(queue->dequeue(), 3);
}

TEST_F(QueueUsingStacksTest, DequeueEmptyQueue) {
    EXPECT_THROW(queue->dequeue(), std::out_of_range);
}

TEST_F(QueueUsingStacksTest, PeekEmptyQueue) {
    EXPECT_THROW(queue->peek(), std::out_of_range);
}

TEST_F(QueueUsingStacksTest, EnqueueAndPeek) {
    queue->enqueue(10);
    EXPECT_EQ(queue->peek(), 10);
    
    queue->enqueue(20);
    EXPECT_EQ(queue->peek(), 10); // Peek should still return the first element
}

TEST_F(QueueUsingStacksTest, IsEmpty) {
    EXPECT_TRUE(queue->isEmpty());
    
    queue->enqueue(1);
    EXPECT_FALSE(queue->isEmpty());
    
    queue->dequeue();
    EXPECT_TRUE(queue->isEmpty());
}

TEST_F(QueueUsingStacksTest, EnqueueFullQueue) {
    for (int i = 0; i < 100; ++i) {
        queue->enqueue(i);
    }
    
    EXPECT_EQ(queue->getQueueSize(), 100);
    
    // Dequeue all elements
    for (int i = 0; i < 100; ++i) {
        EXPECT_EQ(queue->dequeue(), i);
    }
    
    EXPECT_TRUE(queue->isEmpty());
}

TEST_F(QueueUsingStacksTest, GetQueueSize) {
    EXPECT_EQ(queue->getQueueSize(), 0);
    
    queue->enqueue(1);
    EXPECT_EQ(queue->getQueueSize(), 1);
    
    queue->enqueue(2);
    EXPECT_EQ(queue->getQueueSize(), 2);
    
    queue->dequeue();
    EXPECT_EQ(queue->getQueueSize(), 1);
    
    queue->dequeue();
    EXPECT_EQ(queue->getQueueSize(), 0);
}

TEST_F(QueueUsingStacksTest, GetQueueCapacity) {
    EXPECT_EQ(queue->getQueueCapacity(), 100);
    
    queue->enqueue(1);
    EXPECT_EQ(queue->getQueueCapacity(), 100); // Capacity should remain unchanged
}