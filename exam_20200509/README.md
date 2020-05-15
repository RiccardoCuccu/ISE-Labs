# Appello del 09.05.2020

## Esercizio 1
Si realizzi uno script Python che:
- riceva tramite seriale 100 pacchetti con il seguente formato: `STX<numero arbitrario di caratteri>ETX` dove `STX` è il carattere ASCII con valore intero pari a 2, ed `ETX` il carattere ASCII con valore intero pari a 3 (è garantito che questi due caratteri non siano mai presenti all'interno del pacchetto stesso);
- per ciascun pacchetto ricevuto, si registri in memoria il numero di caratteri ricevuti;
- al completamento della ricezione dei 100 pacchetti, si memorizzi all'interno di un file denominato *log.txt* il numero di occorrenze per ciascuna lunghezza. In particolare, deve essere generato un file di testo in cui le due colonne rappresentino rispettivamente:
  1. il numero di caratteri;
  2. il numero di pacchetti ricevuti con il rispettivo numero di caratteri.<br/>
  
  Ad esempio:
    ```
    7 1
    8 2
    10 5
    14 3
    ```

## Esercizio 2
Si vuole realizzare un codice in linguaggio C che:
- legga il file *log.txt* creato nell'esercizio precedente;
- calcoli e stampi a video il valor medio della lunghezza dei pacchetti ricevuti;
- calcoli e stampi a video la varianza della lunghezza dei pacchetti ricevuti.

## Esercizio 3
Scrivere un codice Python che:
- lanci la compilazione, mediante il compilatore gcc del codice C scritto nell'esercizio 2, supponendo che esso si trovi all'interno della stessa cartella;
- lanci l'esecuzione del file eseguibile così prodotto.
