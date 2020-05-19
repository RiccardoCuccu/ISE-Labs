# Appello del 04.09.2019

## Esercizio 1
Si vuole realizzare su una macchina Linux uno script in Python 3 che permetta leggere e memorizzare un file di testo.<br/>
In particolare, si suppone di avere un file in ingresso in cui ogni riga è composta come:
```
nome cognome mansione
```
Oppure:
```
nome cognome progetto <codice progetto>
```
Ad esempio:
```
mario rossi ingegnere elettronico
julia smith ingegnere informatico
mario rossi progetto 1234
mario rossi progetto 5678
julia smith progetto 1234
```
Creare una classe denominata “Impiegati” per memorizzare:
- il nome e il cognome di ciascun impiegato;
- la mansione dell'impiegato;
- l'elenco dei codici dei progetti a cui ha partecipate l'impiegato.

È necessario utilizzare un metodo specifico della classe per aggiornare l'elenco dei progetti.<br/>
Infine, il programma deve stampare a video l'elenco degli impiegati, la mansione e l'elenco dei progetti.

Ad esempio:
```
mario rossi, ingegnere elettronico -- Lista progetti: 1234, 5678
julia smith, ingegnere informatico -- Lista progetti: 1234
```

## Esercizio 2
Realizzare, utilizzando l'interprete bash, un programma con le seguenti funzonalità:
- accettare sulla riga di comando un percorso (es. `/home/studente1/test`);
- contare il numero di file e cartelle presenti nel percorso indicato, ed in tutti genitori (es. `/home/studente1/test`, `/home/studente1`, `/home`, `/`);
- scrivere il nome di ogni cartella analizzata, ed i numeri ricavati al punto precedente, a video, in formato tabulare. I dati devono essere incolonnati, con il nome della cartella giustificato a sinistra, e quello dei numeri giustificato a destra;
- scrivere una riga conclusiva contenente i totali.

Nel caso dell'esempio indicato, a video si dovrà quindi leggere:
```
/home/studente1/test	10	4
/home/studente1		9	35
/home			2	2
/			4	27
Totale			25	68
```
