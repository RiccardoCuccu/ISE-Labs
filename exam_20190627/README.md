# Appello del 27.06.2019

## Esercizio 1
Si vuole realizzare su una macchina Linux uno script in Python 3 che permetta leggere e memorizzare un file di testo.
In particolare, si suppone di avere un file in ingresso in cui ogni riga è composta come:
```
username yyyy-mm-dd hh.nn
```
Dove:
- `username` equivale alla stringa contente il nome di un utente
- `yyyy` equivale ad un anno
- `mm` equivale ad un mese
- `dd` equivale ad un giorno
- `hh` equivale ad un numero di ore (numero compreso tra 0 e 23)
- `nn` equivale ad un numero di minuti (numero compreso tra 0 e 59)

Ad esempio:
```
user1 2019-1-1 15.21
user2 2019-1-22 1.1
user1 2019-1-23 17.11
user2 2019-1-25 2.22
user1 2019-4-15 5.7
user1 2019-10-1 18.58
```

Questi dati, memorizzati su in file, rappresentano il CPU time utilizzato da ciascun utente in uno specifico giorno.
Tutti i dati registrati su di un file appartengono allo stesso anno.

Realizzare la più opportuna ed efficiente struttura dati in grado di memorizzare i dati presenti sul file considerando che il programma possa chiedere all'utente di poter inserire un **username** ed un **mese** da linea di comando in modo che possa conoscere quale sia stato il CPU time (espresso in **minuti**).

Ad esempio:
```
Inserire username: user1
Inserire mese: aprile
Numero di minuti: 307

Inserire username: user2
Inserire mese: gennaio
Numero di minuti: 203

Inserire username: user2
Inserire mese: dicembre
Numero di minuti: 0
```
Si supponga che il programma termini quando viene inserita la stringa "QUIT".

## Esercizio 2
Scrivere un programma utilizzando il linguaggio dell'interprete bash, in grado di generare un codice sorgente C, di compilarlo, e quindi di eseguirlo.<br/>
In particolare, il programma bash deve accettare un numero `n` sulla linea di comando con cui viene invocato, creare un programma C che calcoli il quadrato di `n` e lo stampi su stdout, invocarlo, e verificare che il numero calcolato sia corretto.
