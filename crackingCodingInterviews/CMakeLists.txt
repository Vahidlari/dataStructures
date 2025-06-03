# Top level CMakeLists.txt for crackingCodingInterviews

cmake_minimum_required(VERSION 3.20.0)

project(crackingCodingInterviews C CXX)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add option for building tests
option(BUILD_TESTING "Build the testing tree." OFF)

# Only include GoogleTest if testing is enabled
if(BUILD_TESTING)
    # Include FetchContent for downloading GoogleTest
    include(FetchContent)

    # Download and configure GoogleTest
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.14.0
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    # Enable testing
    enable_testing()
endif()

# Add subdirectories for each chapter based on a Cmake variable called CHAPTERS
foreach(CHAPTER ${CHAPTERS})
    add_subdirectory(${CHAPTER})
    # Add a compile switch for the chapter. This switch is used to enable the test functions for the chapter in the main function
    add_compile_options(-DENABLE_CHAPTER_${CHAPTER})
endforeach()