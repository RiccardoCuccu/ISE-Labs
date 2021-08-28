#!/usr/bin/env python3

DIGITS = 4
SAMPLES = 16

L = [0]*DIGITS									# list of digits
N = [0]*SAMPLES									# list of samples
i = 0										# digits counter
j = 0										# samples counter
n = ""										# string number

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

while True:
	ch = fin.read(1)							# read one character at a time				

	if ch == ' ' or ch == '':						# if the character is a space or EOF the number is finished
		for digit in L:							# concatenate digits
			if digit == 0: break
			n = n + digit

		N[j] = int(n)							# conversion from string to integer
		j += 1								# increment samples counter
		i = 0								# reset digit counter
		n = ""								# reset number
		L = [0]*DIGITS							# delete digits
	else:
		L[i] = ch							# save digit
		i += 1								# increment digit counter

	if j == SAMPLES:
		average = int(sum(N) / SAMPLES)					# average calculation
		fout.write(str(format(average, '0'+str(DIGITS)+'x')) + ' ')	# write 4-digit hexadecimal value (16 bit) to the output file
		j = 0								# reset samples counter

	if ch == '': break							# EOF

fin.close()									# close input file
fout.close()									# close output file
