#include <gtest/gtest.h>
#include "chapter2/get_kth_to_last.hpp"

class GetKthToLastTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Any setup code would go here
    }
};

TEST_F(GetKthToLastTest, GetKthToLastRecursive) {
    CGetKthToLast<int, EGetKthToLastMethod::RECURSIVE> myList;
    myList.pushBack(1);
    myList.pushBack(2);
    myList.pushBack(3);
    myList.pushBack(4);
    myList.pushBack(5);
    EXPECT_EQ(myList.getKthToLast(2)->getData(), 4);
    EXPECT_EQ(myList.getKthToLast(6), nullptr);
    EXPECT_EQ(myList.getKthToLast(0), nullptr);
    EXPECT_EQ(myList.getKthToLast(1)->getData(), 5);
    EXPECT_EQ(myList.getKthToLast(5)->getData(), 1);
}

TEST_F(GetKthToLastTest, GetKthToLastTwoPointers) {
    CGetKthToLast<int, EGetKthToLastMethod::TWO_POINTERS> myList;
    myList.pushBack(1);
    myList.pushBack(2);
    myList.pushBack(3);
    myList.pushBack(4);
    myList.pushBack(5);
    EXPECT_EQ(myList.getKthToLast(2)->getData(), 4);
    EXPECT_EQ(myList.getKthToLast(6), nullptr);
    EXPECT_EQ(myList.getKthToLast(0), nullptr);
    EXPECT_EQ(myList.getKthToLast(1)->getData(), 5);
    EXPECT_EQ(myList.getKthToLast(5)->getData(), 1);
}
