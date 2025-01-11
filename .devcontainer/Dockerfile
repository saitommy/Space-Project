FROM ubuntu:22.04

# install dev tools, SFML dependencies, and OpenGL support
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    libsfml-dev \
    libx11-dev \
    libxrandr-dev \
    libgl1-mesa-glx \
    libglu1-mesa \
    mesa-utils \
    libxext-dev \
    libxrender-dev \ 
    && apt-get clean

# set the working directory in container
WORKDIR /app

# copy the project files into container
COPY . /app

# run CMake to configure the project and build it
RUN mkdir build && cd build && \
    cmake .. && \
    make

# default command: run bash
CMD ["bash"]
