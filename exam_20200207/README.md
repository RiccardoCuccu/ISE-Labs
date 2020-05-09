# Appello del 07.02.2020

## Esercizio 1
Si vuole realizzare su una macchina Linux uno script in Python 3 che permetta elaborare alcune informazioni relative ai tabulati telefonici di alcuni clienti.<br/>
Lo script deve scansionare tutti i files presenti all'interno della cartella in cui si trova. In particolare, si suppone che all'interno della cartella siano presenti unicamente dei file denominati secondo il seguente formato *\<numero telefonico\>-\<mese\>.txt*. Ad esempio, il file: *0111234567-01.txt* corrisponde ai tabulati telefonici del numero chiamante 0111234567 del mese di gennaio.<br/>
All'interno della cartella sono presenti un numero indefinito di file relativi ad un numero indefinito di numeri telefonici diversi. Di seguito è riportato un esempio il file *0111234567-01.txt*:
```
0119876543 02 11.30 12.20
0119876543 02 15.01 16.09
0116384924 03 07.30 08.30
0119876543 05 23.50 23.59
0119876543 06 00.00 00.30
0119243015 07 14.15 14.22
```
Come si osserva dall'esempio, ciascun file *0111234567-01.txt* è suddiviso in 4 colonne che rappresentano:
1. Numero telefonico dell'utente chiamato
2. Giorno del mese in cui è avvenuta la chiamata
3. hh.mm: orario dell'inizio della chiamata
4. hh.mm ora di termine della chiamata

È possibile assumere che le chiamate vengano registrate in ordine cronologico ed è possibile avere una sola linea attiva, di conseguenza non sono permesse più chiamate in parallelo dallo stesso numero.<br/>
Si consideri inoltre che nel caso in cui la chiamata sia a cavallo tra una (o più) giornate essa verrà spezzata su uno o più giorni.
Come mostrato in esempio, se una chiamata verso il numero 0119876543 inizia alle 23.50 del giorno 5 e termina alle 00.30 del giorno 6 saranno presenti due voci distinte:
- `0119876543 05 23.50 23.59`
- `0119876543 06 00.00 00.30`

Leggendo ciascun file presente all'interno della cartella (una sola volta) è necessario produrre un log file denominato *\<numero telefonico\>.log*. Esso deve riportare per ciascun mese del quale sono disponibili i tabulati:
- Il Numero di minuti di chiamate effettuate in Fascia 1: dalle 00.00 alle 07.59
- Il Numero di minuti di chiamate effettuate in Fascia 2: dalle 08.00 alle 15.59
- Il Numero di minuti di chiamate effettuate in Fascia 3: dalle 16.00 alle 23.59

Di conseguenza, il file log relativo all'esempio sarà denominato *0111234567.log* e conterrà al suo interno i seguenti dati:
```
Mese: 01
Minuti effettuati in fascia 1 [00.00 – 07.59]: 60
Minuti effettuati in fascia 2 [08.00 – 15.59]: 146
Minuti effettuati in fascia 3 [16.00 – 23.59]: 18
```
Eventuali file relativi allo stesso numero ma contenenti i tabulati telefonici di mesi differenti dovranno aggiornare il medesimo log file. Ad esempio, lo stesso file *0111234567.log* potrebbe essere successivamente aggiornato nel seguente modo:
```
Mese: 01
Minuti effettuati in fascia 1 [00.00 – 07.59]: 60
Minuti effettuati in fascia 2 [08.00 – 15.59]: 146
Minuti effettuati in fascia 3 [16.00 – 23.59]: 18
Mese: 02
Minuti effettuati in fascia 1 [00.00 – 07.59]: 0
Minuti effettuati in fascia 2 [08.00 – 15.59]: 23
Minuti effettuati in fascia 3 [16.00 – 23.59]: 102
```

## Esercizio 2
Scrivere una funzione C che realizzi un filtro FIR. La funzione deve avere il seguente prototipo:
```c
int fir(int *samples, int *coefficients, int numCoefficients);
```
La funzione riceve in ingresso un puntatore ad un vettore di campioni interi, ed un puntatore ad un vettore di coefficienti.<br/>
Il numero di coefficienti è dato dal parametro `numCoefficients`.<br/>
La funzione calcola il valore di uscita del filtro FIR per i dati ricevuti in ingresso, e lo restituisce.<br/>
Si utilizzi la funzione FIR in un programma C che legge da un file di testo una sequenza di campioni. I coefficienti sono memorizzati in un altro file di testo di nome *coefficienti.txt*.<br/>
Ai dati è applicato il filtro FIR e l'output è salvato in un altro file di testo.<br/>

Si descriva il flow-chart dell'algoritmo utilizzato, e la struttura dati realizzata.

Si determini infine la complessità computazionale dell'algoritmo utilizzato, intesa come il numero ed il tipo di operazioni aritmetiche impiegate, nonché il numero di accessi in memoria necessari.
