enable_testing()

# Create test executable
add_executable(binarySearchTree_test
    binarySearchTree_test.cpp
)

# Add include directories
target_include_directories(binarySearchTree_test
    PRIVATE
        ${CMAKE_SOURCE_DIR}/dataStructures/binarySearchTree/inc
)

# Link against Google Test and the library being tested
target_link_libraries(binarySearchTree_test
    PRIVATE
        GTest::gtest_main
        dataStructures::binarySearchTree
)

# Add the test to CTest
include(GoogleTest)
gtest_discover_tests(binarySearchTree_test) 