#!/bin/bash

# Exit on any error
set -e

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Navigate to the docker directory
cd "$(dirname "$0")"

# Check for .env file and create if it doesn't exist
if [ ! -f .env ]; then
    echo -e "${YELLOW}No .env file found. Creating from template...${NC}"
    if [ ! -f env.template ]; then
        echo -e "${RED}No env.template file found. Please check the repository.${NC}"
        exit 1
    fi
    cp env.template .env
    echo -e "${GREEN}Created .env file. Please edit it with your credentials.${NC}"
    echo -e "${YELLOW}Opening .env file for editing...${NC}"
    ${EDITOR:-vi} .env
fi

# Load environment variables
set -a
source .env
set +a

# Set default values if not in .env
IMAGE_NAME=${IMAGE_NAME:-datastructures}
IMAGE_TAG=${IMAGE_TAG:-latest}
LOCAL_IMAGE_NAME="$IMAGE_NAME:$IMAGE_TAG"
REMOTE_IMAGE_NAME="ghcr.io/$GITHUB_USERNAME/$IMAGE_NAME:$IMAGE_TAG"

echo -e "${YELLOW}Starting Docker development environment setup...${NC}"

# Check if Docker is running
if ! docker info > /dev/null 2>&1; then
    echo -e "${RED}Docker is not running. Please start Docker and try again.${NC}"
    exit 1
fi

echo -e "${YELLOW}What would you like to do?${NC}"
echo "1. Build Docker image and start container"
echo "2. Only build Docker image"
echo "3. Only start container (skip build)"
echo "4. Skip Docker Compose steps"
read -p "Enter your choice (1-4): " compose_choice

case $compose_choice in
    1)
        echo -e "${GREEN}Building Docker image...${NC}"
        docker-compose build
        echo -e "${GREEN}Starting container...${NC}"
        docker-compose up -d
        ;;
    2)
        echo -e "${GREEN}Building Docker image...${NC}"
        docker-compose build
        ;;
    3)
        echo -e "${GREEN}Starting container...${NC}"
        docker-compose up -d
        ;;
    *)
        echo -e "${YELLOW}Skipping Docker Compose build/start steps.${NC}"
        ;;
esac

if [ "$compose_choice" = "1" ] || [ "$compose_choice" = "3" ]; then
    echo -e "${GREEN}Container is ready!${NC}"

    # Check if running in VS Code
    if [ -n "$VSCODE_CLI" ] || [ -n "$VSCODE_EXTENSIONS_PATH" ]; then
        echo -e "${YELLOW}VS Code detected. You can now:${NC}"
        echo "1. Press F1 or Cmd/Ctrl+Shift+P"
        echo "2. Type 'Remote-Containers: Reopen in Container'"
        echo "3. Select the dev container configuration"
    else
        echo -e "${YELLOW}To access the container:${NC}"
        echo "docker-compose exec dev bash"
    fi
fi

# Check if GitHub credentials are configured
if [ -n "$GITHUB_USERNAME" ] && [ -n "$GITHUB_CR_PAT" ]; then
    echo -e "\n${YELLOW}GitHub Container Registry configuration detected. Would you like to:${NC}"
    echo "1. Login to GitHub Container Registry"
    echo "2. Push the image"
    echo "3. Skip GitHub Container Registry setup"
    read -p "Enter your choice (1-3): " choice

    case $choice in
        1)
            echo -e "${GREEN}Logging in to GitHub Container Registry...${NC}"
            echo "$GITHUB_CR_PAT" | docker login ghcr.io -u "$GITHUB_USERNAME" --password-stdin
            ;;
        2)
            echo -e "${GREEN}Pushing image to GitHub Container Registry...${NC}"
            # Verify the image exists
            if ! docker image inspect "$LOCAL_IMAGE_NAME" >/dev/null 2>&1; then
                echo -e "${RED}Error: Image $LOCAL_IMAGE_NAME not found. Make sure the build was successful.${NC}"
                exit 1
            fi
            echo -e "${GREEN}Tagging image as $REMOTE_IMAGE_NAME...${NC}"
            docker tag "$LOCAL_IMAGE_NAME" "$REMOTE_IMAGE_NAME"
            echo -e "${GREEN}Pushing image...${NC}"
            docker push "$REMOTE_IMAGE_NAME"
            ;;
        *)
            echo -e "${YELLOW}Skipping GitHub Container Registry setup${NC}"
            ;;
    esac
else
    echo -e "\n${YELLOW}To push to GitHub Container Registry:${NC}"
    echo "1. Edit the .env file with your GitHub credentials"
    echo "2. Run this script again"
fi