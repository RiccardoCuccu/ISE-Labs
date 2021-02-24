#!/bin/bash

rm hostRenamed.txt							# delete a possible old file
touch hostRenamed.txt							# create a new file

m=0
n=30

while read line
do
	let m++
	let n++

	line=`echo $line | cut -d " " -f 2-3`				# remove the first and the last column
	segment=`echo $line | cut -d "." -f 5-`				# extracts useful data
	line=`echo "192.168.1."$n "host"$m"."$segment "host"$m`		# assemble the new line

	echo $line >> hostRenamed.txt					# appends the line to the file hostRenamed.txt
done < host.txt
