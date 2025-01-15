# Running Project using Docker

Follow these steps to build and run the project in a Docker container.

## Prerequisites
- **Docker Desktop** must be installed and running. If you don't have Docker, [download it here](https://www.docker.com/products/docker-desktop).

- **X11 Server Setup**
  - **vcxsrv for Windows**
    - Install
    - Configure
    - Test
    - Allow Docker
  - **XQuartz for macOS**
    - Install XQuartz from [here](https://www.xquartz.org/).
    - Once XQuartz is running, go to `XQuartz Preferences > Security` and make sure **"Allow connections from network clients"** is checked.
    - To configure XQuartz, run the following commands in your terminal:
        ```bash
        defaults write org.xquartz.X11 enable_iglx -bool true

        export DISPLAY=host.docker.internal:0

        export DISPLAY=:0
        ```

    - To test if XQuartz is working, run the command: ```xeyes```

    - To allow Docker to connect to X11 by running the command: ```xhost +```

<br>
<br>

## Steps

### 1. **Start Docker Desktop**  
   Ensure that Docker Desktop is running on your system.

### 2. **Build the Docker Image**  
   In the root directory of the project, open a terminal and run the following command to build the Docker image from the `Dockerfile` located in the `.devcontainer` folder:
   ```bash
   docker build -t spaceproject -f .devcontainer/Dockerfile .
   ```
### 3. Run the Docker Container
After building the image, run the following command to start the container and set the `DISPLAY` environment variable so that the application can use your local display:

```bash
docker run -it --rm -e DISPLAY=host.docker.internal:0 spaceproject
```

### 4. Start the Project
Once inside the container, run the following command to start the application:

```bash
./buildmac/bin/SpaceProject
```

### 5. Exiting Project
If you're running an interactive application, you can exit by pressing `Ctrl + C`
