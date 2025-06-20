FROM ubuntu:22.04

# Prevent interactive prompts during package installation
ENV DEBIAN_FRONTEND=noninteractive

# Set up timezone (required for some package installations)
ENV TZ=UTC
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

# Install essential build tools and dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    gcc \
    g++ \
    gdb \
    cmake \
    make \
    git \
    curl \
    wget \
    vim \
    nano \
    zsh \
    software-properties-common \
    ccache \
    && rm -rf /var/lib/apt/lists/*

# Configure ccache for better performance
RUN ccache --max-size=10G && \
    ccache --set-config=compression=true && \
    ccache --set-config=compression_level=6 && \
    ccache --set-config=hash_dir=false && \
    ccache --set-config=sloppiness=file_macro,time_macros,include_file_mtime,include_file_ctime

# Add deadsnakes PPA for Python 3.11
RUN add-apt-repository ppa:deadsnakes/ppa && \
    apt-get update && \
    apt-get install -y \
    python3.11 \
    python3.11-venv \
    python3.11-dev \
    && rm -rf /var/lib/apt/lists/*

# Create symbolic links for python3.11
RUN update-alternatives --install /usr/bin/python3 python3 /usr/bin/python3.11 1 && \
    update-alternatives --set python3 /usr/bin/python3.11

# Install pip for Python 3.11
RUN curl -sS https://bootstrap.pypa.io/get-pip.py | python3.11

# Create a non-root user
ARG USERNAME=devuser
ARG USER_UID=1000
ARG USER_GID=$USER_UID

RUN groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME \
    && apt-get update \
    && apt-get install -y sudo \
    && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME

# Set zsh as default shell for the user
RUN chsh -s /usr/bin/zsh $USERNAME

# Set working directory
WORKDIR /workspace

# Switch to non-root user
USER $USERNAME 