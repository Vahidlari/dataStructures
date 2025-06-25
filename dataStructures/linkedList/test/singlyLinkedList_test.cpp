#include <gtest/gtest.h>
#include "dataStructures/singlyLinkedList.hpp"

class SinglyLinkedListTest : public ::testing::Test {
protected:
    void SetUp() override {
        list = new dataStructures::CSinglyLinkedList<int>();
        share_ptr_list = new dataStructures::CSinglyLinkedList<int, std::shared_ptr>();
    }
    void TearDown() override {
        delete list;
        delete share_ptr_list;
    }
    dataStructures::CSinglyLinkedList<int>* list;
    dataStructures::CSinglyLinkedList<int, std::shared_ptr>* share_ptr_list;
};

TEST_F(SinglyLinkedListTest, DefaultConstructor) {
    EXPECT_TRUE(list->empty());
    EXPECT_EQ(list->size(), 0);
}

TEST_F(SinglyLinkedListTest, PushFront) {
    list->pushFront(1);
    EXPECT_FALSE(list->empty());
    EXPECT_EQ(list->size(), 1);
    EXPECT_EQ(list->at(0), 1);
}

TEST_F(SinglyLinkedListTest, PushFrontSharedPtr) {
    share_ptr_list->pushFront(1);
    EXPECT_FALSE(share_ptr_list->empty());
    EXPECT_EQ(share_ptr_list->size(), 1);
    EXPECT_EQ(share_ptr_list->at(0), 1);
}

TEST_F(SinglyLinkedListTest, PushBack) {
    list->pushBack(1);
    EXPECT_FALSE(list->empty());
    EXPECT_EQ(list->size(), 1);
    EXPECT_EQ(list->at(0), 1);
}

TEST_F(SinglyLinkedListTest, PushBackSharedPtr) {
    share_ptr_list->pushBack(1);
    EXPECT_FALSE(share_ptr_list->empty());
    EXPECT_EQ(share_ptr_list->size(), 1);
    EXPECT_EQ(share_ptr_list->at(0), 1);
}

TEST_F(SinglyLinkedListTest, PopFront) {
    list->pushFront(1);
    EXPECT_EQ(list->popFront(), 1);
    EXPECT_TRUE(list->empty());
    EXPECT_EQ(list->size(), 0);
}

TEST_F(SinglyLinkedListTest, PopFrontSharedPtr) {
    share_ptr_list->pushFront(1);
    EXPECT_EQ(share_ptr_list->popFront(), 1);
    EXPECT_TRUE(share_ptr_list->empty());
    EXPECT_EQ(share_ptr_list->size(), 0);
}

TEST_F(SinglyLinkedListTest, PopBackSharedPtr) {
    share_ptr_list->pushBack(1);
    EXPECT_EQ(share_ptr_list->popBack(), 1);
    EXPECT_TRUE(share_ptr_list->empty());
    EXPECT_EQ(share_ptr_list->size(), 0);
}

TEST_F(SinglyLinkedListTest, PopBack) {
    list->pushBack(1);
    EXPECT_EQ(list->popBack(), 1);
    EXPECT_TRUE(list->empty());
    EXPECT_EQ(list->size(), 0);
}

TEST_F(SinglyLinkedListTest, RemoveSharedPtr) {
    share_ptr_list->pushFront(1);
    share_ptr_list->pushFront(2);
    share_ptr_list->pushFront(3);
    EXPECT_TRUE(share_ptr_list->remove(2));
    EXPECT_EQ(share_ptr_list->size(), 2);
    EXPECT_EQ(share_ptr_list->at(0), 3);
    EXPECT_EQ(share_ptr_list->at(1), 1);
}

TEST_F(SinglyLinkedListTest, Remove) {
    list->pushFront(1);
    list->pushFront(2);
    list->pushFront(3);
    EXPECT_TRUE(list->remove(2));
    EXPECT_EQ(list->size(), 2);
    EXPECT_EQ(list->at(0), 3);
    EXPECT_EQ(list->at(1), 1);
}


TEST_F(SinglyLinkedListTest, At) {
    list->pushFront(1);
    list->pushFront(2);
    list->pushFront(3);
    EXPECT_EQ(list->at(0), 3);
    EXPECT_EQ(list->at(1), 2);
    EXPECT_EQ(list->at(2), 1);
}

TEST_F(SinglyLinkedListTest, Contains) {
    list->pushFront(1);
    list->pushFront(2);
    list->pushFront(3);
    EXPECT_TRUE(list->contains(2));
    EXPECT_FALSE(list->contains(4));
}

TEST_F(SinglyLinkedListTest, Size) {
    list->pushFront(1);
    list->pushFront(2);
    list->pushFront(3);
    EXPECT_EQ(list->size(), 3);
}

TEST_F(SinglyLinkedListTest, Empty) {
    EXPECT_TRUE(list->empty());
}

TEST_F(SinglyLinkedListTest, Reverse) {
    list->pushFront(1);
    list->pushFront(2);
    list->pushFront(3);
    list->reverse();
    EXPECT_EQ(list->at(0), 1);
    EXPECT_EQ(list->at(1), 2);
    EXPECT_EQ(list->at(2), 3);
}

TEST_F(SinglyLinkedListTest, ClearSharedPtr) {
    share_ptr_list->pushFront(1);
    share_ptr_list->pushFront(2);
    share_ptr_list->pushFront(3);
    share_ptr_list->clear();
    EXPECT_TRUE(share_ptr_list->empty());
    EXPECT_EQ(share_ptr_list->size(), 0);
}

TEST_F(SinglyLinkedListTest, Clear) {
    list->pushFront(1);
    list->pushFront(2);
    list->pushFront(3);
    list->clear();
    EXPECT_TRUE(list->empty());
    EXPECT_EQ(list->size(), 0);
}

TEST_F(SinglyLinkedListTest, Insert) {
    list->pushFront(1);
    list->pushFront(2);
    list->pushFront(3);
    list->insert(1, 4);
    EXPECT_EQ(list->at(0), 3);
    EXPECT_EQ(list->at(1), 4);
    EXPECT_EQ(list->at(2), 2);
    EXPECT_EQ(list->at(3), 1);
}

TEST_F(SinglyLinkedListTest, EquityOperator) {
    dataStructures::CSinglyLinkedList<int> list2;
    list2.pushFront(1);
    list2.pushFront(2);
    list2.pushFront(3);
    
    EXPECT_EQ(*list, *list); // Self comparison
    EXPECT_NE(*list, list2); // Different lists
}

TEST_F(SinglyLinkedListTest, Destructor) {
    // Create a new list in this scope
    auto* tempList = new dataStructures::CSinglyLinkedList<int>();
    tempList->pushFront(1);
    tempList->pushFront(2);
    tempList->pushFront(3);
    
    // Delete should not crash
    delete tempList;
    
    //EXPECT_TRUE(tempList->empty());
    EXPECT_EQ(tempList->size(), 0);

}

TEST_F(SinglyLinkedListTest, OutOfRangeAt) {
    list->pushFront(1);
    list->pushFront(2);
    list->pushFront(3);
    EXPECT_THROW(list->at(3), std::out_of_range);
}

TEST_F(SinglyLinkedListTest, OutOfRangeInsert) {
    list->pushFront(1);
    list->pushFront(2);
    list->pushFront(3);
    EXPECT_THROW(list->insert(4, 4), std::out_of_range);
}

TEST_F(SinglyLinkedListTest, OutOfRangeInsertNegative) {
    list->pushFront(1);
    list->pushFront(2);
    list->pushFront(3);
    EXPECT_THROW(list->insert(-1, 4), std::out_of_range);
}


TEST_F(SinglyLinkedListTest, RuntimeErrorPopFront) {
    EXPECT_THROW(list->popFront(), std::runtime_error);
}

TEST_F(SinglyLinkedListTest, RuntimeErrorPopBack) {
    EXPECT_THROW(list->popBack(), std::runtime_error);
}

TEST_F(SinglyLinkedListTest, emptyRemove) {
    EXPECT_FALSE(list->remove(1));
}

TEST_F(SinglyLinkedListTest, OutOfRangeEmptyListAt) {
    EXPECT_THROW(list->at(0), std::out_of_range);
}

TEST_F(SinglyLinkedListTest, OutOfRangeEmptyListInsert) {
    EXPECT_THROW(list->insert(1, 1), std::out_of_range);
}

