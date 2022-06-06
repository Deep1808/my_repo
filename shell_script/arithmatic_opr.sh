#/bin/bash

a=10
b=20
#a=`expr $a + $b`

a=$(($a + $b))
echo "Value of A=$a"
