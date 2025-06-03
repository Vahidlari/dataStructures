#!/bin/bash

# A script to build the crackingCodingInterviews project
# The script receives an argument that is the chapter number to build
# The default behavior is to build all chapters
# To analyze the arguments, getopt is used
# The script should define a variable called CHAPTERS that contains the chapters to build. 
# CHAPTERS is an array of strings, each string is the name of a chapter. This variable 
# is passed to the CMakeLists.txt file in the crackingCodingInterviews directory.

# Initialize the CHAPTERS variable with subdirectories in the crackingCodingInterviews directory
# The subdirectories should be named chapter<number>
DEFAULTCHAPTERS=($(ls -d chapter*))

# Initialize variables
BUILD_TESTING=OFF
CLEAN_BUILD=OFF

# Define the usage function
usage() {
    echo "Usage: $0 [-h] [-p <chapter>] [-c] [-t]"
    echo "Build the crackingCodingInterviews project"
    echo "Options:"
    echo "  -h, --help     Show this help message and exit"
    echo "  -p, --chapter  Build a specific chapter"
    echo "  -c, --clean    Clean the build directory"
    echo "  -t, --test     Enable testing"
}

# Parse the arguments
while getopts "hp:ct" opt; do
    case "$opt" in
        h | --help)
            usage
            exit 0
        ;;
        p | --chapter)
            chapter=$OPTARG
            # Check if the chapter is in the DEFAULTCHAPTERS array
            if ! [[ " ${DEFAULTCHAPTERS[@]} " =~ " ${chapter} " ]]; then
                echo "Chapter ${chapter} not found"
                exit 1
            fi
        ;;
        c | --clean)
            # Clean the build directory
            CLEAN_BUILD=ON
        ;;
        t | --test)
            BUILD_TESTING=ON
        ;;
        *)
            usage
            exit 1
        ;;
    esac
done

# Clean the build directory if requested
if [ "${CLEAN_BUILD}" = "ON" ]; then
    rm -rf build
fi


# Print the DEFAULTCHAPTERS variable
echo "DEFAULTCHAPTERS: ${DEFAULTCHAPTERS[@]}"
echo "Testing enabled: ${BUILD_TESTING}"

# The project CMakeLists.txt requires a variable called CHAPTERS that contains the chapters to build.
# If the chapter is not specified, build all chapters
if [ -z "$chapter" ]; then
    CHAPTERS=("${DEFAULTCHAPTERS[@]}")
else
    CHAPTERS=("${chapter}")
fi

# Now build the project
# Create a build directory
mkdir -p build

# Run CMake to generate the build files
cmake -B build -S . -DCHAPTERS="${CHAPTERS[@]}" -DBUILD_TESTING=${BUILD_TESTING}
cmake --build build

# Run tests if testing is enabled
if [ "${BUILD_TESTING}" = "ON" ]; then
    cd build && ctest --output-on-failure
fi



