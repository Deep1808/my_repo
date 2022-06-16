#!/bin/bash

a=$(cat file1.txt)
b=$(cat file2.txt)
c=$(cat file2.txt)

if [ $a -eq $b ] && [ $a -eq $c ] ; then
	rm file3.txt file2.txt
else 
	echo "File are not same"
fi

exit 0
