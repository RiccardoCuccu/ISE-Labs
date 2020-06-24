# ISE Lab 2
Laboratorio 2 del corso **Integrazione di Sistemi Embedded** del corso magistrale in Embedde System (Ingegneria Elettronica) del Politecnico di Torino, anno accademico 2018/2019.<br/>

## Esercizio 1: verifica automatica degli output degli script del lab1
Si vuole creare uno script bash per il controllo automatico dell'esecuzione di una serie di script.
In particolare, si vuole verificare la correttezza degli script consegnati dopo il primo laboratorio del corso.
Scaricare il database di esempio fornito e creare uno script che verifichi quali tra i programmi caricate è conforme alle richieste del secondo esercizio del primo laboratorio.

Nello specifico, lo script es01.sh deve essere in grado di eseguire le seguenti operazioni:
1. Visitare tutte le cartelle che rispettano il formato *gr\<nn\>\<s\>_lab01*, dove *nn* corrisponde al numero del gruppo e *s* alla lettera corrispondente al sottogruppo.
2. Verificare che all'interno vi sia presente la cartella *es02/* e il file *es02/es02.sh*.
La mancata presenza della cartella o del file deve generare i relativi errori e il test del gruppo in esame deve considerarsi fallito.
3. Verificare che il file *host.txt* sia presente e che al suo interno vi sia il seguente contenuto:
    
    ```
    1) 165.137.1.1 alpha1.polito.it alpha1
    2) 165.137.1.2 alpha2.polimi.it alpha2
    3) 165.137.1.3 alpha33.unito.it alpha33
    4) 165.137.1.4 alpha4.unimore.it alpha4
    5) 232.1.1.1 beta1.tum.de beta1
    6) 232.1.1.2 beta2.tum.de beta2
    ```
    
    Nel caso in cui il file non esista o sia stato modificato crearlo o sovrascriverlo.
4. Eventuali altri file o sottocartelle presenti all'interno della cartella *es02/* (ad esempio *hostRenamed.txt*) devono essere rimossi.
5. Verificare che il file *es02/es02.sh* possegga i permessi di esecuzione e nel caso in cui non siano presenti devono essere forzati.
6. Eseguire lo script.
7. Verificare che il file *hostRenamed.txt* sia stato generato e che al suo interno vi sia un matching completo del contenuto:

    ```
    192.168.1.31 host1.polito.it host1
    192.168.1.32 host2.polimi.it host2
    192.168.1.33 host3.unito.it host3
    192.168.1.34 host4.unimore.it host4
    192.168.1.35 host5.tum.de host5
    192.168.1.36 host6.tum.de host6
    ```
    
    Verificando che:
    - il file *hostRenamed.txt* sia coerente al 100% con quello atteso;
    - nel caso in cui non lo sia, è necessario calcolare la percentuale di righe corrette.
8. Generare un file denominato *report.txt* contenete i report di esecuzione nel seguente formato:

    ```
    gr01a KO Missing directory es02/
    gr01b KO Missing directory es02/
    gr02a KO Unmatched output (0.00% correct)
    gr03a KO No es02/hostRenamed.txt was generated
    gr03b OK
    gr04a KO Missing file es02/es02.sh
    gr04b KO Unmatched output (66.67% correct)
    ```
    
    Dove: alla prima colonna corrisponde il nome del gruppo, alla seconda le stringhe OK o KO (OK = matching del 100%, KO matching < 100%), mentre alla terza colonna corrisponde il tipo di errore (se riscontrato):
    - mancata presenza del direttorio *es02/*;
    - mancata presenza dello script *es02.sh*;
    - mancata generazione del file di output *hostRenamed.txt*;
    - percentuale di matching tra il file di output e quello atteso.
9. (Facoltativo) Generare un ulteriore file denominato *log.txt* che contenga informazioni riguardo al livello di similitudine tra i vari script *es02.sh*.
Ad esempio, se vengono trovati due (o più) script identici devono essere segnalati i nomi dei due (o più) gruppi che hanno consegnato il medesimo file.
Inoltre deve essere possibile anche stimare la percentuale di similitudine tra due script in modo da segnalare i gruppi che hanno consegnato script molto simili (sebbene non identici).
Ad esempio è possibile che:
    - solo determinate porzioni di codice siano identiche;
    - vengano inserite diverse spaziature;
    - l'ordine delle righe non sia uguale.
