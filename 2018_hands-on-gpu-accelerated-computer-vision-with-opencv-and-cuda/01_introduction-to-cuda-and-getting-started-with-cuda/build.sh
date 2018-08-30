#!/usr/bin/env bash

cd $(dirname $0)

COUNT=1

for i in $(seq 0 ${COUNT}); do
  nvcc -G -g -o main_${i} ${i}_*.cu
done
