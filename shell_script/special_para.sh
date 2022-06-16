#!/bin/bash

IFS=,
echo $@
touch "$@"
echo $*
echo "$*"
