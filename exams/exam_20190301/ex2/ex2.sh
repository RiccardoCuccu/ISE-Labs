#!/bin/bash

touch ./dir2/hellofunc.c

rm output.log
touch output.log

find ./*/Makefile > paths.txt
while read -r line
do
  riga=$( echo $line | cut -d '/' -f -2 )
  cd $riga
  make &>> ../output.log
  if [ $? != 0 ]; then
    echo "exit 1"
    #exit 1
  fi
  if [ -x postmake.sh ]; then
    source postmake.sh &>> ../output.log
      if [ $? != 0 ]; then
        echo "exit 2"
        #exit 2
      fi
  fi 
  cd ..
  #echo "$line => $riga"
done < paths.txt

rm paths.txt