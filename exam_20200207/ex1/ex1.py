import os
import datetime

os.system("rm -f *.log")

files = os.listdir('.')						# get the list of files in the current directory
files.remove('ex1.py')						# remove this file from the list
files.sort()							# sort the list

first = datetime.timedelta(hours=8)				# end of the first band
second = datetime.timedelta(hours=16)				# end of the second band

for file in files:
	#print("Analizing the file", file, "...")
	number = file[:-7]
	month = file[11:-4]
	fascia1 = fascia2 = fascia3 = datetime.timedelta(hours=0)
	for line in open(file, "r"):

		values = line.split()				# split every line
		t_start = values[2].split('.')			# divide the minutes from the hours of the start of the call
		t_end = values[3].split('.')			# divide the minutes from the hours of the end of the call

		start = datetime.timedelta(hours=int(t_start[0]), minutes=int(t_start[1]))
		end = datetime.timedelta(hours=int(t_end[0]), minutes=int(t_end[1]))

		if start <= first:				# if the call starts before 7.59 ...
			if end <= first:			# ... and ends before 7.59
				fascia1 += end - start
			elif end <= second:			# ... and ends before 15.59
				fascia1 += first - start
				fascia2 += end - first
			else:					# ... and ends before 23.59
				fascia1 += first - start
				fascia2 += second - first
				fascia3 += end - second
		elif start <= second:				# if the call starts before 15.59 ...
			if end <= second:			# ... and ends before 15.59
				fascia2 += end - start
			else:					# ... and ends before 23.59
				fascia2 += second - start
				fascia3 += end - second
		else:						# if the call starts before 23.59 ...
			fascia3 += end - start

	f=open(number+".log", "a")				# open the log file
	f.write("Mese: "+month+"\n")
	f.write("Minuti effettuati in fascia 1 [00.00 – 07.59]: "+str(int(fascia1.seconds/60))+"\n")
	f.write("Minuti effettuati in fascia 2 [08.00 – 15.59]: "+str(int(fascia2.seconds/60))+"\n")
	f.write("Minuti effettuati in fascia 3 [16.00 – 23.59]: "+str(int(fascia3.seconds/60))+"\n")
	f.close()

