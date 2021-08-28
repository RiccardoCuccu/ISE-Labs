#!/usr/bin/env python3

DIGIT = 4
SAMPLES = 16

try:
	fin = open('input.txt', 'r')						# open file for reading
except:
	print("ERROR: failed to open input file!")
	exit(-1)

try:
	fout = open('output.txt','w')						# open file for writing
except:
	print("ERROR: failed to open output file!")
	exit(-1)

L = [0]*DIGIT									# list of digits
N = [0]*SAMPLES									# list of samples
i = 0										# digits counter
j = 0										# samples counter
n = ""										# string number

while True:
	ch = fin.read(1)							# reads one character at a time				

	if ch == '': break							# EOF
	elif ch == ' ':								# if the character is a space the number is finished
		for digit in L:							# concatenate digits
			if digit == 0: break
			n = n + digit

		N[j] = int(n)							# conversion from string to integer
		j += 1								# increment samples counter
		i = 0								# reset digit counter
		n = ""								# reset number
		L = [0]*DIGIT							# delete digits
	else:
		L[i] = ch							# save digit
		i += 1								# increment digit counter

	if j == SAMPLES:
		average = int(sum(N) / SAMPLES)					# average calculation
		fout.write(str(format(average, '0'+str(DIGIT)+'x')) + ' ')	# writing the 4-digit hexadecimal value (16 bit) to the output file
		j = 0								# reset samples counter

fin.close()									# close input file
fout.close()									# close output file
