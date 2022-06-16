#/bin/bash

a=10

until [ $a -lt 10 ]
do
	echo -n $a
	a=$((a+1))
done
