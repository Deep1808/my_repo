#/bin/bash

#sum=0

add ()
{
	#echo "Enter value of A:"
	#read $1
	#echo "Enter value of B:"
	#read $2
	
	echo "value of A is: $1"
	echo "value of A is: $2"
	
	sum=$(($1 + $2))
	#echo "$sum"
	echo "Value of Sum is $sum "
	return "$sum"
}

add $1 $2
echo "Calling Return from MAIN SUM value is  :"$retval""
#ret=$?

#echo "return value is $ret"
