#!/usr/bin/env bash

cd $(dirname $0)

COUNT=5

for i in $(seq ${COUNT}); do
  nvcc -G -g -o main_${i} ${i}_*.cu
done
