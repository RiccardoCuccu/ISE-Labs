# Import the simulator module (it should be in the same directory as this program)
import fakeSerial as serial

def Exame():
	ser = serial.Serial(0)						# open first serial port
	elements = {}

	for n in range(100):
		x = ser.read_until('3')					# read until ETX = '3'
		length = len(x[1:-1])
		elements[length] = elements.get(length, 0)+1		# return 0+1 if the key is not found

	ser.close()							# close port

	f = open("log.txt", "w")
	for n in elements:
		f.write(str(n) + "\t" + str(elements[n]) + "\n")
	f.close()
	
Exame()
