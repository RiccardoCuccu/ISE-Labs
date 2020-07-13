#!/usr/bin/env python3

import string

d={}
counter=0

for line in open("divinaCommedia.txt"):				# for each line of the file
	words=line.split()					# save the line in "words" as a list of words
	for word in words:					# for each word in the list
		counter=counter+1				# increase the word counter
		for char in word:				# for each character of the word
			d[char] = d.get(char,0)+1		# save occurrences individually

f=open("report.txt", "w")					# opens the report.txt file
f.write("Carattere\tOccorrenze\n")				# print the start line

for letter in list(string.ascii_uppercase):			# for each uppercase letter
	ASCII_code=((ord(letter)+32))				# save the ASCII code of the respective lowercase letter
	d[letter] = d.get(letter,0)				# if an uppercase letter was not found in the text, set its value to zero
	d[chr(ASCII_code)] = d.get(chr(ASCII_code),0)		# if a lowercase letter was not found in the text, set its value to zero
	somma=((d[letter]+d[chr(ASCII_code)]))			# sum the occurrences of uppercase and lowercase letters
	f.write(chr(ASCII_code)+"\t\t"+str(somma)+"\n")		# print each letter and its occurrences

f.write("Totale parole: "+str(counter))				# print the number of words
f.close()							# closes the report.txt file
