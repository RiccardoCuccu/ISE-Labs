# Appello del 08.02.2019

## Esercizio 1
Si vuole realizzare su una macchina Linux uno script in Python 3 che permetta di automatizzare la generazione di file di simulazione.<br/>
Si suppone di eseguire lo script all'interno di una cartella che contiene al suo interno il file simulationScript.run inteso come un generico script di simulazione.<br/>
Il file *simulationScript.run* contiene un numero indefinito di righe. Una delle righe contiene la parola chiave `simulationStep` seguita da un numero indefinito di valori numerici (interi e/o floating point).

Il file segue uno schema del tipo:
```
... numero indefinito di righe
simulationStep ...
... numero indefinito di righe
```
I valori che seguono la keyword `simulationStep` rappresentano i vari istanti di simulazione espressi in ordine
crescente.<br/>
Lo script Python dovrà creare `N` cartelle e inserire in ciascuna di esse un file *simulationScript.run* opportunamente modificato al fine di testare diversi step di simulazione.

Specifiche del problema:
- Lo script Python deve chiedere all'utente di inserire due valori numerici interi. Il primo dei due valori rappresenta l'istante t<sub>0</sub> (espresso in ms) della simulazione. Il secondo valore rappresenta l'istante t<sub>end</sub> della simulazione (espresso in ms).
- Lo script deve chiedere all'utente di inserire da linea di comando:
	- Lo step minimo che si intende utilizzare (in ms)
	- Lo step massimo che si intende utilizzare (in ms)
	- La granularità con la quale si vogliono testare i diversi step (in ms)
- Lo script deve quindi creare una cartella per ciascuno step che si desidera testare. Supponendo quindi di dover eseguire una simulazione tra 0 ms e 10 ms, volendo testare valori di step tra 1 ms e 5 ms con una granularità di 1 ms sarà necessario creare 5 cartelle denominate secondo la seguente formattazione:
	- `simulation_1`
	- `simulation_2`
	- `simulation_3`
	- `simulation_4`
	- `simulation_5`
Utilizzare il costrutto opportuno che permetta di verificare la corretta creazione di ciascuna cartella. Infatti, quando viene creata ciascuna cartella è necessario assicurarsi che la creazione sia andata a buon fine verificando che non siano state generate delle eccezioni.
In caso si sia verificato un errore che abbia impedito la creazione della cartella, riportare l'errore e terminare il programma.
- All'interno di ciascuna cartella deve essere inserito un file *simulationScript.run* identico a quello presente all'interno della radice ad eccezione della riga contenente i diversi `simulationStep` che deve contenere l'elenco degli istanti di simulazione compresi tra t0 e tend sullo specifico step.
Ad esempio, all'interno della cartella `simulation_1` dovrà essere modificato l'elenco dei `simulationStep` con:
```
simulationStep 0 1 2 3 4 5 6 7 8 9 10
```
Mentre all'interno della cartella `simulation_2` dovrà essere presente la riga:
```
simulationStep 0 2 4 6 8 10
```

## Esercizio 2
Si vuole realizzare su una macchina Linux un *Makefile* per automatizzare la compilazione di un programma scritto in linguaggio C.
Il programma è costituito da:
- Un file *main.c*, al cui interno è presente il seguente codice:
```c
/********************************************************************/
#include <stdio.h>
#include "version.h"
#include "support.h"

int main( int argc, char **argv ) {
	printf( "My program, version %d\n", VERSION );
	f1();
	f2();
	return 0;
}
/********************************************************************/
```
- Un file *support.h*, che contiene dichiarazioni di funzioni.
- Un file *support.c*, che contiene la definizione di funzioni utilizzate dal main.
- Un file *version.h*, contenente il seguente testo:
```c
/********************************************************************/
#ifndef VERSION_H
#define VERSION_H
#define VERSION 11
#endif
/********************************************************************/
```
Si scriva un *Makefile*, il quale, una volta invocato, produca un eseguibile con nome pari al numero di matricola del candidato. Inoltre, prima di avviare la compilazione, il processo di make deve incrementare di una unità il valore della macro del preprocessore `VERSION`, definita all'interno del file *version.h*.

È possibile utilizzare esclusivamente comandi della shell (gcc, awk, sed, etc.).
Non è possibile utilizzare altri linguaggi, ad esempio Python.