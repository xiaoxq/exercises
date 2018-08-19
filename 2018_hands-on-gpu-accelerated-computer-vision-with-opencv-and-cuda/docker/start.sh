#!/usr/bin/env bash

WORKDIR=$(cd "$(dirname "$0")/.."; pwd)
source "${WORKDIR}/docker/ENV.sh"

docker run -it --rm \
    --runtime=nvidia \
    --net host \
    --name ${CONTAINER} \
    -v "${WORKDIR}":${CWD} \
    ${IMAGE} bash
