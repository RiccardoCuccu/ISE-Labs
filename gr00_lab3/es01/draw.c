#include <stdlib.h>
#include <stdio.h>
#include "draw.h"

/*void CancDisplayBuffer(void)
{
	int i,j;
	for(i=0; i<n_row; i++)
	{
		for(j=0; j<n_col; j++)
			DisplayBuffer[i][j] = 0;
	}
} */

/*  This function is in charge of drawing a single point in the DisplayBuffer 
 *  according to the user's requests, which are understood through the
 *  reception of the struct data passed by the CommandInterpreter. */

void DrawPoint(int x, int y, int m)
{
	// Boundary check (if not respected, function does nothing)
	if(x >= 0 && x <n_row && y >= 0 && y<n_col){
		switch(m) {
			case DRAW_MODE_CLR:
				DisplayBuffer[x][y] = 0;
				break;
			case DRAW_MODE_SET:
				DisplayBuffer[x][y] = 1;
				break;
			case DRAW_MODE_XOR:
				DisplayBuffer[x][y] ^= 1;
				break;
			default:
				printf("Error: mode not found\n");
		}
	}
}

/*  This function is in charge of drawing a single line (as a series of
 *  single points between x1,y1 and x2,y2) in the DisplayBuffer according
 *  to the user's requests,
 *  which are understood through the reception of the struct data
 *  passed by the CommandInterpreter. */

void DrawLine(int x1, int y1, int x2, int y2, int m)
{
	int i=x1;
	int j=y1;

	while(i<=x2 && j<=y2){
		if(i==x2 && j!=y2){
	                DrawPoint(i,j,m);
                        j++;
                }else if(j==y2 && i!=x2){
                        DrawPoint(i,j,m);
                        i++;
                }else{
                        DrawPoint(i,j,m);
                        i++;
                        j++;
                }
	}
}


/*  This function implements Bresenham's semplified Line Algorithm to draw
 *  in the DisplayBuffer an ellipse (by drawing 4 different points at a time)
 *  according to the user's requests,
 *  which are understood through the reception of the struct data
 *  passed by the CommandInterpreter. */

void DrawEllipse(int xc, int yc, int xaxis, int yaxis, int m)
{
	// Here we define some parameters used by Bresenham's Algorithm
	int a_2=xaxis*xaxis;
	int b_2=yaxis*yaxis;
	int x,y,s;
	
	/* First half of ellipse */
	// (Boundary check inside DarwPoint function)
	for(x=0, y=yaxis, s=2*b_2+a_2*(1-2*yaxis); b_2*x <= a_2*y; x++){
		DrawPoint(xc+x,yc+y,m);
		DrawPoint(xc-x,yc+y,m);
		DrawPoint(xc+x,yc-y,m);
		DrawPoint(xc-x,yc-y,m);

		if(s>=0){
			s+=4*a_2*(1-y);
			y--;
		}
		s+=b_2*((4*x)+6);
	}
	
	/* Second half of ellipse */
	for(x=xaxis, y=0, s=2*a_2+b_2*(1-2*xaxis); a_2*y<=b_2*x; y++){
		DrawPoint(xc+x,yc+y,m);
		DrawPoint(xc-x,yc+y,m);
		DrawPoint(xc+x,yc-y,m);
		DrawPoint(xc-x,yc-y,m);

		if(s>=0){
			s+=4*b_2*(1-x);
			x--;
		}
		s+=a_2*((4*y)+6);
	}
}

