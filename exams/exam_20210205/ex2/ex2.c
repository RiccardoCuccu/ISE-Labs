#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <unistd.h> 
#include <errno.h> 

#define BAUDRATE 9600
#define SAMPLESNUM 16
#define SAMPLESSIZE 16
#define SAMPLEBYTES SAMPLESSIZE/8

int main(int argc, char *argv[]) {

	int sin, sout;
	int average, check, j;
	int i = 0;
	FILE *f;

	int int_elements[SAMPLESNUM];
	char hex_elements[SAMPLEBYTES+1];

	char serialNameIn[] = "myinput";
	char serialNameOut[] = "myoutput";

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

		//serialRead(sin, &hex_elements[0]);
		//serialRead(sin, &hex_elements[1]);
		check = read(sin, hex_elements, SAMPLEBYTES);				// read SAMPLESSIZE bits
		if (check != SAMPLEBYTES) break;					// check if the data stream is over

		hex_elements[SAMPLEBYTES] = '\0';					// enter the string terminator

		if (i >= SAMPLESNUM) {
			i = 1;								// reset data counter
		} else {
			i++;								// increment data counter
		}

		int_elements[i-1] = (int) strtol(hex_elements, NULL, 16);		// convert to decimal

		average = 0;								// reset average
		for(j = 0; j < i; j++) {						// sum all elements of the array
			average += int_elements[j];
		}
		average = average / i;							// update the moving average (only integer values)

		fprintf(f, "%x\n", average);						// write to file

		sprintf(hex_elements, "%x", average);					// prepare the string

		//serialWrite(sout, hex_elements[0]);
		//serialWrite(sout, hex_elements[1]);
		check = write(sout, &hex_elements, strlen(hex_elements));		// write to serial
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
