FROM nvidia/cuda:9.1-cudnn7-devel-ubuntu16.04
MAINTAINER Aaron Xiao <xiaoxiangquan@gmail.com>

ENV DEBIAN_FRONTEND=noninteractive

# Work directory where we will mount the project root.
ARG CWD=/home/work
VOLUME ${CWD}
WORKDIR ${CWD}

# Required tools and libs.
# TODO(xiaoxq): Merge layers when they become stable.
RUN apt-get update -y && apt-get install -y git vim
#RUN apt-get install -y nvidia-cuda-toolkit
