#!/bin/bash

#ifconfig | egrep '([0-9]{1,3}\.){3}[0-9]{1,3}'

#a='lo'

if [ $1 = 'enp0s3' ]; then
	ifconfig enp0s3
fi

if [ $1 = 'IP' ]; then
	ifconfig | egrep '([0-9]{0,3}\.){3}[0-9{1,3}]'	
#ifconfig -a|awk '{print $1 " " $2}'|egrep -w 'Link|inet'|sed 's/ Link//'|sed 's/inet addr://'
fi

if [ $1 = 'lo' ]; then 
	ifconfig lo
fi
