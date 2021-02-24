#!/usr/bin/env python
import os
import subprocess
import math

# Clean folder
os.system("rm -f *.ps")
os.system("rm -f *.txt")

# Initialization
L_module = 0.05                        #nH
L_value = L_module * 10**(-9)          #nH
C_module = 0.02                        #pF
C_value = C_module * 10**(-12)         #pF
#LC_module = L_module * C_module
LC_value = L_value * C_value
LC_cell_delay = int(math.sqrt(LC_value) * 10**(12))	   #ps   
RS_value = 12.5                      		    	   #Ohm
Rl_value = {'50':'50', '12-5k':'12.5k', '100meg':'100meg'} #Ohm

l = open("log.txt","w+")

# Delay insertion (picoseconds)
while True:
	delay_in = input("Enter the netlist delay in picoseconds, only positive integer values are allowed: ")
	try:
		delay = int(delay_in)
		if delay < 0:
			print("Error: the delay requested is negative, please insert a positive integer value")
			continue
		break
	except ValueError:
    		print ("Error: the delay requested is not an integer value, please insert a positive integer value")
    
t_edge = delay/3                        #ps
t_rise = 0.2                            #ps
t_fall = 0                              #ps
t_width = 5                             #ns
print("Loading")

# Subcircuit generation
cells = 10
ground = 99
s = open("subcircuit.txt","w+")
s.write("*subcircuit definition\n.subckt lc_sub 1 %d %d\n\n*components\n" % (cells+1, ground))
for i in range(1, cells+1):
	s.write("*%.2fnH inductor between node %d and %d\n" % (L_module, i, i+1))
	s.write("L%d %d %d %.2fn\n" % (i, i, i+1, L_module))
	s.write("*%.2fpF capacitor between node %d and %d\n" % (C_module, i+1, ground))
	s.write("C%d %d %d %.2fp\n\n" % (i, i+1, ground, C_module))
s.write(".ends")
s.close()

# Circuit generation
subs = delay // (LC_cell_delay*cells)
spare = delay - subs * (LC_cell_delay*cells)

ground = 0

for res in Rl_value:
    c = open(("netlisttxline%s.txt" % res),"w+")
    c.write(".include ./subcircuit.txt\n\n")
    c.write("*square wave generator between node 1 and ground\n")
    c.write("V1 1 %d pulse(0 1 %.2fPS %.2fPS %.2fPS %dNS)\n\n" % (ground, t_edge, t_rise, t_fall, t_width))
    c.write("*%d Ohm resistor between nodes 1 and 2\n" % RS_value)
    c.write("R1 1 2 %.2f\n\n" % RS_value)

    for i in range(2, subs+2):
    	c.write("*subcircuit %d\n" % (i-1))
    	c.write("XSUB%d %d %d %d lc_sub\n" % (i-1, i, i+1, ground))

    c.write("\n")

    for i in range(spare):
    	c.write("*%.2fnH inductor between node %d and %d\n" % (L_module, i+subs+2, i+subs+3))
    	c.write("L%d %d %d %.2fn\n" % (i+1, i+subs+2, i+subs+3, L_module))
    	c.write("*%.2fpF capacitor between node %d and %d\n" % (C_module, i+subs+3, ground))
    	c.write("C%d %d %d %.2fp\n" % (i+1, i+subs+3, ground, C_module))

    c.write("\n")

    c.write("*%sOhm resistor between nodes %d and %d\n" % (res, spare+subs+2, ground))
    c.write("R2 %d %d %s\n\n" % (subs+spare+2, ground, Rl_value[res]))
    c.write("*Equivalent circuit model using transmission lines\n")
    c.write("V2 %d %d pulse(0 1 %.2fPS %.2fPS %.2fPS %dNS)\n\n" % (spare+subs+3,ground, t_edge, t_rise, t_fall, t_width))
    c.write("*%d Ohm resistor between nodes %d and %d\n" % (RS_value,spare+subs+3,spare+subs+4))
    c.write("R3 %d %d %.2f\n\n" % (spare+subs+3,spare+subs+4,RS_value))
    c.write("*Transmission line\n")
    c.write("T1 %d %d %d %d Z0=%.2f TD=%dp\n\n" % (spare+subs+4,ground,spare+subs+5,ground,math.sqrt(L_value/C_value),delay))
    c.write("*%sOhm resistor between nodes %d and %d\n" % (res,spare+subs+5, ground))
    c.write("R4 %d %d %s\n\n" % (spare+subs+5,ground,Rl_value[res]))
    c.write("*transient analysis between 0 and 5ns, with 0.1ps step\n")
    c.write(".tran 0.01p 5n\n")
    c.write(".control\n")
    c.write("run\n")
    c.write("set hcopydevtype=postscript\n")
    c.write("set hcopypscolor=1\n")
    c.write("set color0 =rgb:f/f/f\n")
    c.write("set color1 =rgb:0/0/0\n")
    c.write("set color2 =rgb:0/0/f\n")
    c.write("set color3 =rgb:f/0/0\n")
    c.write("set color4 =rgb:0/f/0\n")
    c.write("print v(%d) v(%d) v(%d) >res%s.txt\n" % (subs+spare+3,subs+spare+2, spare+subs+5, res))
    c.write("hardcopy res%s.ps v(1) v(%d) v(%d)\n" % (res, subs+spare+2, spare+subs+5))
    c.write(".endc\n")
    c.write(".end\n")
    c.close()

    # Ngspice analysis
    os.system("ngspice -b netlisttxline%s.txt" % res)

    # Results elaboration
    fd = open((("res%s.txt") % res),"r")
    
    l.write("load = %s\n" % res)
    
    l.write("Iteration".ljust(10)+"|Vref".ljust(20)+"|Vout".ljust(20)+"|Relative Error\n")

    ## Let's try to unpack the file into the various columns
    vlt_column = list()
    vlc_column = list()
    vsr_column = list()
    time_column = list()

    for lines in fd:
        if lines[0].isdigit():
            time_column.append(lines.split()[1])
            vsr_column.append(lines.split()[2])
            vlc_column.append(lines.split()[3])
            vlt_column.append(lines.split()[4])

    fd.close()

    # deltaTd evaluation
    FirstFound = False
    SecFound = False

    for vals in zip(time_column,vsr_column,vlc_column):
        if not(FirstFound and SecFound):
            if(vals[1][0:2] == '5.' and vals[1][10:12] == '01' and not FirstFound):
                t50v1=vals[0]
                FirstFound = True
            if(vals[2][0:2] == '4.' and vals[2][10:12] == '01' and not SecFound):
                t50vl=vals[0]
                SecFound = True
        else:
            break
            
    dTd = float(t50vl) - float(t50v1)
    deltaTd = float(t50vl) * 10**(12) - float(t50v1) * 10**(12)
    #print('deltaTd is equal to: %.2fps' % deltaTd)
    print('.')

    base_val = t_edge+0.1*2*deltaTd+deltaTd

    # Creation of voltage and time lists
    no_of_int = int(5000 // (2*deltaTd))
    list_of_int = list()
    vlc_list = list()
    vlt_list = list()
    no_of_elms = list()

    for i in range(no_of_int):
        vlc_list.append(0)
        vlt_list.append(0)
        no_of_elms.append(0)
        list_of_int.append((base_val+i*2*deltaTd)*10**(-12))

    lim_inf = list_of_int[0]
    lim_sup = list_of_int[1]
    i=0

    # Accumulate in lists elements the various voltages, then divide by number of elements to get mean value
    for elms in zip(time_column,vlc_column,vlt_column):
        if(float(elms[0]) > float(lim_sup) and i != 14):
            #print("Iteration %d: Vref = %f, Vout = %f" % (i,vlt_list[i]/no_of_elms[i],vlc_list[i]/no_of_elms[i]))
            iteration = str(i).ljust(10)
            v_ref = vlt_list[i]/no_of_elms[i]
            v_refs = (("|")+str(v_ref)).ljust(20)
            v_out = vlc_list[i]/no_of_elms[i]
            v_outs = (("|")+str(vlc_list[i]/no_of_elms[i])).ljust(20)+("|")
            err = (abs(v_ref - v_out)/v_ref)*100
            l.write("%s%s%serr = %.2f%%\n" % (iteration, v_refs, v_outs, err))
            
            i = i+1
            if i != 14:
                lim_inf = list_of_int[i]
                lim_sup = list_of_int[i+1]

        if(float(elms[0]) >= float(lim_inf) and float(elms[0]) <= float(lim_sup)):
            vlc_list[i] = vlc_list[i] + float(elms[1])
            vlt_list[i] = vlt_list[i] + float(elms[2])
            no_of_elms[i] = no_of_elms[i] + 1
           
    l.write("Evaluated td = " + str(dTd) + "\n\n")         
            
l.close()
print("End of processing: the results are contained in the log.txt file")