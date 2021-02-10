#!/usr/bin/env python3

# Import the simulator module (it should be in the same directory as this program)
import fakeSerial as serial

average = 0
i = 0								# data counter
L = []								# list of converted hexadecimal characters

sin = serial.Serial(0)						# open serial 0 (simulated)
sout = serial.Serial(1)						# open serial 1 (simulated)

try:
	f = open("data.txt", "w")				# open file for writing
except:
	print("ERROR: failed to open output file!")
	exit(-1)

while True:
	dato = sin.read(2)					# read 16 bits
	if dato == '': break					# check if the data stream is over

	if i >= 16:
		i = 1						# reset data counter
		L = []						# reset datas
	else:
		i += 1						# increment data counter
	
	L.append(int(dato, 16))					# concatenate the data received in decimal
	average = sum(L)					# sum all elements of the list
	average = average // i					# update the moving average (only integer values)

	f.write(format(average, 'x') + "\n")			# write to file
	sout.write(format(average, 'x'))			# write to serial
	
sin.close()							# close serial 0
sout.close()							# close serial 1
f.close()							# close file
