#!/bin/bash

export GENGINE_DISTRIBUTED=1
export GENGINE=$(readlink -e .)
export PATH=${GENGINE}/scripts:${PATH}

pushd $1

${SHELL} -c 'gengine-compile'
