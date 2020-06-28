class Impiegati:

	def __init__(self, n, s, j):
		self.name = n
		self.surname = s
		self.job = j
		self.projects = []

	def add_project(self, p):
		self.projects.append(p)

d = {}									# dictionary of employees
	
for line in open("employees.txt", "r"):					# read the file "employees.txt"
	elements = line.split()						# split the line in a list of elements
	name = elements.pop(0)						# extract name
	surname = elements.pop(0)					# extract surname
	namesurname = name+surname					# concatenate name and surname to use it as a variable
	if namesurname in d:						# eployee already in the dictionary
		project = elements.pop(1)				# extract project
		d[namesurname].add_project(project)			# add the project
	else:								# eployee not in the dictionary
		job = ' '.join(elements)				# extract job
		d[namesurname] = Impiegati(name, surname, job)		# instance object

for employees in d:							# for each employee print one line
	print(d[employees].name, end=' ')				# print name
	print(d[employees].surname, end=', ')				# print surname
	print(d[employees].job, end=' -- ')				# print job
	print("Lista progetti:", end=' ')
	last=len(d[employees].projects)					# number of projects
	for n in d[employees].projects:					# for loop to exclude the comma from the last element
		if last == 1:
			print(n, end=' ')				# print last project
		else:
			print(n, end=', ')				# print project
			last = last - 1
	print('')
