#!/usr/bin/env python3

# Import the simulator module (it should be in the same directory as this program)
import fakeSerial as serial

INTBIT = 12							# number of bits to represent an unsigned integer
HEXDIGIT = int(INTBIT/4)					# number of hexadecimal characters to represent the same unsigned integers
BYTETOREAD = HEXDIGIT*2+1					# total number of bytes to read from the serial for each operation

sin = serial.Serial(port = '/dev/ttyS0', baudrate = 9600)	# open serial /dev/ttyS0 (simulated)
sout = serial.Serial(port = '/dev/ttyS1', baudrate = 9600)	# open serial /dev/ttyS1 (simulated)

try:
	f = open("data.txt", "w")				# open file for writing
except:
	print("ERROR: failed to open output file!")
	exit(-1)

while(1):
	dato = sin.read(BYTETOREAD)				# read 56 bits (7 bytes)
	if dato == '': break					# check if the data stream is over

	n1 = int(dato[0:3], 16)					# convert the first hex to decimal
	n2 = int(dato[3:6], 16)					# convert the second hex to decimal
	op = dato[6]						# extract the bitwise operation

	if (op == '+'):						# OR operation
		result = n1 | n2
	elif (op == 'x'):					# AND operation
		result = n1 & n2
	elif (op == '#'):					# XOR operation
		result = n1 ^ n2

	f.write('%d %c %d %d\n' % (n1, op, n2, result))		# write to file
	sout.write('%03x' % result)				# write to serial

sin.close()							# close serial /dev/ttyS0
sout.close()							# close serial /dev/ttyS1
f.close()							# close file
