#!/bin/bash
#function to add two numbers
add()
{
	read x
	read y
	echo -e "Number entered by u are: $x and $y"
	sum=$((x + y)) 
	echo "sum of $x and $y is $sum"
}

add 

