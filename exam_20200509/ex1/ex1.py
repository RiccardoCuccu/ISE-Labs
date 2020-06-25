# Import the simulator module (it should be in the same directory as this program)
import fakeSerial as serial

def Exame():
	ser = serial.Serial(0)			# open first serial port
	for n in range(100):
		x = ser.read_until('3')		# read until ETX = '3'
		print( "x =", x )
	
	ser.close()						# close port
	
Exame()