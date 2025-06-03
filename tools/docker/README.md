# Development Environment Docker Setup

This directory contains Docker configuration for setting up a development environment for the Data Structures and Algorithms project.

## Features

- Ubuntu 22.04 base image
- GCC compiler and build tools
- CMake build system
- Python 3.11 with pip
- Non-root user setup for better security
- VS Code DevContainer support
- Environment-based configuration for GitHub Container Registry

## Quick Start

The easiest way to get started is to use the provided setup script:

```bash
# Make sure you're in the project root directory
cd tools/docker
./setup.sh
```

The script will:
1. Check if Docker is running
2. Create and prompt you to configure the `.env` file if it doesn't exist
3. Build the development container
4. Start the container
5. Provide instructions for VS Code integration or manual access
6. Handle GitHub Container Registry setup if configured

### Environment Configuration

The setup uses a `.env` file for configuration. A template (`env.template`) is provided with the following variables:

```bash
# GitHub Container Registry Configuration
GITHUB_USERNAME=your-github-username
GITHUB_CR_PAT=your-personal-access-token

# Docker Image Configuration
IMAGE_NAME=datastructures
IMAGE_TAG=latest
```

The setup script will automatically create a `.env` file from this template if it doesn't exist and prompt you to edit it.

## Manual Setup

### Prerequisites

1. Install Docker and Docker Compose
2. Install Visual Studio Code
3. Install the "Remote - Containers" extension in VS Code
4. (Optional) GitHub account for container registry access

### Using VS Code DevContainer

1. Open the project in VS Code
2. When prompted, click "Reopen in Container" 
   - Or use the command palette (F1) and select "Remote-Containers: Reopen in Container"
3. Wait for the container to build and start
4. You're ready to code!

### Manual Docker Usage

To build and run the container manually:

```bash
# From the tools/docker directory
docker-compose build
docker-compose up -d
docker-compose exec dev bash
```

### GitHub Container Registry

To use the GitHub Container Registry:

1. Set up GitHub Container Registry access:
   - Go to GitHub Settings → Developer Settings → Personal Access Tokens
   - Generate a new token with `read:packages`, `write:packages`, and `delete:packages` permissions
   - For private repositories, also add `repo` scope

2. Configure your environment:
   - Copy `env.template` to `.env`
   - Edit `.env` with your GitHub username and PAT
   - Run `./setup.sh` and choose the appropriate options

3. Pull the image on another machine:
   ```bash
   docker pull ghcr.io/YOUR_GITHUB_USERNAME/datastructures:latest
   ```

## Customization

- Modify `Dockerfile` to add additional tools and dependencies
- Adjust `devcontainer.json` to customize VS Code settings and extensions
- Update `docker-compose.yml` to modify container configuration
- Edit `env.template` to add new configuration variables

## Troubleshooting

1. If the container fails to build:
   - Check Docker daemon is running
   - Ensure you have internet connectivity
   - Try running `docker system prune` to clean up old images

2. If VS Code fails to connect:
   - Ensure the Remote - Containers extension is installed
   - Try reloading VS Code
   - Check the Remote - Containers output panel for errors

3. If GitHub Container Registry push fails:
   - Verify your Personal Access Token has the correct permissions
   - Check your `.env` file configuration
   - Ensure you're logged in to ghcr.io
   - Check if your repository has packages enabled in Settings

4. If the `.env` file is not being recognized:
   - Make sure you're in the correct directory (tools/docker)
   - Check file permissions
   - Try creating the file manually from the template 