enable_testing()

# Create test executable
add_executable(linkedList_test
    linkedNode_test.cpp
    singlyLinkedList_test.cpp
)

# Add include directories
target_include_directories(linkedList_test
    PRIVATE
        ${CMAKE_SOURCE_DIR}/dataStructures/linkedList/inc
)

# Link against Google Test and the library being tested
target_link_libraries(linkedList_test
    PRIVATE
        GTest::gtest_main
        dataStructures::linkedList
)

# Add the test to CTest
include(GoogleTest)
gtest_discover_tests(linkedList_test) 