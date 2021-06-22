#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <unistd.h> 
#include <errno.h> 

#define BAUDRATE 9600
#define INTBIT 16
#define HEXDIGIT INTBIT/4
#define MAX_SAMPLES 16

int main(int argc, char *argv[]) {

	int sin, sout;
	int average, check, j;
	int i = 0;
	FILE *f;

	int int_elements[MAX_SAMPLES] = {};						// initialize the array to zero
	char hex_element[HEXDIGIT+1];

	char serialNameIn[] = "ttyS0";
	char serialNameOut[] = "ttyS1";

	//sin = serialOpen(serialNameIn);
	//sout = serialOpen(serialNameOut);
	mkfifo(serialNameIn, 0666);							// create serial (simulated with a FIFO)
	mkfifo(serialNameOut, 0666);							// create serial (simulated with a FIFO)

	sin = open(serialNameIn, O_RDONLY | O_NONBLOCK);				// open serial (simulated with a FIFO)
	if(sin == -1) {
		perror("ERROR during OPEN execution (input stream)");
		exit(errno);
	}

	sout = open(serialNameOut, O_WRONLY | O_NONBLOCK);				// open serial (simulated with a FIFO)
	if(sout == -1) {
		perror("ERROR during OPEN execution (output stream)");
		exit(errno);
	}

	f = fopen("data.txt", "w");							// open file for writing
	if(f == NULL) {
		perror("ERROR during FOPEN execution");
		exit(errno);
	}

	while(1) {

		//for (j = 0; j < HEXDIGIT; j++) {
		//	serialRead(sin, &hex_element[j]);
		//}
		check = read(sin, hex_element, HEXDIGIT);				// read HEXDIGIT bytes
		if (check != HEXDIGIT) break;						// check if the data stream is over

		hex_element[HEXDIGIT] = '\0';						// enter the string terminator

		if (i >= MAX_SAMPLES-1) i = 0;						// reset data counter
		else i++;								// increment data counter

		sscanf(hex_element, "%x", &int_elements[i]);				// extract hexadecimal value

		average = 0;								// reset average
		for(j = 0; j < MAX_SAMPLES; j++) {					// sum all elements of the array
			average += int_elements[j];
		}
		average = average / MAX_SAMPLES;					// update the moving average (only integer values)

		fprintf(f, "%04x\n", average);						// write to file

		sprintf(hex_element, "%04x", average);					// prepare the string

		//for (j = 0; j < HEXDIGIT; j++) {
		//	serialWrite(sout, hex_element[j]);
		//}
		check = write(sout, &hex_element, strlen(hex_element));			// write to serial
		if (check == -1) {
			perror("ERROR during WRITE execution (output stream)");
			exit(errno);
		}
	}

	//serialClose(sin);
	//serialClose(sout);
	close(sin);									// close serial (simulated with a FIFO)
	close(sout);									// close serial (simulated with a FIFO)
	fclose(f);									// close file

	return 0;
}
