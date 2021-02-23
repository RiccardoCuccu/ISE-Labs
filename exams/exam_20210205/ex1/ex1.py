#!/usr/bin/env python3

# Import the simulator module (it should be in the same directory as this program)
import fakeSerial as serial

MAX_SAMPLES = 16

average = 0
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
	dato = sin.read(2)					# read 16 bits (2 bytes)
	if dato == '': break					# check if the data stream is over

	if i >= MAX_SAMPLES:
		i = 1						# reset data counter
	else:
		i += 1						# increment data counter
	
	L.pop(i-1)						# remove the oldest data
	L.insert(i-1, int(dato, 16))				# convert the received data into decimal and enter it in the list
	average = sum(L)					# sum all elements of the list
	average = average // MAX_SAMPLES			# update the moving average (only integer values)

	f.write(format(average, 'x') + "\n")			# write to file
	sout.write(format(average, 'x'))			# write to serial
	
sin.close()							# close serial 0
sout.close()							# close serial 1
f.close()							# close file
