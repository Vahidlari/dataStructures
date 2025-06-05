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
- CMake (3.10 or later)
- Make

### Building the Projects

Different sections of this repository might have different build systems:

1. For CMake-based projects:
   ```bash
   mkdir _build
   cd _build
   cmake ..
   make
   ```

2. For the crackingCodingInterviews section:
   ```bash
   cd crackingCodingInterviews
   ./build.sh      # Build all chapters
   ./build.sh -p chapter1    # Build specific chapter
   ./build.sh -t   # Build and run tests
   ```

## Project Sections

Each major section has its own README with detailed information about its contents and usage. Please refer to the individual README files in each directory for more specific information.

## Contributing

Feel free to submit issues and enhancement requests!

## License

This code is as free as a bird soaring through the clouds! 🦅
(But please be nice and give credit if you use it somewhere)
