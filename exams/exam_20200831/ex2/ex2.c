#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VARIABLES 16

int main(int argc, char *argv[]){
	FILE *ft, *fo;
	int i, flag=0, count=0, countch=0;
	int valori[VARIABLES];
	char ch;  
	char temp[256];
	char caratteri[VARIABLES][256];

	ft=fopen("template.txt", "r");									// apertura del file "template.txt" in lettura
	if (ft == NULL) {										// in caso di errore nell'apertura del file
			printf("Errore apertura file");							// stampa messaggio di errore
			exit(1);									// chiusura del programma
	}

	fo=fopen("output.txt", "w");									// apertura del file "output.txt" in scrittura
	if (fo == NULL) {										// in caso di errore nell'apertura del file
			printf("Errore apertura fie");							// stampa messaggio di errore
			exit(2);									// chiusura del programma
	}

	while(1) {
		ch = fgetc(ft);										// estrazione del carattere da "template.txt"
		if (ch==EOF)										// se il file è finito esce dal ciclo while
			break;
		if (flag==1) {										// è presente una variabile da sostituire
			if (ch==' ' || ch=='\n') {							// controllo se la variabile è terminata
				for(i=0; i<VARIABLES; i++) {						// controllo se è già stato richiesto il valore della variabile all'utente
					if (!strcmp(temp, caratteri[i])) {				// se il valore della variabile è già stato memorizzato
						fprintf(fo, "%d%c", valori[i], ch);			// stampa del valore corrispondente alla variabile sul file "output.txt"
						flag=0;							// azzeramento della flag
						countch=0;						// azzeramento del counter dei caratteri della variabile
						memset(temp, 0, sizeof(temp));				// reset della variabil temp
						break;
					}
				}
				if (flag==1) {								// se la flag non è stata azzerata è la prima volta che si incontra questa variabile
					printf("Inserire il valore della variabile '%s': ", temp);	// stampa a video la richiesta di immissione del valore della variabile
					scanf("%d", &valori[count]);					// salva il valore della variabile sull'array "valori[]"
					strcpy(caratteri[count], temp);					// salva il nome della variabile corispondente nella matrice "caratteri[][]"					
					fprintf(fo, "%d%c", valori[count], ch);				// stampa il valore della variabile sul file "output.txt"
					count++;							// incremento del contatore (massimo 16 variabili)
					flag=0;								// azzeramento della flag
					countch=0;							// azzeramento del counter dei caratteri della variabile
					memset(temp, 0, sizeof(temp));					// reset della variabil temp
				}
			} else {
				temp[countch]=ch;							// se la variabile non è terminata concatena il nuovo carattere
				countch++;								// incremento del counter dei caratteri della variabile
			}
		}
		else if (ch=='$') {									// se "ch" contiene il carattere '$'
			flag=1;										// setting della flag ad uno
		} else {
			fputc(ch,fo);									// copia del carattere dal file "template.txt" al file "output.txt"
		}
	}

	fclose(fo);											// chiusura del file "output.txt"
	fclose(ft);											// chiusura del file "template.txt"

	return 0;
}
