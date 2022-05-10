enable_testing()

# Create test executable
add_executable(baseDataType_test
    baseDataType_test.cpp
)

# Add include directories
target_include_directories(baseDataType_test
    PRIVATE
        ${CMAKE_SOURCE_DIR}/dataStructures/baseDataType/inc
)

# Link against Google Test and the library being tested
target_link_libraries(baseDataType_test
    PRIVATE
        GTest::gtest_main
        dataStructures::baseDataType
)

# Add the test to CTest
include(GoogleTest)
gtest_discover_tests(baseDataType_test) 