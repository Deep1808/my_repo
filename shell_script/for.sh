#/bin/bash

for var1 in 0 1 2
do
	for var2 in 1 3 4
	do 
		if ($var -eq  $var2)
		echo -e $var1
		echo -e $var2
		fi
	done
done
