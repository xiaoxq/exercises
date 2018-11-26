#!/usr/bin/env bash

cd $(dirname $0)

COUNT=7

for i in $(seq ${COUNT}); do
  nvcc -G -g -o main_${i} ${i}_*.cu
done
