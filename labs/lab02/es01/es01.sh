#!/bin/bash
shopt -s extglob											# to remove files selectively

rm report.txt
rm log.txt

mkdir scripts

find ./dbase -name "gr[0-9]*[ab]_lab01" -type d | sort | cut -d "/" -f 3 > folders.txt
n_lines=`wc -l ./hostRenamed.txt | cut -d " " -f 1`

while read line
do
	folder=`echo "./dbase/"$line"/es02/"`
	bash_file=`echo $folder"es02.sh"`
	host_file=`echo $folder"host.txt"`
	hostRenamed_file=`echo $folder"hostRenamed.txt"`
	group=`echo $line | cut -d "_" -f 1`

	## Correction files
	if [ -d $folder ]										# If the folder exists, delete all files except es02.sh and host.txt
	then
		cd $folder
		rm !("es02.sh"|"host.txt")
		cd ../../..

		if [ ! -e $host_file ]									# If the host.txt file does not exist, copy the original host.txt inside $folder
		then
			cp ./host.txt $folder/host.txt
			echo "host.txt file missing, copy successfully in $folder"
		elif ! cmp -s ./host.txt $folder/host.txt						# If the host.txt file has been manipulated, copy the original host.txt inside $folder
		then
			cp ./host.txt $folder/host.txt
			echo "host.txt file changed, replacement successful in $folder"
		fi

		if [ -e $bash_file -a ! -x $bash_file ]							# If the es02.sh file exist and is not executable, make it executable
		then
			chmod u+x $bash_file
		fi
	fi

	## Check files
	if [ ! -d $folder ]
	then
		error_message="KO Missing directory es02/"
	elif [ ! -e $bash_file ]
	then
		error_message="KO Missing file es02/es02.sh"
	else
		cp $bash_file ./scripts/$group.sh
		cd $folder
		./es02.sh
		cd ../../..

		if [ ! -e $hostRenamed_file ]
		then
			error_message="KO No es02/hostRenamed.txt was generated"
		else
			w_lines=`diff ./hostRenamed.txt $hostRenamed_file | grep "^>" | wc -l`		# wrong lines
			c_lines=`expr $n_lines - $w_lines`						# correct lines
			percentage=`expr $c_lines \* 10000 / $n_lines | sed 's/..$/.&/'`		# percentage with decimals
			
			if [ $w_lines -ne 0 ]
			then
				error_message="KO Unmatched output ($percentage% correct)"
			else
				error_message="OK"
			fi
		fi
	fi

	line=`echo $group $error_message`
	echo $line >> report.txt

done < folders.txt

## Check similarities
cd ./scripts
for script_1 in $( ls )
do
	for script_2 in $( ls )
	do
		if [ "$script_1" != "$script_2" ]
		then
			diff -c -i -b -B $script_1 $script_2 > ../diff.txt
			script_lines=`wc -l $script_1 | cut -d " " -f 1`
			if ! [ -s ../diff.txt ]								# If diff.txt is not empty
			then 
				echo "The script $script_1 is 100% equal to the script $script_2." >> ../log.txt
			else
				copied_lines=`sort ../diff.txt | uniq | grep '^ ' | wc -l`
				percentage_copy=`expr $copied_lines \* 100 / $script_lines`
				echo "The script $script_1 is $percentage_copy% equal to the script $script_2." >> ../log.txt
			fi
		fi
	done
	rm "$script_1"
done
cd ..

rm folders.txt
rm diff.txt
rm -r scripts