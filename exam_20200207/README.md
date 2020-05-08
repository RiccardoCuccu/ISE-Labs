# Appello del 07.02.2020

## Esercizio 1


## Esercizio 2
Scrivere una funzione C che realizzi un filtro FIR. La funzione deve avere il seguente prototipo:
```c
int fir( int *samples, int *coefficients, int numCoefficients );
```
La funzione riceve in ingresso un puntatore ad un vettore di campioni interi, ed un puntatore ad un vettore di coefficienti.<br/>
Il numero di coefficienti è dato dal parametro `numCoefficients`.<br/>
La funzione calcola il valore di uscita del filtro FIR per i dati ricevuti in ingresso, e lo restituisce.<br/>
Si utilizzi la funzione FIR in un programma C che legge da un file di testo una sequenza di campioni. I coefficienti sono memorizzati in un altro file di testo di nome *coefficienti.txt*.<br/>
Ai dati è applicato il filtro FIR e l'output è salvato in un altro file di testo.<br/>

Si descriva il flow-chart dell'algoritmo utilizzato, e la struttura dati realizzata.

Si determini infine la complessità computazionale dell'algoritmo utilizzato, intesa come il numero ed il tipo di operazioni aritmetiche impiegate, nonché il numero di accessi in memoria necessari.
