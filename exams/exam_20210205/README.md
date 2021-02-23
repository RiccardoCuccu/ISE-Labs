# Appello del 05.02.2021

## Esercizio 1
Risolvere l'esercizio richiesto mediante uno script in linguaggio Python.<br/>
Si vuole realizzare un programma in grado di ricevere uno stream di dati tramite interfaccia seriale.
I dati, ricevuti con un baudrate di 9600 bps, sono numeri espressi mediante caratteri ASCII, in notazione esadecimale su 16 bit.<br/>
Il software deve ricevere i dati, calcolare la media mobile su 16 campioni ed inviare il risultato tramite seriale mantenendo il medesimo baudrate, e lo stesso formato.
I risultati devono essere allo stesso tempo memorizzati su di un file di uscita, di nome *data.txt*.

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
