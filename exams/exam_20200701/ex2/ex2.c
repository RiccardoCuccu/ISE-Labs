#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	FILE *fdiv, *fout;
	int i = 0, n = 0, count = 0;
	char character;	
	int aphabet[26] = {0};
	
	if ((fdiv=fopen("divinaCommedia.txt", "rt")) == NULL) {			// opens the divinaCommedia.txt file
		printf("Errore apertura file divinaCommedia.txt");		// returns error if it cannot open the file
		exit(1);
	}

	while (fscanf(fdiv, "%c", &character) != EOF) {				// EOF = End Of File
		if (character == 10 || character == 32){			// if character contains a \n (ASCII=10) or a Space (ASCII=32) it means that a new word begins
			count = count + 1;
		}
		else if (character >= 65 && character <= 90) {			// if character contains a value between A (ASCII=65) an Z (ASCII=90) it means that it is an uppercase
			n = character - 65;
			aphabet[n] += 1;
		}
		else if (character >= 97 && character <= 122) {			// if character contains a value between a (ASCII=97) an z (ASCII=122) it means that it is a lowercase
			n = character - 97;
			aphabet[n] += 1;
		}

		// First rough implementation
		/*switch(character) {
			case '\n':
			case ' ': count=count + 1; break;
			case 'A':
			case 'a': aphabet[0] += 1; break ;
			case 'B':
			case 'b': aphabet[1] += 1; break ;
			case 'C':
			case 'c': aphabet[2] += 1; break ;
			case 'D':
			case 'd': aphabet[3] += 1; break ;
			case 'E':
			case 'e': aphabet[4] += 1; break ;
			case 'F':
			case 'f': aphabet[5] += 1; break ;
			case 'G':
			case 'g': aphabet[6] += 1; break ;
			case 'H':
			case 'h': aphabet[7] += 1; break ;
			case 'I':
			case 'i': aphabet[8] += 1; break ;
			case 'J':
			case 'j': aphabet[9] += 1; break ;
			case 'K':
			case 'k': aphabet[10] += 1; break ;
			case 'L':
			case 'l': aphabet[11] += 1; break ;
			case 'M':
			case 'm': aphabet[12] += 1; break ;
			case 'N':
			case 'n': aphabet[13] += 1; break ;
			case 'O':
			case 'o': aphabet[14] += 1; break ;
			case 'P':
			case 'p': aphabet[15] += 1; break ;
			case 'Q':
			case 'q': aphabet[16] += 1; break ;
			case 'R':
			case 'r': aphabet[17] += 1; break ;
			case 'S':
			case 's': aphabet[18] += 1; break ;
			case 'T':
			case 't': aphabet[19] += 1; break ;
			case 'U':
			case 'u': aphabet[20] += 1; break ;
			case 'V':
			case 'v': aphabet[21] += 1; break ;
			case 'W':
			case 'w': aphabet[22] += 1; break ;
			case 'X':
			case 'x': aphabet[23] += 1; break ;
			case 'Y':
			case 'y': aphabet[24] += 1; break ;
			case 'Z':
			case 'z': aphabet[25] += 1; break;
			default: break;
		}*/
	}

	fclose(fdiv);								// closes the divinaCommedia.txt file

	if ((fout=fopen("report.txt", "wt")) == NULL) {				// opens the report.txt file
		printf("Errore apertura file");					// returns error if it cannot open the file
		exit(2);
	}

	fprintf(fout, "character\tOccorrenza\n");				// print the start line
	for (i=0; i<26; i++) {							// print each letter and its occurrences
		n=97+i;
		fprintf(fout, "%c\t\t%d\n", n, aphabet[i]);
	}

	fprintf(fout, "Totale parole: %d", count);				// print the number of words

	fclose(fout);								// closes the report.txt file

	return 0;
}
