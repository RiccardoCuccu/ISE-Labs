import sys
import usb.core
import serial
import serial.tools.list_ports
import re
from random import randint
from time import sleep
from Tkinter import *
import ttk


###################################################
######### Graphical Interface Section #############
###################################################
def graphical_interface(*args):

    ###################################################
    ####### Section Associated to L 0 Button ##########
    ###################################################
    def calculate0():
        led_command = 'L 0'
        calculate(led_command, old_ledcom, response_time)

    ###################################################
    ####### Section Associated to L 1 Button ##########
    ###################################################
    def calculate1():
        led_command = 'L 1'
        calculate(led_command, old_ledcom, response_time)

    #################################################################
    ## Command Elaboration and Data Conversion (from ASCII to int) ##
    #################################################################
    def calculate(led_command, old_ledcom, response_time):
	if (led_command != old_ledcom.get()):
		old_ledcom.set(led_command)
		data = tx_rx(led_command)
		if(data == 'T2000'):
			dec_data = 2000
			warning.set('Timeout!\n')
		else:
			dec_data = int(data[1:5],16)
			warning.set('Ok!\n')
       	else:
		dec_data = ''	
		warning.set('You can not turn ON/OFF a LED\nthat was previously ON/OFF')
       	response_time.set(dec_data)

    root = Tk()
    root.title("Reflex Test")

    mainframe = ttk.Frame(root, padding = "3 3 3 3")
    mainframe.grid(column = 0, row = 0, sticky = (N, W, E, S))
    mainframe.columnconfigure(0, weight = 1)
    mainframe.rowconfigure(0, weight = 1)

    old_ledcom = StringVar()
    old_ledcom.set('L 0')
    response_time = StringVar()
    warning = StringVar()
    warning.set('\n')
    ttk.Label(mainframe, text="Your response time is equal to:").grid(column=1, row=1, columnspan=2, sticky=(W,E))
    ttk.Label(mainframe, textvariable=response_time).grid(column=1, row=2, sticky=(E))
    ttk.Label(mainframe, text="ms").grid(column=2, row=2, sticky=(W, E))
    ttk.Label(mainframe, justify = CENTER, textvariable=warning).grid(column=1, row=3, rowspan=2, columnspan=2, sticky=(N,S))

    ttk.Button(mainframe, text="L 1", command=calculate1).grid(column=1, row=5, sticky=(E))
    ttk.Button(mainframe, text="L 0", command=calculate0).grid(column=2, row=5, sticky=(W))

    for child in mainframe.winfo_children(): child.grid_configure(padx=5, pady=5)
    root.mainloop()

########################################
####### Tx and Rx Data Section #########
########################################
def tx_rx(led_command):
    sleep(randint(10,20))
    dev.write(led_command)
    data = dev.read(size=5)
    return data


###################################################################
#### Beginning of Script, Serial Connection and CLI section #######
###################################################################

print("########## Reflex Measurement System ##########\n"+
        "How to measure your reflex: type command 'L 1' if the green led\n" +
        "is off, in order to turn it on, otherwise type 'L 0' (the opposite\n" +
        "will happen). After a random amount of time, the led will turn\n" +
        "on/off and you'll have to press the blue button as fast as possible.\n" +
        "The system will measure the time between the led turns on/off and the\n" +
        "button is pressed.\nTo exit the program, type 'exit'\n\n" +
        "Notice: no other instruction will be accepted.")

dev_list = [tuple(device) for device in list(serial.tools.list_ports.comports())]

device_found = 0

for entry in dev_list:

    m = re.search('TTL232R-3V3',entry[1])
    if m:

        device_found = 1
        stm32_port = entry[0]

        dev = serial.Serial(port=stm32_port, baudrate='115200', parity='N', stopbits=1)
        print("\nConnection established with STM32 device at port: %s\n" % stm32_port)
	
	gui_switch = raw_input("Do you want a graphical interface? [Y/n] ")
	while (gui_switch != 'Y') and (gui_switch != 'n'):
		gui_switch = raw_input("Error: invalid command\nDo you want a graphical interface? [Y/n] ")

	if (gui_switch == 'Y'):
		graphical_interface()
	else:
		prev_command = 'L 0'
		while True:
		    command = raw_input("Insert command, 'L 0' or 'L 1': ")
		    if (command == 'exit'):
		        break
		    elif (command == prev_command):
		        print("You cannot turn on/off a led that's already on/off!")
		    elif (command == 'L 1') or (command == 'L 0'):
		        data = tx_rx(command)
		        if data == 'T2000':
		            print ("Timeout: more than 2s have passed")
		        else:
		            print ("Flying time: %d ms" % int(data[1:5],16))
		    else:
		        print("Wrong format, insert 'L 0' or 'L 1'!")
		    prev_command = command
        dev.close()

if device_found == 0:
    print("Error: device not found!")
