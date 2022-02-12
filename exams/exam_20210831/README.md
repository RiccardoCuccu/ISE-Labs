# Appello del 31.08.2021

## Esercizio 1
Risolvere l'esercizio richiesto mediante uno script in linguaggio Python.<br/>
Si vuole realizzare un programma in grado di processare il contenuto di un file di testo. Il file, di nome *input.txt*, contiene una sequenza arbitrariamente lunga di record.

Ogni record è composto da:
- Una parentesi graffa aperta `{`
- Una lista di coppie chiave/valore
- Una parentesi graffa chiusa `}`

Ogni coppia chiave valore è costituita da:
- Una stringa alfanumerica rappresentante la chiave
- Il carattere dei due punti `:`
- Una stringa alfanumerica rappresentante il valore
- Il carattere del punto e virgola `;`

Ad esempio:
```
{key1: value1; key2:value1; ...}{key3: value3; key1:value4; ...}...
```

Sia la chiave che il valore sono stringhe composte esclusivamente di caratteri alfabetici e/o numeri.<br/>
Attorno ai delimitatori (parentesi graffe, `:` e `;`) possono essere anche presenti degli spazi, ovvero delle interruzioni di linea (vai a capo).

Il programma realizzato deve leggere il file *input.txt* e generare un file di uscita in cui ogni riga contiene una chiave e tutti i valori corrispondenti trovati, separati da una virgola, secondo il formato seguente:
```
key1: value1, value4, ...;
key2: value2, ...;
```
Qualora lo stesso valore sia associato più volte ad una stessa chiave, esso deve essere riportato in uscita soltanto una volta.<br/>
Si consideri che il numero massimo di chiavi differenti all'interno del file sia al più 1000.

Si sottolinea che nel file di ingresso non ci sono necessariamente delle interruzioni di linea, e quindi non è possibile leggere una riga alla volta.<br/>
Si evidenzia altresì che la dimensione complessiva del file non è nota a priori, e quindi non è possibile caricarne il contenuto completo in memoria prima di processare i dati.

## Esercizio 2
Risolvere l'esercizio 1 mediante un programma scritto in linguaggio C.
