# Cracking the Coding Interview Solutions

This directory contains solutions to problems from the book "Cracking the Coding Interview" by Gayle Laakmann McDowell.

## Directory Structure

Each chapter from the book has its own directory:
- `chapter1/`: Arrays and Strings
- Additional chapters will be added as solutions are implemented

## Building and Running

This section uses CMake as its build system, with a convenient build script provided.

### Build Script Usage

```bash
./build.sh [-h] [-p <chapter>] [-c] [-t]
```

Options:
- `-h, --help`: Show help message and exit
- `-p, --chapter`: Build a specific chapter (e.g., `chapter1`)
- `-c, --clean`: Clean the build directory
- `-t, --test`: Enable testing

### Examples

1. Build all chapters:
```bash
./build.sh
```

2. Build a specific chapter:
```bash
./build.sh -p chapter1
```

3. Build and run tests:
```bash
./build.sh -t
```

4. Clean build and rebuild:
```bash
./build.sh -c
```

## Testing

Each problem solution includes unit tests. To run the tests:
```bash
./build.sh -t
```

The tests will be executed using CTest and any failures will be reported with details. 