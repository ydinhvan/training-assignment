// C program to demonstrate drawing a circle using OpenGL
#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#define pi 3.142857

// function to initialize
void myInit (void)
{
	// making background color black as first
	// 3 arguments all are 0.0 - 255.0 (black -> white)
	// red, green, blue, alpha )
	glClearColor(255.0, 255.0, 255.0, 1.0);
	
	// making picture color in RGB mode:
	// red = 0, green = 1, blue =0,
	glColor3f(0.0, 1.0, 0.0);
	
	// size of picture boundary is 1 pixel
	glPointSize(10.0);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();
	
	// setting window dimension in X- and Y- direction
	//gluOrtho2D (left, right, bottom, top)
	// 400x300
	gluOrtho2D(-200, 200, -150, 150);
}

void display (void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	float x, y, i;
	
	// iterate y up to 2*pi, i.e., 360 degree
	// with small increment in angle as
	// glVertex2i just draws a point on specified co-ordinate
	for ( i = 0; i < (2 * pi); i += 0.001)
	{
		// let 200 is radius of circle and as,
		// circle is defined as x=r*cos(i) and y=r*sin(i)
		x = 50 * cos(i);
		y = 50 * sin(i);
		
		glVertex2i(x, y);
	}
	{
		glVertex2i(0,0);
		glVertex2i(-200, -150);
		glVertex2i(-200, 150);
		glVertex2i(200, 150);
		glVertex2i(200, -150);
	}
	glEnd();
	glFlush();
}

int main (int argc, char** argv)
{
	// Initialize the init function
	glutInit(&argc, argv);
	
	//Initialize the toolkit: set display mode and color scheme
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	
	// giving window size in X- and Y- direction
	glutInitWindowSize(400, 300);
	
	// Sets the starting position fo the window
	glutInitWindowPosition(0, 0);
	
	// Giving name to window
	glutCreateWindow("Circle Drawing");
	
	myInit();
	
	glutDisplayFunc(display);

	// a loop until event occurs
	glutMainLoop();
}

