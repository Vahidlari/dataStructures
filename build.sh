#!/bin/bash

# A script to build the DataStructures project
# The script can build specific data structures or all of them
# To analyze the arguments, getopt is used

# Initialize variables
BUILD_TESTING=false
CLEAN_BUILD=false
BUILD_TYPE="Release"
BUILD_DIR="_build"
PROJECT=""
COMPONENT=""

# Get the list of available projects
PROJECTS=("dataStructures" "crackingCodingInterviews")

# Function to get components for a project
get_components() {
    local project=$1
    if [ -d "$project" ]; then
        echo $(ls -d ${project}/*/ | grep -v "CMakeFiles" | sed "s/${project}\///g" | sed 's/\///g')
    else
        echo ""
    fi
}

# Function to convert binary input to true/false
to_bool() {
    local value=$(echo "$1" | tr '[:upper:]' '[:lower:]')
    case "$value" in
        true|1|yes|on) echo "true" ;;
        false|0|no|off) echo "false" ;;
        *) echo "Invalid binary value: $1" >&2; exit 1 ;;
    esac
}

# Define the usage function
usage() {
    echo "Usage: $0 [-h] [-p <project>] [-m <component>] [-c <true|false>] [-t <true|false>] [-d <Debug|Release>]"
    echo "Build the DataStructures and Algorithms project"
    echo "Options:"
    echo "  -h, --help      Show this help message and exit"
    echo "  -p, --project   Select project to build (dataStructures or crackingCodingInterviews)"
    echo "  -m, --component Build a specific component within the project"
    echo "  -c, --clean     Clean the build directory (accepts: true/false, 1/0, yes/no, on/off)"
    echo "  -t, --test      Enable testing (accepts: true/false, 1/0, yes/no, on/off)"
    echo "  -d, --debug     Set build type (Debug or Release)"
}

# Parse the arguments
while getopts "hp:m:c:t:d:" opt; do
    case "$opt" in
        h | --help)
            usage
            exit 0
        ;;
        p | --project)
            PROJECT=$OPTARG
            # Check if the project exists
            if ! [[ " ${PROJECTS[@]} " =~ " ${PROJECT} " ]]; then
                echo "Project ${PROJECT} not found"
                echo "Available projects: ${PROJECTS[@]}"
                exit 1
            fi
        ;;
        m | --component)
            COMPONENT=$OPTARG
            # If project is specified, check if component exists in project
            if [ -n "$PROJECT" ]; then
                COMPONENTS=($(get_components "$PROJECT"))
                if ! [[ " ${COMPONENTS[@]} " =~ " ${COMPONENT} " ]]; then
                    echo "Component ${COMPONENT} not found in project ${PROJECT}"
                    echo "Available components: ${COMPONENTS[@]}"
                    exit 1
                fi
            fi
        ;;
        c | --clean)
            # Convert binary input to true/false
            CLEAN_BUILD=$(to_bool "$OPTARG")
        ;;
        t | --test)
            BUILD_TESTING=$(to_bool "$OPTARG")
        ;;
        d | --debug)
            BUILD_TYPE=$OPTARG
            if [[ "$BUILD_TYPE" != "Debug" && "$BUILD_TYPE" != "Release" ]]; then
                echo "Invalid build type: $BUILD_TYPE"
                echo "Valid options are: Debug, Release"
                exit 1
            fi
        ;;
        *)
            usage
            exit 1
        ;;
    esac
done

# Clean the build directory if requested
if [ "${CLEAN_BUILD}" = "true" ]; then
    echo "Cleaning build directory..."
    rm -rf "${BUILD_DIR}"
fi

# Print build configuration
echo "Build configuration:"
echo "  Available projects: ${PROJECTS[@]}"
echo "  Testing enabled: ${BUILD_TESTING}"
echo "  Build type: ${BUILD_TYPE}"
echo "  Build directory: ${BUILD_DIR}"

if [ -n "$PROJECT" ]; then
    echo "  Building project: ${PROJECT}"
    COMPONENTS=($(get_components "$PROJECT"))
    echo "  Available components: ${COMPONENTS[@]}"
    if [ -n "$COMPONENT" ]; then
        echo "  Building component: ${COMPONENT}"
    else
        echo "  Building all components"
    fi
else
    echo "  Building all projects"
fi

# Create build directory
mkdir -p "${BUILD_DIR}"

# Run CMake to generate the build files
echo "Configuring CMake..."
cmake -B "${BUILD_DIR}" -S . \
    -DCMAKE_BUILD_TYPE=${BUILD_TYPE} \
    -DBUILD_TESTING=${BUILD_TESTING} \
    ${PROJECT:+-DSELECTED_PROJECT=${PROJECT}} \
    ${COMPONENT:+-DSELECTED_COMPONENT=${COMPONENT}}

# Build the project
echo "Building project..."
cmake --build "${BUILD_DIR}" --config ${BUILD_TYPE}

# Run tests if testing is enabled
if [ "${BUILD_TESTING}" = "true" ]; then
    echo "Running tests..."
    cd "${BUILD_DIR}" && ctest --output-on-failure --build-config ${BUILD_TYPE}
fi 