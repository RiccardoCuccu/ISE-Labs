import os

os.system ("bash -c 'rm -rf -d simulation_*'")	# remove old folders

#t_zero=input('Inserire t_zero: ')
#t_end=input('Inserire t_end: ')
#s_min=input('Inserire s_min: ')
#s_max=input('Inserire s_max: ')
#gran=input('Inserire gran: ')

t_zero=0
t_end=10
s_min=1
s_max=5
gran=1

for i in range(s_min, s_max+1, gran):	# create new directories or print an error
	try:
		os.mkdir("./simulation_%d" % i)
	except:
		exit("Errore nella creazione della cartella simulation_%d\n" % i)

for i in range(s_min, s_max+1, gran):	# copy and modify the simulationScript.run file
	os.chdir("./simulation_%d" % i)
	file=open("../simulationScript.run","r")	# read original file
	new_file=open("./simulationScript.run", "w+")	# create new file inside the folder
	for j in range(len(open("../simulationScript.run").readlines())):	# loops for the numbers of lines in original file
		text=file.readline()			# copy the line
		if "simulationStep" in text:		# target line
			text="simulationStep:"		# overwrite the variable with a new line
			for k in range(t_zero,t_end,i):		# loops to add to the variable the instants time
				text=text + " " + str(k)	# build the new line
			text=text + "\n"
			new_file.write(text)			# put the rewritten line in the new file
		else:
			new_file.write(text)			# put the original line in the new file
	file.close()					# close the original file
	new_file.close()				# close the new file
	os.chdir("..")					# return to the father directory
