#!/bin/bash

echo 'Number of parameters =' $#

i=0
echo "Positional parameters:"
for var in $0 $@
do
  echo '$'$i '=' $var
  let i++
done

case $1 in

	1)
	if [ $# -ne 2 ]
	then
		echo "Error: wrong parameters number! Correct format: ./es01.sh 1 fileName"
		exit 1
	else
		find /home/ms20.49/ -name $2
	fi ;;

	2) 
	if [ $# -ne 3 ]
	then
		echo "Error: wrong parameters number! Correct format: ./es01.sh 1 fileName /path"
		exit 2
	else
		if [ ! -d $3 ]
		then
			mkdir $3
			echo "Created folder $3"
		fi
    
		if [ ! -e $3/$2 ]
		then
			touch $3/$2
		else
			echo "Error: the file $2 already exist inside the directory $3"
			exit 3
		fi
	fi ;;

	3)
	if [ $# -ne 4 ]
	then
		echo "Error: wrong parameters number! Correct format: ./es01.sh 1 fileName /sourcepath /destinationpath"
		exit 4
	else
		if [ ! -d $3 ]
		then
			echo "Error: source directory not found!"
			exit 5
		elif [ ! -e $3/$2 ]
		then
			echo "Error: source file not found!"
			exit 6
		elif [ ! -d $4 ]
		then
			read -p "Warning: destination directory not found! Do you want to create it? Y/n: " answer
			if [ $answer == "Y" ]
			then
				mkdir $4
			elif [ $answer == "n" ]
			then
				echo "Aborted operation."
				exit -1
			else
				echo "Error: invalid command! Aborted operation."
				exit 7
			fi
		fi
		mv $3/$2 $4
	fi ;;

	*) echo "Error: command not found!" ;;
esac
