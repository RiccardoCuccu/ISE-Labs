#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define SAMPLES 16

int main(int argc, char *argv[]) {

	int i = 0;
	int j = 0;
	int k = 0;
	int average;
	int temp[4] = {0};
	int values[SAMPLES];

	char ch;

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

	while(!feof(fin)) {							// loops until the file is finished
		if (i == SAMPLES) {
			average = 0;						// reset average
			for(k = 0; k < SAMPLES; k++) {
				average = average + values[k];			// sum the samples
			}
			average = average/SAMPLES; 				// average calculation
			memset(values, 0, sizeof(values)); 			// reset variable "values"
			fprintf(fout, "%04x ", average); 			// writing the 4-digit hexadecimal value (16 bit) to the output file
			i = 0; 							// reset samples counter
		} else {
			ch = fgetc(fin);					// extract a char
			if (ch == 0x20) {					// if the schar is a space
				switch (j) {					// sum of the digits according to their order of magnitude
					case 1: values[i] = temp[0];
					break;
					case 2: values[i] = temp[0]*10 + temp[1];
					break;
					case 3: values[i] = temp[0]*100 + temp[1]*10 + temp[2];
					break;
					case 4: values[i] = temp[0]*1000 + temp[1]*100 + temp[2]*10 + temp[3];
					break;
					default: values[i] = 0;
					break;
				}
				memset(temp, 0, sizeof(temp));			// reset variable "temp"
				i++;						// increment samples counter
				j = 0;						// reset digits counter
			} else {
				temp[j] = atoi(&ch);				// conversion from character to integer
				j++;						// increment digits counter
			}
		}
	}

	fclose(fin);								// close input file
	fclose(fout);								// close output file

	return 0;
}
