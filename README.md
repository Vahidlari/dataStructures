# Data Structures and Algorithms

This repository contains implementations of various data structures and algorithms, along with solutions to programming problems from different sources. The repository is organized into several main sections:

## Repository Structure

- **dataStructures/**: Implementation of fundamental data structures
- **graphs/**: Graph algorithms and related problems
- **Sorting/**: Various sorting algorithm implementations
- **crackingCodingInterviews/**: Solutions to problems from "Cracking the Coding Interview" book
- **tools/**: Utility functions and helper tools

## Getting Started

### Development Container

This repository includes a development container configuration that provides a consistent development environment with all necessary tools pre-installed. To use it:

1. Prerequisites:
   - [Visual Studio Code](https://code.visualstudio.com/)
   - [Docker](https://www.docker.com/get-started)
   - [VS Code Remote - Containers extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers)

2. Opening in Dev Container:
   ```bash
   # Clone the repository
   git clone [repository-url]
   cd [repository-name]

   # Open in VS Code
   code .

   # When prompted "Reopen in Container" click "Reopen in Container"
   # Or use Command Palette (F1) and select "Remote-Containers: Reopen in Container"
   ```

The dev container includes:
- C++ development tools
- CMake
- Build essentials
- Required extensions and configurations

### Prerequisites (for local development)

If you prefer not to use the dev container, you'll need:
- C++ compiler (supporting C++17 or later)
- CMake (3.14 or later)
- Make

### Building the Projects

The repository uses a unified build system that allows building either specific components or the entire codebase. The main build script (`build.sh`) provides several options:

1. Build everything:
   ```bash
   ./build.sh
   ```

2. Build a specific project:
   ```bash
   ./build.sh -p dataStructures          # Build all data structures
   ./build.sh -p crackingCodingInterviews  # Build all chapters
   ```

3. Build a specific component within a project:
   ```bash
   ./build.sh -p dataStructures -m linkedList  # Build just the linked list
   ./build.sh -p crackingCodingInterviews -m chapter1  # Build just chapter 1
   ```

4. Additional build options:
   ```bash
   # Enable testing in debug mode
   ./build.sh -t true -d Debug

   # Clean build
   ./build.sh -c true

   # Build specific component with testing enabled
   ./build.sh -p dataStructures -m binaryHeap -t true
   ```

The build script will automatically detect available components in each project and validate your selections. If you specify an invalid project or component, it will show an error message with the available options.

Build script options:
- `-p, --project`: Select project to build (dataStructures or crackingCodingInterviews)
- `-m, --component`: Build a specific component within the project
- `-c, --clean`: Clean the build directory (true/false)
- `-t, --test`: Enable testing (true/false)
- `-d, --debug`: Set build type (Debug or Release)
- `-h, --help`: Show help message

## Project Sections

Each major section has its own README with detailed information about its contents and usage. Please refer to the individual README files in each directory for more specific information.

## Contributing

Feel free to submit issues and enhancement requests!

## License

This code is as free as a bird soaring through the clouds! 🦅
(But please be nice and give credit if you use it somewhere)
