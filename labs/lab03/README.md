# ISE Lab 3
Laboratorio 3 del corso **Integrazione di Sistemi Embedded** del corso magistrale in Embedde System (Ingegneria Elettronica) del Politecnico di Torino, anno accademico 2018/2019.<br/>

## Esercizio 1
Scrivere il codice C relativo ad un sistema in grado di leggere comandi grafici da una generica periferica di ingresso, e di eseguirli. L'esecuzione deve comportare la modifica di un frame buffer contenuto in memoria RAM, di dimensione 128x128 pixel. Il buffer è monocromatico, ovvero ciascun pixel è rappresentato da un singolo bit, il cui valore ‘0’ o ‘1’ equivale ad un pixel spento o acceso rispettivamente.<br/>
I comandi accettati sono:
| Comando                              | Effetto            |
|--------------------------------------|--------------------|
| P\<x\>\<y\>\<m\>                     | Disegna un punto   |
| L\<x1\>\<y1\>\<x2\>\<y2\>\<m\>       | Disegna una linea  |
| E\<xc\>\<yc\>\<xaxis\>\<yaxis\>\<m\> | Disegna un ellisse |

Progettare il sistema in maniera modulare, in modo da avere in file separati funzioni che effettuino operazioni di tipo differente.

## Esercizio 2
Compilare, da shell, il codice ottenuto, su piattaforma x86_64, e quindi su piattaforma ARM embedded.<br/>
È tassativamente vietato l'utilizzo di IDE.<br/>
Riportare la dimensione del codice compilato in ambedue le piattaforme, nonchè i comandi utilizzati per ottenere l'eseguibile.
