#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define DIGITS 4
#define SAMPLES 16

int main(int argc, char *argv[]) {

	int i;									// generic counter
	int j = 0;								// samples counter
	int k = 0;								// digit counter
	int average;
	int values[SAMPLES];

	char ch;
	char temp[DIGITS];
	char format[10];

	FILE *fin, *fout;

	fin = fopen("input.txt", "r"); 						// open file for reading
	if(fin == NULL) {
		perror("ERROR opening input file");
		exit(errno);
	}

	fout = fopen("output.txt", "w");					// open file for writing
	if(fout == NULL) {
		perror("ERROR opening output file");
		exit(errno);
	}

	sprintf(format, "%%0%dx ", DIGITS);					// create the string for the print format

	for(i = 0; i < DIGITS; i++){						// reset digits
		temp[i] = '\0';
	}

	while(1) {
		
		ch = fgetc(fin);						// read one character at a time

		if (ch == ' ' || ch == EOF) {					// if the character is a space or EOF the number is finished
			values[j] = atoi(temp);					// conversion from string to integer
			j++;							// increment samples counter
			k = 0;							// reset digit counter
			for(i = 0; i < DIGITS; i++){				// delete digits
				temp[i] = '\0';
			}
		} else {
			temp[k]=ch;						// save digit
			k++;							// increment digit counter
		}

		if(j == SAMPLES) {
			average = 0;						// reset average
			for(i = 0; i < SAMPLES; i++) {
				average += values[i];				// sum the samples
			}
			average = average / SAMPLES;				// average calculation
			fprintf(fout, format, average);				// write 4-digit hexadecimal value (16 bit) to the output file
			j = 0;							// reset samples counter
		}

		if(ch == EOF) break;						// EOF
	}

	fclose(fin);								// close input file
	fclose(fout);								// close output file

	return 0;
}
