#!/usr/bin/env bash

cd $(dirname $0)

nvcc -o 0_main 0_two-variable-addition-program-in-cuda-c.cu
nvcc -o 1_main 1_passing-parameter-by-reference.cu
