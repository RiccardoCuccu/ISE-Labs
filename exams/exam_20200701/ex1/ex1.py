#!/usr/bin/env python3

d={}
counter=0

for line in open("divinaCommedia.txt"):            #per ogni riga del file
    words=line        
    words=words.split()                                    # salva in words la riga come una lista di parole
    for word in words:                                        # per ogni parola della lista
        counter=counter+1                                # incrementa il contatore
        for char in word:                                        # per ogni carattere di ogni parola
            d[char] = get(char,0)+1                        # salva le occorrenze di tutti i caratteri (non solo lettere) dividendo

                                                                            # tra maiuscole e minuscole

f=open("report.txt", "w")
f.write("Carattere\tOccorrenze\n")

for letter in (a,b,c,d,e,f, ..... z):                            # sicuramente esiste una funzione per ciclare sulle lettere dell'alfabeto

                                                                            # (forse [a-z] o forse anche con range() ma non sono sicuro)

     ASCII_code= ((ord(letter)+27))                        # suppongo che l'offset tra i caratteri ascii sia 27 ma dovrebbe essere
                                                                                # un po' di più (basta prendere una tabella ascii)
    somma=((d[letter]+d[chr(ASCII_code)]))        # somma dei valori maiuscoli e minuscoli
    f.write(letter+"\t")                                            # stampa la lettera
    f.write(str(somma)+"\n")                                # stampa il valore corrispondente e torna a capo

f.write("Totale parole: "+str(count))                            # stampa l'ultima riga con il totale delle parole del file
f.close()
