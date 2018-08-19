# Hands-On GPU-Accelerated Computer Vision with OpenCV and CUDA

## Environment

Tested on Ubuntu 18.04, but should be easy to migrate as it uses docker.

1. Check https://docs.docker.com/install/linux/docker-ce/ubuntu and
   https://github.com/NVIDIA/nvidia-docker to install docker and nvidia-docker.

1. Build docker image.

   ```bash
   docker/build.sh
   ```

1. Start container.
   ```bash
   docker/start.sh
   ```

## Known issues

1. "unsatisfied condition: cuda >= 9.2"

   You need a driver 396+ to run CUDA 9.2. So just downgrade to CUDA 9.1.
