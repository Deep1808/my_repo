#!/bin/bash

#if [ $3 ='+']
#	echo "SUM of $1 and $2 = $(($1 + $2))"
#if [ $3 ='-']
#	echo "SUB of $1 and $2 = $(($1 - $2))"
#exit 0

echo "$((${2:-0 $1 ${3:-0}}))"
