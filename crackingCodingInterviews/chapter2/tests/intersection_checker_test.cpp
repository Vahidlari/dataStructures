#include <gtest/gtest.h>
#include "chapter2/intersection_checker.hpp"

class IntersectionCheckerTest : public ::testing::Test {
protected:
    void SetUp() override { 
        // Initialize two lists with no intersection
        list1 = CAppendableSinglyLinkedList<int>();
        list2 = CAppendableSinglyLinkedList<int>();

        // Append nodes to the first list
        for (int i = 1; i <= 5; ++i) {
            list1.pushBack(i);
        }

        // Append nodes to the second list
        for (int i = 6; i <= 10; ++i) {
            list2.pushBack(i);
        }
    }
    void TearDown() override {
        // Clear the lists after each test
        list1.clear();
        list2.clear();
    }

    CAppendableSinglyLinkedList<int> list1;
    CAppendableSinglyLinkedList<int> list2;
};

TEST_F(IntersectionCheckerTest, NoIntersection) {
    // Check that the lists do not intersect
    EXPECT_EQ(checkIntersection(list1, list2), nullptr);
}

TEST_F(IntersectionCheckerTest, IntersectionAtTail) {
    // Create an intersection at the tail of both lists
    CAppendableSinglyLinkedList<int> intersection;
    for (int i = 11; i <= 15; ++i) {
        intersection.pushBack(i);
    }

    // Append the intersection to both lists
    list1.append(intersection.getHead());
    list2.append(intersection.getHead());

    // Check that the lists intersect at the tail
    EXPECT_EQ(checkIntersection(list1, list2), intersection.getHead());
}

TEST_F(IntersectionCheckerTest, IntersectionWithDifferentSizes) {
    // Create an intersection with different sizes
    CAppendableSinglyLinkedList<int> intersection;
    for (int i = 16; i <= 20; ++i) {
        intersection.pushBack(i);
    }

    // Make list1 larger than list2
    for (int i = 20; i <= 25; ++i) {
        list1.pushBack(i);
    }

    // Append the intersection to both lists
    list1.append(intersection.getHead());
    list2.append(intersection.getHead());

    // Check that the lists intersect at the first node of the intersection
    EXPECT_EQ(checkIntersection(list1, list2), intersection.getNodeAt(0));
}

TEST_F(IntersectionCheckerTest, EmptyList) {
    // Check intersection with an empty list
    CAppendableSinglyLinkedList<int> emptyList;

    // Expect no intersection
    EXPECT_EQ(checkIntersection(list1, emptyList), nullptr);
    EXPECT_EQ(checkIntersection(emptyList, list2), nullptr);
}

TEST_F(IntersectionCheckerTest, BothEmptyLists) {
    // Check intersection with two empty lists
    CAppendableSinglyLinkedList<int> emptyList1;
    CAppendableSinglyLinkedList<int> emptyList2;

    // Expect no intersection
    EXPECT_EQ(checkIntersection(emptyList1, emptyList2), nullptr);
}

TEST_F(IntersectionCheckerTest, SelfIntersection) {
    // Check intersection of a list with itself
    CAppendableSinglyLinkedList<int> selfList;
    for (int i = 1; i <= 5; ++i) {
        selfList.pushBack(i);
    }

    // Expect the intersection to be the head of the list
    EXPECT_EQ(checkIntersection(selfList, selfList), selfList.getHead());
}

