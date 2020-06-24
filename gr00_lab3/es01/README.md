The "draw" function is in charge of "drawing" in the 128x128 DisplayBuffer array by substituting certain values within certain cells of the forementioned array following the instructions parameters interpreted by the parser "CommandInterpreter" and then passed to the function.

The possible values substituted can be "0" (CLEAR, pixel off) or "1" (SET, pixel on), with the addition of the mode "XOR" which simply changes the selected value from "0" to "1" or viceversa.

The core of the "draw" function is the "DrawPoint" subfunction, which is in charge of drawing a single point in the DisplayBuffer by receiving as input the X,Y coordinates of the point and the drawing mode ("0", "1", "XOR"). This subfunction also contains a boundary check which  makes the function do nothing if the coordinates of the point are outside the Buffer (X,Y greater than 128 or lower thab 0).

The DrawLine subfunction receives two additional X,Y coordinates as input and then recursively calls the DrawPoint function to draw a line as a series of points between the two points described by their input coordinates.

The last subfunction, DrawEllipse, is a bit more complicated and utilizes Bresenham's simplified Curve Line Algorythm (found at ruslancray/lab site) to draw an ellipse by dividing it in two halves and drawing four points per step, and receiving as input the elliptical center X,Y coordinates, the length  of the X,Y semiaxis and the drawing mode.

In case of both the DrawLine and DrawEllipse the boundary check is implied in the DrawPoint calls, so it is possible to draw as far as the 128x128 allows even with inputs that would imply overstepping the boundaries.

The DisplayBuffer is then returned to the main and printed on screen.	
