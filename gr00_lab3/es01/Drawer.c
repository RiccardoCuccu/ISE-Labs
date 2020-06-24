#include<stdio.h>
#include<stdlib.h>
#include"CommandInterpreter.h"
#include"draw.h"

int main(int argc, char** argv) {

	ReadCmdReadType* list_ptr;
	char buffer[size_buf];
	int i,j;
	//CancDisplayBuffer();

	while(1) {
		printf("Insert parameters: ");
		acquireParameters(buffer);
		list_ptr = passParameters(buffer);

		switch(list_ptr->cmd) {
			case 'P':
				DrawPoint(list_ptr->xc, list_ptr->yc, list_ptr->m);
				break;
			case 'L':
				DrawLine(list_ptr->xc, list_ptr->yc, list_ptr->dx, list_ptr->dy, list_ptr->m);
				break;
			case 'E':
				DrawEllipse(list_ptr->xc, list_ptr->yc, list_ptr->dx, list_ptr->dy, list_ptr->m);
				break;
			default:
				printf("Command not found\n");
		}

		for(i=0; i<n_row; i++) {
			for(j=0; j<n_col; j++)
				printf("%i",DisplayBuffer[i][j]);
			printf("\n");
		}
		free(list_ptr);
	}

	return 0;
}
