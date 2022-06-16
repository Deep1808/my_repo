#!/bin/sh

a=0
while [ "$a" -lt 10 ]    
do
   b="$a"
   while [ "$b" -ge 0 ]  
   do
      echo -n "$b "
      b=$((b - 1))
   done
   echo
   a=$(($a + 1))
done

