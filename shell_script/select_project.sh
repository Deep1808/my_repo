#!/bin/bash

PS3="What type of phone do you have ? "
select $phone in handheld headset;
do
	echo "You have selected $phone ,as per your choice"
	break
done

PS3="Which field you are working in Finance,Sales or Engineering? "
select $field in finance sales engineering;
do
	echo "You are currently working in $field"
	break
done

echo $phone,$field >> extension1.cvc 
