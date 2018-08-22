#!/usr/bin/env bash

cd $(dirname $0)

nvcc -o main_0 0_hello-cuda.cu
