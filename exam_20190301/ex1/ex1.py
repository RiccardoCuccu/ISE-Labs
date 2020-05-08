# coding=utf-8

f=open('log.txt','w')		# apertura del file log.txt in scrittura
r=open('results.txt')		# apertura del file results.txt in lettura

n_block=0
for line in open('results.txt'):
	if '-----' in line:
		if n_block != 0:
			#f.write('Block %d:\t Num of Columns: %d.\t The sum of "%s" is: %.1f.\t The average is: %.1f.\n' % (n_block, elementi, etichetta[0:-1], somma, media))	# il range [0:-1] esclude il carattere "\n"
			f.write('Block {0}:\t Num of Columns: {1}.\t The sum of \"{2}\" is: {3}.\t The average is: {4}.\n'.format(n_block, elementi, etichetta[0:-1], somma, media))
		n_block=n_block+1		# nuovo blocco
		somma=0					# azzeramento somma
		media=0					# azzeramento media
		elementi=0				# azzeramento elementi
		etichetta='empty'	
	else:
		text=line.split('\t')
		if (text[-1].rstrip().isalpha()):		# se l'ultimo elemento non è un numero
			etichetta=text[-1]					# salva l'etichetta dell'ultima colonna 
			#lunghezza=len(text)				# numero di colonne del blocco
		else:
			somma=somma+float(text[-1])			# somma degli elementi dell'ultima colonna
			elementi=elementi+1					# conteggio degli elementi dell'ultima colonna
			media=somma/elementi				# media degli elementi dell'ultima colonna

#f.write('Block %d:\t Num of Columns: %d.\t The sum of "%s" is: %.1f.\t The average is: %.1f.\n' % (n_block, elementi, etichetta[0:-1], somma, media))
f.write("Block {0}:\t Num of Columns: {1}.\t The sum of \"{2}\" is: {3}.\t The average is: {4}.\n".format(n_block, elementi, etichetta[0:-1], somma, media))
f.close()