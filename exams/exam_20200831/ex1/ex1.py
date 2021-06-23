#!/usr/bin/env python3

o = open("output.txt", "w")											# apertura del file "output.txt" in scrittura
d = {}														# dizionario per i valori delle variabili
flag = 0													# azzeramento della flag
temp = ""

for line in open("template.txt", "r"):										# estrazione delle righe
	for ch in line:												# estrazione dei caratteri
		if flag == 1:											# è presente una variabile da sostituire
			if ch == ' ' or ch == '\n':								# controllo se la variabile è terminata
				if temp in d:									# controllo se è già stato richiesto il valore della variabile all'utente
					o.write(str(d[temp]) + ch)						# se il valore della variabile è già stato memorizzato stampa sul file "output.txt"
				else:										# altrimenti è la prima volta che si incontra questa variabile
					d[temp] = input("Inserire il valore della variabile '" + temp + "': ")	# stampa a video la richiesta di immissione del valore della variabile
					o.write(str(d[temp]) + ch)						# stampa sul file "output.txt" il valore della variabile
				flag = 0									# azzeramento della flag
				temp = ""									# azzeramento del nome della variabile
			else:
				temp = temp + ch								# se la variabile non è terminata concatena il nuovo carattere
		elif ch == r'$':										# se "ch" contiene il carattere '$'
			flag = 1										# setting della flag ad uno poichè la parola successiva è una variabile
		else:
			o.write(ch)										# copia del carattere dal file "template.txt" al file "output.txt"
o.close()
