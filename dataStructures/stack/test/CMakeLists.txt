enable_testing()

# Create test executable
add_executable(stack_test
    stack_test.cpp
)


# Link against Google Test and the library being tested
target_link_libraries(stack_test
    PRIVATE
        GTest::gtest_main
        dataStructures::stack
)

# Add the test to CTest
include(GoogleTest)
gtest_discover_tests(stack_test) 