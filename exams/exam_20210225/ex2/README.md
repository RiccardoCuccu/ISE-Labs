# Guida alla simulazione
La seriale è stata simulata tramite l'utilizzo di una Named Pipe (FIFO).

## Simulazione dello stream di input
Per simulare lo stream di input compilare il file `writer.c` tramite il comando:
```
make writer
```

Successivamente eseguire il file generato `writer` seguito dal nome della Named Pipe che si intende utilizzare, in questo caso:
```
./writer ttyS0
```

Infine inserire la successione di caratteri da utilizzare come stream di input, ad esempio:
```
012345+6789ABxCDEF01#234567+89ABCDxEF0123#456789+ABCDEFx012345#6789AB+CDEF01x234567#
```

## Lettura dello stream di output
Per leggere lo stream di output aprire un nuovo terminale e compilare il file `reader.c` tramite il comando:
```
make reader
```

Successivamente eseguire il file generato `reader` seguito dal nome della Named Pipe che si intende utilizzare, in questo caso:
```
./reader ttyS1
```

Infine in un terzo terminale compilare il file `ex2.c` ed eseguire il file generato `ex2.out` tramite il comando:
```
gcc ex2.c -Wall -o ex.out && ./ex.out
```
