# Glob all test files
file(GLOB_RECURSE TEST_FILES "*.cpp")

# Create the test executable
add_executable(${PROJECT_NAME}_tests ${TEST_FILES})

# Link against the library and Google Test
target_link_libraries(${PROJECT_NAME}_tests
    PRIVATE
        ${PROJECT_NAME}_lib
        GTest::gtest_main
)

# Ensure debug symbols are generated for the test executable
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(${PROJECT_NAME}_tests PRIVATE -g)
endif()

# Include test directories
target_include_directories(${PROJECT_NAME}_tests
    PRIVATE
        ${CMAKE_SOURCE_DIR}/inc
)

# Discover and add tests
include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}_tests)