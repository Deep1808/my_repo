#!/bin/bash
cd ~/home/deep/my_repo/home_work




prompt="Please select a file:"
options=( $(ls) )

PS3="$prompt "
select opt in "${options[@]}" "Quit" ; do
	if (( REPLY == 1 + ${#options[@]} )) ; 
	then
		exit
	elif (( REPLY > 0 && REPLY <= ${#options[@]} )) ; 
	then
	echo "You picked $opt which is file $REPLY"
	echo $opt

	option2=($(ls $opt))
	select op2 in "${option2[@]}" "Quit" ; 
	do
		echo "You picked $op2 which is file $REPLY"
	echo $op2
	(cd $opt/$op2)
	pwd
	make all
 	valgrind --leak-check=full ./output
	done	
	break
	else
	echo "Invalid option. Try another one."
	fi

echo $op2 in "${options[@]}"
done
