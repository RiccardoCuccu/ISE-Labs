#!/usr/bin/env python3

o=open("output.txt", "w")										# apertura del file "output.txt" in scrittura
d={}													# dizionario per i valori delle variabili
flag=0													# azzeramento della flag

for line in open("template.txt", "r"):									# estrazione delle righe
	for ch in line:											# estrazione dei caratteri
		if flag==1:										# "ch" è una variabile da sostituire
			if ch in d:									# controllo se è già stato richiesto il valore della variabile all'utente
				o.write(str(d[ch]))							# se il valore della variabile è già stato memorizzato stampa sul file "output.txt"
			else:										# altrimenti è la prima volta che si incontra questa variabile
				d[ch]=input("Inserire il valore della variabile '" + ch + "': ")	# stampa a video la richiesta di immissione del valore della variabile
				o.write(str(d[ch]))							# stampa sul file "output.txt" il valore della variabile
			flag=0										# azzeramento della flag
			continue
		elif ch==r'$':										# se "ch" contiene il carattere '$'
			flag=1										# setting della flag ad uno poichè il carattere successivo è una variabile
			continue
		else:
			o.write(ch)									# copia del carattere dal file "template.txt" al file "output.txt"
o.close()
