#!/usr/bin/env bash

cd $(dirname $0)

nvcc -o 0_main 0_hello-cuda.cu
