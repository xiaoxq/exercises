FROM nvidia/cuda:9.2-cudnn7-devel-ubuntu18.04
MAINTAINER Aaron Xiao <xiaoxiangquan@gmail.com>

ENV DEBIAN_FRONTEND=noninteractive

# Work directory where we will mount the project root.
ARG CWD=/home/work
VOLUME ${CWD}
WORKDIR ${CWD}

# Required tools and libs.
RUN apt-get update -y && apt-get install -y git nvidia-cuda-toolkit vim
