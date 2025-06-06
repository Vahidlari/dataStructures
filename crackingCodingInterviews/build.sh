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

# Function to convert binary input to ON/OFF
to_onoff() {
    local value=$(echo "$1" | tr '[:upper:]' '[:lower:]')
    case "$value" in
        true|1|yes|on) echo "ON" ;;
        false|0|no|off) echo "OFF" ;;
        *) echo "Invalid binary value: $1" >&2; exit 1 ;;
    esac
}

# Define the usage function
usage() {
    echo "Usage: $0 [-h] [-p <chapter>] [-c <true|false>] [-t <true|false>]"
    echo "Build the crackingCodingInterviews project"
    echo "Options:"
    echo "  -h, --help     Show this help message and exit"
    echo "  -p, --chapter  Build a specific chapter"
    echo "  -c, --clean    Clean the build directory (accepts: true/false, 1/0, yes/no, on/off)"
    echo "  -t, --test     Enable testing (accepts: true/false, 1/0, yes/no, on/off)"
}

# Parse the arguments
while getopts "hp:c:t:" opt; do
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
            # Convert binary input to ON/OFF
            CLEAN_BUILD=$(to_onoff "$OPTARG")
        ;;
        t | --test)
            BUILD_TESTING=$(to_onoff "$OPTARG")
        ;;
        *)
            usage
            exit 1
        ;;
    esac
done

# Clean the build directory if requested
if [ "${CLEAN_BUILD}" = "ON" ]; then
    rm -rf _build
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
mkdir -p _build

# Run CMake to generate the build files
cmake -B _build -S . -DCHAPTERS="${CHAPTERS[@]}" -DBUILD_TESTING=${BUILD_TESTING}
cmake --build _build

# Run tests if testing is enabled
if [ "${BUILD_TESTING}" = "ON" ]; then
    cd _build && ctest --output-on-failure
fi



