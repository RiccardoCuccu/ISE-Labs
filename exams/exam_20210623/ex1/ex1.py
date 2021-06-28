#!/usr/bin/env python3

SAMPLES = 16

try:
	fin = open('input.txt', 'r')				# open file for reading
except:
	print("ERROR: failed to open input file!")
	exit(-1)

try:
	fout = open('output.txt','w')				# open file for writing
except:
	print("ERROR: failed to open output file!")
	exit(-1)

content = fin.read()						# extract the content of the input file
numbers = content.split(' ')					# conversion from string to list

i = 0								# counter
average = 0							# average
values = []							# list of samples

for number in numbers:						# for each number contained in the input file
	if i == SAMPLES:
		average = sum(values)				# sum the samples
		average = int(average/SAMPLES)			# average calculation
		fout.write(str(format(average, '04x') + ' '))	# writing the 4-digit hexadecimal value (16 bit) to the output file
		values = []					# reset of samples
		values.append(int(number, 10)) 			# conversion from character to integer
		i = 1						# reset samples counter
	else:
		values.append(int(number, 10))			# conversion from character to integer
		i = i+1						# increment samples counter

fin.close()							# close input file
fout.close()							# close output file
