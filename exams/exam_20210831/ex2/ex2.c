#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

#define MAX_KEYS 10
#define MAX_VALS 10
#define MAX_CHAR 100

struct Chiave {									// structure for storing key and values
	char key[MAX_CHAR];
	char values[MAX_VALS][MAX_CHAR];
};

int main(int argc, char *argv[]) {

	int i, j;								// counters
	int first;								// flag to indicate if it is the first character to be printed
	int exister = 0;							// flag to indicate if a value already exists
	int switcher = 0;							// flag to switch between key and value

	char ch;								// variable for temporary storage of the character
	char key[MAX_CHAR];							// variable for temporary storage of the key
	char value[MAX_CHAR];							// variable for temporary storage of the value

	FILE *fin, *fout;							// file pointers

	struct Chiave Chiavi[MAX_KEYS];						// array of structures
		
	fin = fopen("input.txt", "r"); 						// open file for reading
	if(fin == NULL) {
		perror("ERROR opening input file");
		exit(errno);
	}

	while(1){
		ch = fgetc(fin);									// read one character and save it in 'ch'
		if(ch == EOF) break;									// if 'ch' is EOF the file is finished
		else if(ch == '{' || ch == '}' || ch == ' ' || ch == '\n') continue;			// characters allowed but not relevant
		else if(ch == ':') switcher = 1;							// if 'ch' is ':' the key is finished
		else if(ch == ';') {									// if 'ch' is ';' the value is finished
			for(i=0; i < MAX_KEYS; i++) {							// iterates over keys
				if(!strcmp(key, Chiavi[i].key)) {					// if the key is already present
					for(j=0; j < MAX_VALS; j++) {					// iterates over values
						if(!strcmp(value, Chiavi[i].values[j])) {		// if the value is already present
							exister = 1;					// set flag
							break;
						}
					}
					if(exister == 0) {						// if the value does not exist yet
						for(j=0; j < MAX_VALS; j++) {				// iterates over values
							if(!strcmp("",Chiavi[i].values[j])) {		// if it is an empty value
								strcpy(Chiavi[i].values[j], value);	// save value
								break;
							}
						}
					}
					strcpy(key, "");			// reset variable
					strcpy(value, "");			// reset variable
					exister = 0;				// reset flag
				} else if(!strcmp("",Chiavi[i].key)) {		// if the key was not found
					strcpy(Chiavi[i].key, key);		// save key
					strcpy(Chiavi[i].values[0], value);	// save value
					strcpy(key, "");			// reset variable
					strcpy(value, "");			// reset variable
				}
			}
			switcher = 0;						// reset flag
		}
		else if(isdigit(ch) || isalpha(ch)) {
			if(switcher == 0)					// if 'ch' is a key character
				strncat(key, &ch, 1);				// concatenate key
			else if(switcher == 1)					// if 'ch' is a value character
				strncat(value, &ch, 1);				// concatenate value
		}
		else {
			printf("ERROR: character not allowed!");
			return -1;
		}
	}

	fclose(fin);								// close input file

	fout = fopen("output.txt", "w"); 					// open file for reading
	if(fout == NULL) {
		perror("ERROR opening output file");
		exit(errno);
	}

	for(i = 0; i < MAX_KEYS; i++) {						// for each key
		if (!strcmp("",Chiavi[i].key)) break;				// if the key isn't empty
		first = 1;							// flag for the first printed value
		fprintf(fout, "%s: ", Chiavi[i].key);				// print the key
		for(j=0; j < MAX_VALS; j++) {					// for each key value
			if(first == 1 && strcmp("",Chiavi[i].values[j])) {	// if it is the first value and isn't empty
				fprintf(fout, "%s", Chiavi[i].values[j]);	// print the value
				first = 0;					// reset flag
			} else if(strcmp("",Chiavi[i].values[j])){		// if it isn't the first value and isn't empty
				fprintf(fout, ", %s", Chiavi[i].values[j]);	// print the value
			}
		}
		fprintf(fout, ";\n");						// print the end of the line
	}

	fclose(fout);								// close output file
	
	return 0;
}
