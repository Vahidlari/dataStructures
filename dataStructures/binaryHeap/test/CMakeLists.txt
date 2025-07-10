enable_testing()

# Create test executable
add_executable(binaryHeap_test
    binaryHeap_test.cpp
    baseDataType_test.cpp
)

# Add include directories
# target_include_directories(binaryHeap_test
#     PRIVATE
#         ${CMAKE_SOURCE_DIR}/dataStructures/binaryHeap/inc
# )

# Link against Google Test and the library being tested
target_link_libraries(binaryHeap_test
    PRIVATE
        GTest::gtest_main
        dataStructures::binaryHeap
)

# Add the test to CTest
include(GoogleTest)
gtest_discover_tests(binaryHeap_test) 