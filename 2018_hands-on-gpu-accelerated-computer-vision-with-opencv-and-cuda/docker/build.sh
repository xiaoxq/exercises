#!/usr/bin/env bash

cd $(dirname $0)

source ENV.sh

docker build -t ${IMAGE} --build-arg CWD="${CWD}" .
