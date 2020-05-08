while 1:
	user = input('Inserire username: ')
	mese = input('Inserire mese: ')

	user=user.rstrip()
	mese=mese.rstrip()

	n=0
	if mese=="gennaio": n=1
	if mese=="febbraio": n=2
	if mese=="marzo": n=3
	if mese=="aprile": n=4
	if mese=="maggio": n=5
	if mese=="giugno": n=6
	if mese=="luglio": n=7
	if mese=="agosto": n=8
	if mese=="settembre": n=9
	if mese=="ottobre": n=10
	if mese=="novembre": n=11
	if mese=="dicembre": n=12
	#print(n)

	if (user or mese)=='QUIT': exit('exit')
	ore=0; minuti=0

	for line in (open('cpu_time.txt')):
		row=line.split(' ')
		#print(row)
		if row[0]==user:
			target=row[1].split('-')
			#print(target)
			if int(target[1])==n:
				time=row[2].split('.')
				#print(time)
				ore=ore+int(time[0])
				minuti=minuti+int(time[1])
	count=ore*60+minuti
	print('Numero di minuti: {0}\n'.format(count))