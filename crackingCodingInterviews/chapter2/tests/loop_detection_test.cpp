#include "gtest/gtest.h"
#include "chapter2/loop_detection.hpp"

class LoopDetectionTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Any setup code would go here
        list = new CCircularSinglyLinkedList();
        // Create a non-looping list
        list->pushBack(1);
        list->pushBack(2);
        list->pushBack(3);
        list->pushBack(4);
        list->pushBack(5);
        list->pushBack(6);
        list->pushBack(7);

    }
    void TearDown() override {
        delete list;
    }
    // Pointer to the list being tested
    CCircularSinglyLinkedList* list;
};

TEST_F(LoopDetectionTest, NoLoop) {
    EXPECT_EQ(list->getLoopStart(), nullptr);
}

TEST_F(LoopDetectionTest, LoopAtStart) {
    list->setLoop(0);
    EXPECT_EQ(list->getLoopStart()->getData(), 1);
}

TEST_F(LoopDetectionTest, LoopAtMiddle) {
    list->setLoop(3);
    EXPECT_EQ(list->getLoopStart()->getData(), 4);
}

TEST_F(LoopDetectionTest, LoopAtEnd) {
    list->setLoop(6);
    EXPECT_EQ(list->getLoopStart()->getData(), 7);
}