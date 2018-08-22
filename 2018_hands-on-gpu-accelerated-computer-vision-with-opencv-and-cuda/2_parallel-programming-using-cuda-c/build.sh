#!/usr/bin/env bash

cd $(dirname $0)

nvcc -o main_0 0_two-variable-addition-program-in-cuda-c.cu
nvcc -o main_1 1_passing-parameter-by-reference.cu
nvcc -o main_2 2_thread-execution-on-a-device.cu
nvcc -o main_3 3_accessing-gpu-device-properties-from-cuda-programs.cu
nvcc -o main_4 4_two-vector-addition-program.cu
