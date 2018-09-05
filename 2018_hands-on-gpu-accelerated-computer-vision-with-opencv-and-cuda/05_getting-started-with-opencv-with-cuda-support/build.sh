#!/usr/bin/env bash

cd $(dirname $0)

COMPILE="g++ -std=c++11 $(pkg-config --libs --cflags opencv)"

COUNT=7
for i in $(seq 0 ${COUNT}); do
  ${COMPILE} -o main_${i} ${i}_*.cc
done
