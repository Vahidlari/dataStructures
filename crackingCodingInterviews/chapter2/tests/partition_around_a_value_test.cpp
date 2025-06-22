#include <gtest/gtest.h>
#include "chapter2/partition_around_a_value.hpp"

class PartitionAroundATest : public ::testing::Test {
protected:
    void SetUp() override {
        // Any setup code would go here
    }
};

TEST_F(PartitionAroundATest, PartitionAroundATest_UsingTwoSubLists) {
    CPartitionAroundAValue<int> myList;
    myList.pushBack(3);
    myList.pushBack(5);
    myList.pushBack(8);
    myList.pushBack(5);
    myList.pushBack(10);
    myList.pushBack(2);
    myList.pushBack(1);
    myList.partitionAroundAValue<EPartitionMethod::USING_TWO_SUB_LISTS>(5);
    EXPECT_EQ(myList.size(), 7);
    EXPECT_EQ(myList.at(0), 3);
    EXPECT_EQ(myList.at(1), 2);
    EXPECT_EQ(myList.at(2), 1);
    EXPECT_EQ(myList.at(3), 5);
    EXPECT_EQ(myList.at(4), 8);
    EXPECT_EQ(myList.at(5), 5);
    EXPECT_EQ(myList.at(6), 10);
}

TEST_F(PartitionAroundATest, PartitionAroundATest_UsingMoveToHead) {
    CPartitionAroundAValue<int> myList;
    myList.pushBack(3);
    myList.pushBack(5);
    myList.pushBack(8);
    myList.pushBack(5);
    myList.pushBack(10);
    myList.pushBack(2);
    myList.pushBack(1);
    myList.partitionAroundAValue<EPartitionMethod::USING_MOVE_TO_HEAD>(5);
    EXPECT_EQ(myList.size(), 7);
    EXPECT_EQ(myList.at(0), 1);
    EXPECT_EQ(myList.at(1), 2);
    EXPECT_EQ(myList.at(2), 3);
    EXPECT_EQ(myList.at(3), 5);
    EXPECT_EQ(myList.at(4), 8);
    EXPECT_EQ(myList.at(5), 5);
    EXPECT_EQ(myList.at(6), 10);    
}

TEST_F(PartitionAroundATest, PartitionAroundATest_UsingMoveToHead_EmptyList) {
    CPartitionAroundAValue<int> myList;
    myList.partitionAroundAValue<EPartitionMethod::USING_MOVE_TO_HEAD>(5);
    EXPECT_EQ(myList.size(), 0);
}

TEST_F(PartitionAroundATest, PartitionAroundATest_UsingMoveToHead_OneElement) {
    CPartitionAroundAValue<int> myList;
    myList.pushBack(5);
    myList.partitionAroundAValue<EPartitionMethod::USING_MOVE_TO_HEAD>(5);
    EXPECT_EQ(myList.size(), 1);
    EXPECT_EQ(myList.at(0), 5);
}

TEST_F(PartitionAroundATest, PartitionAroundATest_UsingMoveToHead_TwoElements) {
    CPartitionAroundAValue<int> myList;
    myList.pushBack(5);
    myList.pushBack(10);
    myList.partitionAroundAValue<EPartitionMethod::USING_MOVE_TO_HEAD>(3);
    EXPECT_EQ(myList.size(), 2);
    EXPECT_EQ(myList.at(0), 5);
    EXPECT_EQ(myList.at(1), 10);
}

TEST_F(PartitionAroundATest, PartitionAroundATest_UsingMoveToHead_TwoElements_ReverseOrder) {
    CPartitionAroundAValue<int> myList;
    myList.pushBack(10);
    myList.pushBack(5);
    myList.partitionAroundAValue<EPartitionMethod::USING_MOVE_TO_HEAD>(5);
    EXPECT_EQ(myList.size(), 2);
    EXPECT_EQ(myList.at(0), 10);
    EXPECT_EQ(myList.at(1), 5);
}