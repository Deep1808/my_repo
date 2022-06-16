#/bin/bash

for n in {1..10}
do
	q=$((n % 2))
	if [ $q -eq 0 ]
	then
		echo "$n ----- Number is EVEN !!"

		continue
	else
		echo "$n ------- Number is ODD !!"
	fi
done	
