#!/bin/bash

if [ $# -ne 1 ]; then
	echo "Inserire uno e un solo parametro"
	echo "exit 1"
	#exit 1
elif !(($1)); then
	echo "Il valore inserito dev'essere un numero"
	echo "exit 2"
	#exit 2
else
  echo "Il valore inserito e' un numero"
  
  touch main.c
  echo '#include <stdio.h>' > main.c
  echo '#include <math.h>' >> main.c
  echo ' ' >> main.c
  echo 'int main(int argc, char *argv[]) {' >> main.c
  echo "	int number=pow($1,2);" >> main.c
  echo '	printf("%d", number);' >> main.c
  echo '	return number;' >> main.c
  echo '}' >> main.c

  gcc -o main main.c
  result=`./main`
  temp=$(( $1**2 ))
  echo "$temp =? $result"
  if [ result==temp ]; then
  	echo "Il risultato e' corretto!"
  else
  	echo "Il risultato e' sbagliato!"
  fi
fi