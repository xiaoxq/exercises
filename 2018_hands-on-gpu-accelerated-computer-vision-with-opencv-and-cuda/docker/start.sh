#!/usr/bin/env bash

ROOT=$(cd "$(dirname "$0")/.."; pwd)
source "${ROOT}/docker/ENV.sh"

docker run -it --rm \
    --runtime=nvidia \
    --net host \
    --name ${CONTAINER} \
    -v "${ROOT}":${CWD} \
    ${IMAGE} bash
