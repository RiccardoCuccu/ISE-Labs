/* 
	This is the source file of the Command Interpreter
	The functions declared in the interface will be implemented here
*/

#include <stdio.h>
#include <stdlib.h>
#include "CommandInterpreter.h"

/*
	This function is in charge of acquiring parameters, in case of
	x86_64 systems, via terminal and of "digesting" inputs in order
	for the parser to be able to understand what's the request.
*/
void acquireParameters(char* buffer) {
	
	// Get a maximum of 14 parameters from stdin and store it into the buffer
	fgets(buffer,size_buf,stdin);
	
}

/*
	This function is in charge of translating the parameters received by
	the "reader" (acquireParameter) and of writing into the struct data
	all the parameters for the drawer.
*/
ReadCmdReadType* passParameters(char* buffer){
	
	/*
		Here we define numerical parameters' buffers (to convert them to integer), all
		the integer numerical data and the command.
	*/
	char xc_buf[size_param], yc_buf[size_param], dx_buf[size_param], dy_buf[size_param];
	int xc, yc, dx, dy, m;
	char cmd, m_char;
	ReadCmdReadType* list_ptr = (ReadCmdReadType*) malloc(sizeof(ReadCmdReadType));
		
	/* Parameters extraction from the original buffer */
	cmd = buffer[0];

	int i;	

	/* If we have to print a point, mode will be in position 7, otherwise its position is the thirteenth */
	if(cmd == 'P') {
		for(i=0; i<3; i++) {
			xc_buf[i] = buffer[i+1];
			yc_buf[i] = buffer[i+4];
			dx_buf[i] = 0;
			dy_buf[i] = 0;
		}
		m_char = buffer[7];
	
	}
	else {
		for(i=0; i<3; i++) {
			xc_buf[i] = buffer[i+1];
			yc_buf[i] = buffer[i+4];
			dx_buf[i] = buffer[i+7];
			dy_buf[i] = buffer[i+10];
		}
		m_char = buffer[13];
	}
			
	/* Integer to char conversion */
	xc = (xc_buf[2]-'0') + (xc_buf[1]-'0')*10 + (xc_buf[0]-'0')*100;
	yc = (yc_buf[2]-'0') + (yc_buf[1]-'0')*10 + (yc_buf[0]-'0')*100;
	dx = (dx_buf[2]-'0') + (dx_buf[1]-'0')*10 + (dx_buf[0]-'0')*100;
	dy = (dy_buf[2]-'0') + (dy_buf[1]-'0')*10 + (dy_buf[0]-'0')*100;
	switch(m_char) {

		case '0': m = DRAW_MODE_CLR;
			break;

		case '1': m = DRAW_MODE_SET;
			break;

		case '2': m = DRAW_MODE_XOR;
			break;

		default: m = -1;

	}

	/* Parameters updating */
	list_ptr -> cmd = cmd;
	list_ptr -> xc = xc;
	list_ptr -> yc = yc;
	list_ptr -> dx = dx;
	list_ptr -> dy = dy;
	list_ptr -> m = m;
	
	return list_ptr;
}

