#!/usr/bin/env bash
cd $(dirname $0)

COMPILE="g++ -std=c++11 $(pkg-config --libs --cflags opencv)"

COUNT=2
for i in $(seq ${COUNT}); do
  ${COMPILE} -o main_${i} ${i}_*.cc
done
