#!/usr/bin/env python3

try:
	fin = open('input.txt', 'r')				# open file for reading
except:
	print("ERROR: failed to open input file!")
	exit(-1)

D = {}								# dictionary for storing keys and values
key = ''							# variable for temporary storage of the key
value = ''							# variable for temporary storage of the value
exist = 0							# flag to indicate if a value already exists
switch = 0							# flag to switch between key and value

while(1):
	ch = fin.read(1)					# read one byte (one character) and save it in 'ch'
	if ch == '': break					# if 'ch' is empty the file is finished
	elif (ch in ["{","}"," ","\n"]): continue		# characters allowed but not relevant
	elif ch == ":":                     			# if 'ch' is ':' the key is finished
		switch = 1	
	elif ch == ";":						# if 'ch' is ';' the value is finished
		if key in D:					# if the key is already present in the dictionary
			for v in D[key]:			# for each key value
				if value == v:			# check if 'value' already exists
					exist = 1		# set flag
					break
		if exist == 0:					# if the value is not associated with the key
			D[key] = D.get(key, []) + [value]	# concatenate the new value to the old key values
		key = ''					# reset variable
		value = ''					# reset variable
		switch = 0					# reset flag
		exist = 0					# reset flag
	elif (ch.isalnum):					# if 'ch' is an alphanumeric character
		if switch == 0:					# if 'ch' is a key character
			key = key+ch				# concatenate key
		elif switch == 1:				# if 'ch' is a value character
			value = value+ch			# concatenate value
	else:
		print("ERROR: character not allowed!")
		exit(-1)

fin.close()							# close input file

try:
	fout = open('output.txt', 'w')				# open file for writing
except:
	print("ERROR: failed to open input file!")
	exit(-1)

for k in sorted(D):						# for each dictionary key
	first = 1						# flag for the first printed value
	fout.write(k+": ")					# print the key
	for v in sorted(D[k]):					# for each key value
		if first == 1:					# if it is the first value
			fout.write(v)				# print the value
			first = 0				# reset flag
		else:						# if it isn't the first value
			fout.write(", "+v)			# print the value
	fout.write(";\n")					# print the end of the line

fout.close()							# close output file
