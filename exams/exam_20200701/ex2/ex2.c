#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){

	FILE  *fdiv, *fout;
	int i=0, count =0;
	char carattere='a';                                        // variabile p
	int aphabet[25]={0};                                    // vettore dove allocare il conteggio dei caratteri
	int *ptr_alphabet;
	char letters[]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};               // vettore contenente i caratteri
	char *ptr_letters;
	int flag=1;

	if ((fdiv=fopen("divinaCommedia.txt", "rt"))==NULL) {
		printf("Errore apertura file divinaCommedia.txt");
		exit(1);
	}

	while(flag==1) {                                                    // finchè non finisce il file
		carattere='c';
		while (carattere!='\n' && flag==1) { // finchè non finisce la stringa             
			if (fscanf(fdiv, "%c", &carattere) == EOF) {		// scansiona carattere per carattere
				flag=0;
				break;
			}
			printf("%c", carattere);

			switch(carattere) { // switch-case in base al contenuto di carattere
				case ' ': count=count+1; break;                           // c'è uno spazio quindi inizia una nuova parola
				case '\n': count=count+1; break;                           // c'è una nuova riga quindi inizia una nuova parola
				case 'A':
				case 'a': ptr_alphabet=&aphabet[0]; aphabet[0] = *ptr_alphabet+1; break ;
				case 'B':
				case 'b': ptr_alphabet=&aphabet[1]; aphabet[1] = *ptr_alphabet+1; break ;
				case 'C':
				case 'c': ptr_alphabet=&aphabet[2]; aphabet[2] = *ptr_alphabet+1; break ;
				case 'D':
				case 'd': ptr_alphabet=&aphabet[3]; aphabet[3] = *ptr_alphabet+1; break ;
				case 'E':
				case 'e': ptr_alphabet=&aphabet[4]; aphabet[4] = *ptr_alphabet+1; break ;
				case 'F':
				case 'f': ptr_alphabet=&aphabet[5]; aphabet[5] = *ptr_alphabet+1; break ;
				case 'G':
				case 'g': ptr_alphabet=&aphabet[6]; aphabet[6] = *ptr_alphabet+1; break ;

					/* faccio il case per tutte le lettere (c'è sicuramente modo di ottimizzare notevolmente e non dover fare i singoli case) */
				case 'Z':
				case 'z': ptr_alphabet=&aphabet[25]; aphabet[25] = *ptr_alphabet+1+1; break;
				default: break;    // in caso di altri simboli non fa nulla
			}
		}
	}

	printf("\n");
	//count=count-1;				// perchè conta anche l'ultimo \n

	if ((fout=fopen("report.txt", "wt"))==NULL) {            // restituisce errore se non riesco ad aprire il file
		printf("Errore apertura file");
		exit(2);
	}

	fprintf(fout, "Carattere\tOccorrenza\n");                   // stampa riga iniziale
	for (i=0; i<26; i++) {                                        // ciclo per il numero di lettere dell'alfabeto
		ptr_alphabet=&aphabet[i];
		ptr_letters=&letters[i];
		fprintf(fout, "%c\t\t%d\n", *ptr_letters, *ptr_alphabet);            // stampa il carattere e il relativo numero di occorrenze
	}

	fprintf(fout, "Totale parole: %d", count);                // stampa il totale delle parole

	fclose(fout);
	fclose(fdiv);
	
	return 0;
}
