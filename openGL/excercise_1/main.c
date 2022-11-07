/*
 * Copyright (c) 1993-2003, Silicon Graphics, Inc.
 * All Rights Reserved
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose and without fee is hereby granted, provided that the above
 * copyright notice appear in all copies and that both the copyright
 * notice and this permission notice appear in supporting documentation,
 * and that the name of Silicon Graphics, Inc. not be used in
 * advertising or publicity pertaining to distribution of the software
 * without specific, written prior permission.
 *
 * THE MATERIAL EMBODIED ON THIS SOFTWARE IS PROVIDED TO YOU "AS-IS" AND
 * WITHOUT WARRANTY OF ANY KIND, EXPRESS, IMPLIED OR OTHERWISE,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY OR
 * FITNESS FOR A PARTICULAR PURPOSE.  IN NO EVENT SHALL SILICON
 * GRAPHICS, INC.  BE LIABLE TO YOU OR ANYONE ELSE FOR ANY DIRECT,
 * SPECIAL, INCIDENTAL, INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY KIND,
 * OR ANY DAMAGES WHATSOEVER, INCLUDING WITHOUT LIMITATION, LOSS OF
 * PROFIT, LOSS OF USE, SAVINGS OR REVENUE, OR THE CLAIMS OF THIRD
 * PARTIES, WHETHER OR NOT SILICON GRAPHICS, INC.  HAS BEEN ADVISED OF
 * THE POSSIBILITY OF SUCH LOSS, HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, ARISING OUT OF OR IN CONNECTION WITH THE POSSESSION, USE
 * OR PERFORMANCE OF THIS SOFTWARE.
 *
 * US Government Users Restricted Rights 
 * Use, duplication, or disclosure by the Government is subject to
 * restrictions set forth in FAR 52.227.19(c)(2) or subparagraph
 * (c)(1)(ii) of the Rights in Technical Data and Computer Software
 * clause at DFARS 252.227-7013 and/or in similar or successor clauses
 * in the FAR or the DOD or NASA FAR Supplement.  Unpublished - rights
 * reserved under the copyright laws of the United States.
 *
 * Contractor/manufacturer is:
 *	Silicon Graphics, Inc.
 *	1500 Crittenden Lane
 *	Mountain View, CA  94043
 *	United State of America
 *
 * OpenGL(R) is a registered trademark of Silicon Graphics, Inc.
 */

/*  rotatesphere.c, a variation of cubemap.c
 *
 * This demo shows the application of a texture to a lit sphere.
 *
 * Controls:
 *   w,x rotate up and down
 *   a,d rotate left and right
 *   f,b move the spehere along the z-axis (post rotation)
 *   r reset the sphere to the original location and orientation
 *   l Turns lighting on or off
 *
 */

#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

/* Texture map - the image size MUST be a power of 2 */
#define	imageSize 128
static GLubyte image[imageSize][imageSize][4];

/* lighting toggle */
static int is_lit;

/* Viewing params */
static GLdouble ztrans = 0.0;
float clockwise = 0.0;
float leftright = 0.0;

/* Sphere generator */
GLUquadricObj *gqu;

/* Sets up the texture image */
void makeImages(void)
{
   int i, j;
   int row, col;
   int k;
   for (i = 0; i < imageSize; i++) {
      for (j = 0; j < imageSize; j++) {
	      row = i / 4;
	      col = j / 4;
	      if((row % 2) != (col % 2)){
	         for(k=0;k<3;k++)
	            image[i][j][k] = 255;
	            image[i][j][3] = 255;
	      }
         else{
	            image[i][j][0] = 255 * (double)j / (double)imageSize;
	            image[i][j][1] = 255 - image[i][j][0];
	            image[i][j][2] = 255 * (double)i / (double)imageSize;
	         }
      }
   }
}

void init(void)
{
  /* Ambient and diffuse reflective property of the surface */
   GLfloat diffuse[4] = {1.0, 1.0, 1.0, 1.0};

   /* Basic setup stuff */
   // Set up backgound is black
   glClearColor (0.0, 0.0, 0.0, 0.0);
   // Enable Depth buffer
   glEnable(GL_DEPTH_TEST);
   // set shaing mode: smooth or flat
   glShadeModel(GL_SMOOTH);

   /* Set up the sphere generator */
   gqu = gluNewQuadric();
   gluQuadricDrawStyle(gqu, GLU_FILL);
   gluQuadricNormals(gqu, GLU_SMOOTH);
   gluQuadricTexture(gqu, GL_TRUE);

   /* Build the texture image and specify the application */
   makeImages();
   
   glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
   glEnable(GL_TEXTURE_2D);
   glBindTexture(GL_TEXTURE_2D, 1);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imageSize, imageSize, 0, 
		GL_RGBA, GL_UNSIGNED_BYTE, image);

   /* Setup lighting  and material properties */
   glEnable(GL_LIGHT0);
   /* GLfloat light_position[] = {set this up for the y-axis}; */
   /* glLightfv(GL_LIGHT0, , ); */
   GLfloat ambient[] = { 0.15, 0.15, 0.15, 1.0};
   glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);

   glMaterialfv (GL_FRONT, GL_AMBIENT_AND_DIFFUSE, diffuse);
   
   is_lit = 1;
}

void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   // Push the current matrix to stack
   glPushMatrix ();

   /* Set up the rotations and translations */
   glTranslatef(0.0, 0.0, ztrans);

   /* Turn on lighting if needed */
   if(is_lit)
     glEnable(GL_LIGHTING);
   else
     glDisable(GL_LIGHTING);

   /* Draw */
   gluSphere(gqu, 5.0, 15, 15);

   // Pop the curent matrix from stack
   glPopMatrix ();

   // swap buffer: called when in mode: GLUT_DOUBLE 
   glutSwapBuffers();
}

void reshape(int w, int h)
{
  /* Fill the whole window */
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);

   /* Setup a perspecive projection */
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(40.0, (GLfloat) w/(GLfloat) h, 1.0, 300.0);

   /* Reset the modelview matrix  & move so that the viewier is 20
    * units from the origin */
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef(0.0, 0.0, -20.0);
}


/* Handle keyboard input events */
void keyboard (unsigned char key, int x, int y)
{
   switch (key) {
      case 'f':
         ztrans = ztrans - 0.2;
         glutPostRedisplay();
         break;
      case 'b':
         ztrans = ztrans + 0.2;
         glutPostRedisplay();
         break;
/*    Set up more cases for rotating sphere cw, ccw, left and right */
/*    Increment variables (lines 69 & 70) by 1 or 2 degrees. */
      case 'r':
	      //leftright = 0.0;
	      //clockwise = 0.0;
	      //ztrans = 0.0;
         //gl Rotate float
         glRotatef(90.0, leftright, clockwise, ztrans);
	      //gluLookAt(1,1,1,1,1,1,1,1,1);
         glutPostRedisplay();
	      break;
      case 'l':
	      is_lit = is_lit?0:1;
	      glutPostRedisplay();
	      break;
      case 'q':
         exit(0);
         break;
      default:
         break;
   }
}

int main(int argc, char** argv)
{
   // Initialize the init function
   glutInit(&argc, argv);
   
   // GLUT_DOUBLE: use two buffer, one to visible, one to render
   // have to call "glutSwapBuffers()" function
   // GLUT_SINGLE: use one buffer, draw directly to display
   // things draw last in a frame are shown for a shorter time period
   // then objects at the beginning
   
   // GLUT_RGB: 
   // GLUT_DEPTH: The depth buffer is important for 3D graphics.
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   
   // Initialize a window with size 
   glutInitWindowSize(800, 800);
   
   // start position of window
   glutInitWindowPosition(100, 100);
   
   // title of window
   glutCreateWindow (argv[0]);
   
   // callback init function
   init ();
   
   // 
   glutDisplayFunc(display);
   
   glutReshapeFunc(reshape);
   
   glutKeyboardFunc(keyboard);
   
   glutMainLoop();
   return 0;
}


