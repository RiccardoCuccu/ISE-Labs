#!/usr/bin/env python
import os
import subprocess

# Clean folder. Deleting working directories and outputs
os.system("rm -rf work")
os.system("rm -f log.txt")
os.system("rm -f transcript")
os.system("rm -f vsim.wlf")

# Setting up environement variables
os.environ["PATH"] += os.pathsep + "/software/mentor/modelsim_6.5c/modeltech/linux_x86_64/"
os.environ["LM_LICENSE_FILE"] = "1717@led-x3850-1.polito.it"

# Print out environement variables
os.system("echo $PATH")
os.system("echo $LM_LICENSE_FILE")

par = 2

for i in range(3):
	# Input_Vectors text file creation
	print("#################### Architecture's parallelism: %d bit ####################" % par)
	print("Input Vectors file generation")
	in1 = 0
	in2 = 0
	f = open("input_vectors.txt","w+")
	com = open(("compare_vectors_%sbit.txt" % str(par)),"w+")

	lines = open("constants.vhd", "r").readlines()
	lines[1] = '		constant N : natural := %d;\n' % par
	comp = open("constants.vhd", "w")
	comp.writelines(lines)
	comp.close()

	form_in = '0:0%s' % str(par)
	form_in += 'b'
	form_res = '0:0%s' % str(par+1)
	form_res += 'b'

	for i in range(2**par):
		for j in range(2**par):
			f.write("%s %s\n" % (('{%s}' % form_in).format(in1),('{%s}' % form_in).format(in2)))
			com.write("%s\n" % (('{%s}' % form_res).format(in1+in2)))
			in2 += 1
		in2 = 0
		in1 += 1

	f.close()
	com.close()

	# Launch Modelsim simulation
	print ("Starting simulation...")
	process = subprocess.call(["vsim", "-c", "-do", "compile.do"])
	print ("Simulation completed")

	# Circuit's output and golden output comparison
	print("Start of comparison")
	out = open("output_results.txt","r")
	com = open(("compare_vectors_%sbit.txt" % str(par)),"r")
	f = open("input_vectors.txt","r")
	log = open("log.txt","a+")
 
	log.write("### Informations regarding %s bit RCA ###\n" % str(par))

	diff=0

	for (l1,l2,l3) in zip(out,com,f):
		if int(l1, 2) - int(l2, 2) != 0:
			log.write("Error in operation %s + %s. Correct sum: %s. Actual sum: %s\n" % (l3[:par],l3[(par+1):(2*par+1)],l2[:-1],l1[:-1]))
			diff=1

	if diff == 0:
		log.write("The circuit behaves as expected\n\n")	

	out.close()
	com.close()
	log.close()
	f.close()
	#os.system("mv input_vectors.txt input_vectors_%sbit.txt" % str(par))
	os.system("rm -f input_vectors.txt")
	#os.system("mv output_results.txt output_results_%sbit.txt" % str(par))
	os.system("rm -f output_results.txt")
	os.system("rm -f compare_vectors_%sbit.txt" % str(par))
	print("End of comparison, info can be found on file log.txt")
	print("Thank you")
	par *= 2

