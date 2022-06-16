#!/bin/bash

if [ -d $HOME/performance/ ]; then
	echo "Directory is present !!"
else
	mkdir $HOME/performance ; echo "Directory Created"
fi
free >> $HOME/performance/memory.log

