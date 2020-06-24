/* This is the header file of the drwarer function
 * It's divided into three functions, a short description is given
 * before every function  */

// Number of buffer rows and of buffer columns (standard at 128x128), mode

#define n_row 128
#define n_col 128
#define DRAW_MODE_CLR 0
#define DRAW_MODE_SET 1
#define DRAW_MODE_XOR 2

int DisplayBuffer[n_row][n_col];


//void CancDisplayBuffer(void);

/*  This function is in charge of drawing a single point in the DisplayBuffer 
 *  according to the user's requests, which are understood through the
 *  reception of the struct data passed by the CommandInterpreter. 
 */

void DrawPoint(int x, int y, int m);

/*  This function is in charge of drawing a single line (as a series of
 *  single points between x1,y1 and x2,y2) in the DisplayBuffer according
 *  to the user's requests,
 *  which are understood through the reception of the struct data
 *  passed by the CommandInterpreter. 
 */

void DrawLine(int x1, int y1, int x2, int y2, int m);

/*  This function implements Bresenham's semplified Line Algorithm to draw
 *  in the DisplayBuffer an ellipse (by drawing 4 different points at a time)
 *  according to the user's requests,
 *  which are understood through the reception of the struct data
 *  passed by the CommandInterpreter.
 */

void DrawEllipse(int xc, int yc, int xaxis, int yaxis, int m);
