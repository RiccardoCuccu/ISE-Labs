# ISE Lab 4
Laboratorio 4 del corso **Integrazione di Sistemi Embedded** del corso magistrale in Embedde System (Ingegneria Elettronica) del Politecnico di Torino, anno accademico 2018/2019.<br/>

## Esercizio 1
Relativamente al programma realizzato nel Laboratorio 3, scrivere un makefile per la compilazione automatica del codice.<br/>
In particolare:
1. Scrivere un makefile con regole esplicite, in cui il target di default comporti la compilazione per piattaforma x86_64. Deve inoltre essere presente il target ‘clean’, che quando invocato elimina gli eseguibili ed i file oggetto.
2. Scrivere un makefile con regole esplicite, in cui il target di default comporti la compilazione per piattaforma Arm. Deve inoltre essere presente il target ‘clean’, che quando invocato elimina gli eseguibili ed i file oggetto.
3. Scrivere un makefile con regole esplicite, in cui il target di default comporti la compilazione per una piattaforma arbitraria, secondo quanto specificato sulla riga di comando di make. In particolare, il comando make PREFIX=xxx deve causare l’utilizzo di xxx-gcc come compilatore.
4. Modificare il makefile precedente in modo da utilizzare per quanto possibile regole implicite.
5. Aggiungere al makefile il target test, eseguito su richiesta, che effettui un test sul programma realizzato. Il test deve essere effettuato mediante l’utilizzo di comandi di shell.