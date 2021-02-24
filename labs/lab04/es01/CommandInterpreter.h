/*
	This is the header file of the Command Interpreter
	It's divided into two functions, a short description is given before every function
*/

//	Buffer size, parameter, 4 coordinates (max), mode
#define size_buf 16
#define size_param 3
#define DRAW_MODE_CLR 0
#define DRAW_MODE_SET 1
#define DRAW_MODE_XOR 2

// Struct data in which we save parameters to be returned to main
typedef struct {
	char cmd;
	int xc;
	int yc;
	int dx;
	int dy;
	int m;
} ReadCmdReadType;

/*
	This function is in charge of acquiring parameters, in case of
	x86_64 systems, via terminal and of "digesting" inputs in order
	for the parser to be able to understand what's the request.
*/
void acquireParameters(char* buffer);

/*
	This function is in charge of translating the parameters received by
	the "reader" (acquireParameter) and of writing into the struct data
	all the parameters for the drawer.
*/
ReadCmdReadType* passParameters(char* buffer);
