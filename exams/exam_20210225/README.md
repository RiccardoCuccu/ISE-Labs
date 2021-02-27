# Appello del 25.02.2021

## Esercizio 1
Risolvere l'esercizio richiesto mediante uno script in linguaggio Python.<br/>
Si vuole realizzare un programma in grado di ricevere uno stream di dati tramite interfaccia seriale.
I dati, ricevuti con un baudrate di 9600 bps, sono:
- Due numeri espressi mediante caratteri ASCII , in notazione esadecimale. Tali numeri rappresentano interi senza segno su 12 bit.
- Un operatore logico da applicare bit-a-bit ai due operandi ricevuti precedentemente. Gli operatori, rappresentati mediante un singolo carattere ASCII, possono essere:
    - `+` per eseguire una funzione di `OR`
    - `x` per eseguire una funzione di `AND`
    - `#` per eseguire una funzione di `XOR`
    
Il software deve ricevere i dati, effettuare l’operazione logica richiesta ed inviare il risultato tramite seriale mantenendo il medesimo baudrate, e lo stesso formato.
I risultati devono essere allo stesso tempo memorizzati su di un file di testo inserendo su ciascuna riga:
- Primo operando espresso in intero in notazione decimale
- Simbolo rappresentante la funzione logica applicata
- Secondo operando espresso in intero in notazione decimale
- Risultato dell’operazione espresso in intero in notazione decimale

## Esercizio 2
Risolvere l'esercizio 1 mediante un programma scritto in linguaggio C, supponendo di avere a disposizione le seguenti funzioni:
- `int serialOpen( char * serialName )`<br/>
Apre il canale seriale col nome specificato in \<serialName\>.
Restituisce -1 in caso di errore, altrimenti il numero di riferimento del canale.
- `int serialClose( int channel )`<br/>
Chiude il canale seriale specificato dal parametro \<channel\>.
Restituisce 0 in caso di successo, altrimenti -1.
- `int serialRead( int channel, uint8_t *dataPtr )`<br/>
Legge un byte letto dal canale seriale specificato dal parametro \<channel\>.
Il dato letto è memorizzato all'indirizzo specificato dal parametro \<dataPtr\>.
Restituisce 0 in caso di successo, altrimenti -1.
- `int serialWrite( int channel, uint8_t data )`<br/>
Scrive sul canale seriale specificato dal parametro \<channel\> il byte contenuto nel parametro \<data\>.
Restituisce 0 in caso di successo, altrimenti -1.
