# ISE Lab 1
Laboratorio 1 del corso Integrazione di Sistemi Embedded del corso magistrale in Embedde System (Ingegneria Elettronica) del Politecnico di Torino, anno accademico 2019/2020.<br/>

## Esercizio 1: menu per la gestione semplificata dei file
Si vuole creare uno script che permetta di operare sui file le seguenti azioni:
1. Riceva da tastiera il nome di un file completo di estensione e ne verifichi l'esistenza all'interno della home directory. Se all'interno della cartella sono presenti più sottocartelle, queste devono essere visitate in modo ricorsivo per ricercare la presenza del file (o più copie del file). Ogni volta che un'occorrenza viene trovata deve essere visualizzato un messaggio contenente il path all'interno del quale è stato trovato il file.
2. Creazione di un nuovo file (di testo) il cui nome e direttorio di destinazione devono essere letti da tastiera. Nel caso in cui la cartella di destinazione non esista questa deve essere creata dandone avviso all'utente. Una volta accertata la presenza della cartella di destinazione è necessario verificare che il file non esista già; in tal caso restituire un errore all'utente.
3. Spostamento di un file da una cartella sorgente ad una destinazione controllando l'esistenza di entrambi i direttori. Nel caso in cui la cartella sorgente non esista generare un errore; nel caso in cui la cartella destinazione non esista è necessario chiedere all'utente (Y/n) conferma prima di crearla.
4. Rimozione di un file il cui nome viene fornito dall'utente
5. Rimozione di un direttorio il cui nome viene fornito dall'utente. Se all'interno della cartella sono presenti più sottocartelle anch'esse devono essere rimosse.
6. Nel caso in cui l'utente fornisca argomenti errati deve essere generato un errore che spieghi chiaramente l'errore (ad esempio, numero del comando errato, numero di argomenti errato, ecc... )

### Consegna
L'esecuzione deve essere ottenuta mediante il comando:
```bash
$ ./es01.sh <comando> <argomento/i>
```
ad esempio:
```bash
$ ./es01.sh 1 fileName
$ ./es01.sh 2 fileName /path/
$ ./es01.sh 3 filename /sourcePath/ /destinationPath/
$ ./es01.sh 4 fileName
$ ./es01.sh 5 /path/
```

## Esercizio 2: rinominazione indirizzi IP
Dato un elenco di indirizzi IP associati a diversi host come nel file in esempio denominato *host.txt*:
```
1) 165.137.1.1 alpha1.polito.it alpha1
2) 165.137.1.2 alpha2.polimi.it alpha2
3) 165.137.1.3 alpha33.unito.it alpha33
4) 165.137.1.4 alpha4.unimore.it alpha4
5) 232.1.1.1 beta1.tum.de beta1
6) 232.1.1.2 beta2.tum.de beta2
```

A partire dal file in esempio *host.txt* è necessario creare un secondo file *hostRenamed.txt* secondo le seguenti regole:
1. La prima colonna deve essere scartata
2. L'indirizzo IP deve essere composto come 192.168.1.*n*, dove n è il numero della riga (*m*) + 30.
3. Il nome di ciascun host deve essere composto come host*m*.
4. Il nome del dominio deve rimanere invariato
5. L'ultima colonna deve contenere il nuovo nome dell'host

Di conseguenza il file di uscita *hostRenamed.txt* dovrà essere identico a:
```
192.168.1.31 host1.polito.it host1
192.168.1.32 host2.polimi.it host2
192.168.1.33 host3.unito.it host3
192.168.1.34 host4.unimore.it host4
192.168.1.35 host5.tum.de host5
192.168.1.36 host6.tum.de host6
```

### Consegna
L'esecuzione deve essere ottenuta mediante il comando:
```bash
$ ./es02.sh
```
il quale deve generare il file *hostRenamed.txt*.
