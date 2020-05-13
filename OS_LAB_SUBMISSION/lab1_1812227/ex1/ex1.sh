#!/bin/bash
fileName="ex1.txt"
null="Null input"
if [ -z "$1" ]
then 
	printf "$null" > "$fileName"
else
	printf "%s " "$1" > "$fileName"
	if [ "$#" -gt 1 ]
	then
		i=2
		while [ "$i" -le "$#" ]
		do
			printf "%s " "${!i}" >> "$fileName" 
			i=$((i+1))
		done
	fi
fi
printf "\n" >> "$fileName"
uname -a >> "$fileName"
