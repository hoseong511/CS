#!/bin/bash

if [[ -n $1 ]]
then

	ProcessName=($1)
	echo ${ProcessName}
	echo `ps -ef | grep -c ${ProcessName}`

	if [[ `ps -ef | grep -c ${ProcessName}` -gt 1 ]]
	then
		ProcessID=`ps -ef | grep ${ProcessName} | awk '{if (NR == 1) printf $2}'`
		echo "hi ${ProcessID}"
		while true
		do
			leaks ${ProcessID}
			sleep 1
		done
	fi
else
	echo -e "Please input Process Name!"
fi