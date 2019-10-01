#!/usr/bin/env bash

DIR=$( cd $(dirname "${BASH_SOURCE[0]}"); pwd )

conda env update --prune -f ${DIR}/conda.yaml
source activate $( grep ^name ${DIR}/conda.yaml | awk '{print $2}' )
