# Appello del 01.03.2019

## Esercizio 1
Si vuole realizzare su una macchina Linux uno script in Python 3 che permetta leggere e manipolare un file di testo.
Il file di testo in esame, denominato *results.txt* e presente all'interno della cartella corrente, è suddiviso in un numero indefinito di blocchi separati tra loro da una riga contenente i caratteri: "-----------------------------".<br/>
Ciascun blocco è caratterizzato da un numero indefinito di colonne separate tramite il separatore TAB. La prima riga di ciascun blocco contiene le etichette di ciascuna colonna, anch'esse separate tramite il separatore TAB.<br/>
Le righe successive contengono dati numerici espressi in **floating point**.<br/>
Di seguito è riportato un file di esempio:
```
-----------------------------
a	b	c	d
11	3	564	77
3	344	66	8	
99	877	7	44
-----------------------------
a	b	out
11	3	77
3	344	8
99	877	33
44	66	15
-----------------------------
a	b	c	d	f	output
1	2.1	3	4	5	6.0
7	8	9.7	10	11	12.14
13	14	15	16.5	17	18.1
19	20	21	22	23	24.7
```
Si vuole calcolare per ciascun blocco:
- Il numero del blocco (`int`)
- Il numero di colonne (`int`)
- La sommatoria dei valori numerici riportati all'interno dell'ultima colonna riportando l'etichetta (`float`)
- Il valor medio dei dati numerici riportati all'interno dell'ultima colonna (`float`)

I dati sopra elencati devono essere riportati all'interno di un log file, denominato *log.txt*, come riportato in esempio:
```
Block 1:	Num of Columns: 4.	The sum of “d” is: 129.0.	The average is: 43.0
Block 2:	Num of Columns: 3.	The sum of “out is: 133.0.	The average is: 33.25
Block 3:	Num of Columns: 6.	The sum of “output” is: 60.94.	The average is: 15.235
```

## Esercizio 2
Si vuole realizzare su una macchina Linux uno script eseguibile dall'interprete bash, al fine di automatizzare l'operazione di preparazione di un programma da distribuire.<br/>
Lo script e' collocato in una directory, al cui interno sono presenti sottodirectory e file.<br/>
Per ogni sottocartella, lo script deve verificare se all'interno della stessa sia presente un file con nome *Makefile*, e, in caso affermativo, deve invocare il comando `make`.<br/>
Deve quindi verificare se nella stessa sottocartella sia presente anche un file eseguibile con nome *postmake.sh*, e, nel caso in cui esso sia presente ed eseguibile, lo deve lanciare.<br/>
L'output dell'esecuzione di tutti i comandi (sia `make` che `postmake.sh`) deve essere salvato in un file denominato *output.log*, contenente sia l'output dei comandi che eventuali segnalazioni di errore.<br/>
Infine, lo script deve abortire l'esecuzione nel caso in cui uno dei comandi lanciati abbia generato un errore.
