#!/bin/bash

export GENGINE_DISTRIBUTED=1
export GENGINE=$(readlink -e .)
export PATH=${GENGINE}/scripts:${PATH}

${SHELL} -i
