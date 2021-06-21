#!/usr/bin/env python3

# Import the simulator module (it should be in the same directory as this program)
import fakeSerial as serial

INTBIT = 16							# number of bits to represent an unsigned integer
HEXDIGIT = int(INTBIT/4)					# number of hexadecimal characters to represent the same unsigned integers
MAX_SAMPLES = 16

i = 0								# data counter
L = [0]*MAX_SAMPLES						# list of converted hexadecimal characters

sin = serial.Serial(port = '/dev/ttyS0', baudrate = 9600)	# open serial /dev/ttyS0 (simulated)
sout = serial.Serial(port = '/dev/ttyS1', baudrate = 9600)	# open serial /dev/ttyS1 (simulated)

try:
	f = open("data.txt", "w")				# open file for writing
except:
	print("ERROR: failed to open output file!")
	exit(-1)

while True:
	data = sin.read(HEXDIGIT)				# read 32 bits (4 bytes)
	if data == '': break					# check if the data stream is over
	n = int(data, 16)					# convert the received data into decimal
	
	L = L[:i] + [n] + L[i+1:]
	average = sum(L)					# sum all elements of the list
	average = average // MAX_SAMPLES			# update the moving average (only integer values)

	if i >= MAX_SAMPLES-1: i = 0				# reset data counter
	else: i += 1						# increment data counter

	f.write(format(average, 'x') + "\n")			# write to file
	sout.write(format(average, 'x'))			# write to serial
	
sin.close()							# close serial 0
sout.close()							# close serial 1
f.close()							# close file
