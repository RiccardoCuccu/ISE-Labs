#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <unistd.h> 
#include <errno.h> 

#define BAUDRATE 9600
#define INTBIT 12
#define HEXDIGIT INTBIT/4
#define BYTETOREAD HEXDIGIT*2+1

int main(int argc, char *argv[]) {

	int sin, sout;
	int n1, n2;
	int check, result;
	//int i;
	FILE *f;

	char op;
	char cn1[HEXDIGIT+1];
	char cn2[HEXDIGIT+1];
	char cresult[HEXDIGIT+1];

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

		//for (i = 0; i < HEXDIGIT; i++) {					// read the first hexadecimal (3 bytes)
		//	serialRead(sin, &cn1[i]);
		//}
		check = read(sin, cn1, HEXDIGIT);					// read the first hexadecimal
		if (check != HEXDIGIT) break;						// check if the data stream is over
		cn1[HEXDIGIT] = '\0';							// enter the string terminator

		//for (i = 0; i < HEXDIGIT; i++) {					// read the second hexadecimal (3 bytes)
		//	serialRead(sin, &cn2[i]);
		//}
		check = read(sin, cn2, HEXDIGIT);					// read the second hexadecimal
		if (check != HEXDIGIT) break;						// check if the data stream is over
		cn2[HEXDIGIT] = '\0';							// enter the string terminator

		//serialRead(sin, &op);
		check = read(sin, &op, 1);						// read the sign of the operation
		if (check != 1) break;							// check if the data stream is over

		sscanf(cn1, "%x", &n1);							// extract first hexadecimal value
		sscanf(cn2, "%x", &n2);							// extract second hexadecimal value

		if (op == '+') result = n1 | n2;					// OR operation
		else if (op == 'x') result = n1 & n2;					// AND operation
		else if (op == '#') result = n1 ^ n2;					// XOR operation

		fprintf(f, "%d %c %d %d\n", n1, op ,n2, result);			// write to file

		sprintf(cresult, "%03x", result);					// prepare the string

		//for (i = 0; i < HEXDIGIT; i++) {					// write the result (3 bytes)
		//	serialWrite(sout, &cresult[i]);
		//}
		check = write(sout, &cresult, strlen(cresult));				// write to serial
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
