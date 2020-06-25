import os
import pty
import serial

master = pty.openpty()
slave = pty.openpty()

# Simulated serial port
ser = serial.Serial(os.ttyname(slave))

# To Write to the device
#ser.write('Your text')

# To read from the device
#os.read(master,1000)

print(ser.name)