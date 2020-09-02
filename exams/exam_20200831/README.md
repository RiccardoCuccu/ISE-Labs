# Appello del 31.08.2020

## Esercizio 1
Risolvere l'esercizio richiesto mediante uno script in linguaggio Python.<br/>
Si vuole elaborare un file di testo denominato *template.txt* in cui la lunghezza di ciascuna riga e dell'intero testo sono arbitrarie.<br/>
Il testo contiene al suo interno anche diverse stringe alfabetiche precedute dal simbolo "$".<br/>
Il file deve essere letto **carattere per carattere** e ogni qualvolta si incontri una stringa composta interamente da caratteri alfabetici e preceduta dal carattere **$** deve essere chiesto all'utente di inserirne il corrispondente valore numerico intero.<br/>
Ad esempio, leggendo il file:
```
xx $a
abcd $b
456 $a xxx $c
```
Sarà necessario chiedere all'utente di inserire i valori numerici (interi) delle variabili a, b, e c.<br/>
Si noti che, sebbene la variabile a, compaia più volte all'interno del testo, essa deve essere richiesta all'utente un'unica volta, ed il valore immesso dovrà essere utilizzato per tutte le successive occorrenze. Si noti che il numero massimo di variabili presenti all'interno del file **template.txt** è pari a 16.<br/>
Infine, si generi un secondo file denominato **output.txt** in cui le variabili a, b, e c sono sostituite con il relativo valore numerico.
Riprendendo il caso precedente, e supponendo che l'utente abbia inserito i dati a=1, b=2, c=3, verrà generato il file:
```
xx 1
abcd 2
456 1 xxx 3
```
Non è consentito creare in memoria il file elaborato, per poi scriverlo. È indispensabile che esso sia scritto **mentre** si effettua la lettura.

## Esercizio 2
Risolvere l'esercizio 1 mediante un programma scritto in linguaggio C.
