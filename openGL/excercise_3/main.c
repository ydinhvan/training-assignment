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

/* normal vector toggle */
static int is_nout;

/* Viewing params */
static GLdouble ztrans = 0.0;
float clockwise = 0.0;
float leftright = 0.0;

/* Setup tga texture files, only 1 initially */
#define SPHERE_TEXTURE  0
#define NUM_TEXTURES    1
GLuint  textureObjects[NUM_TEXTURES];
const char *szTextureFiles[] = {"Sky320by240.tga"};

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
	}else{
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
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glEnable(GL_DEPTH_TEST);
   glShadeModel(GL_SMOOTH);

   /* Set up the sphere generator */
   gqu = gluNewQuadric();
   gluQuadricDrawStyle(gqu, GLU_FILL);
   gluQuadricNormals(gqu, GLU_SMOOTH);
   gluQuadricTexture(gqu, GL_TRUE);

   /* Build the texture image and specify the application
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
		GL_RGBA, GL_UNSIGNED_BYTE, image); */

   /* Alternatively, set up tga texture map */
    int i;
    glEnable(GL_TEXTURE_2D);
    glGenTextures(NUM_TEXTURES, textureObjects);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    
    
    for(i = 0; i < NUM_TEXTURES; i++)
        {
        GLubyte *pBytes;
        GLint iWidth, iHeight, iComponents;
        GLenum eFormat;
        
        glBindTexture(GL_TEXTURE_2D, textureObjects[i]);
        
        // Load this texture map
        pBytes = gltLoadTGA(szTextureFiles[i], &iWidth, &iHeight, &iComponents, &eFormat);
        gluBuild2DMipmaps(GL_TEXTURE_2D, iComponents, iWidth, iHeight, eFormat, GL_UNSIGNED_BYTE, pBytes);
        free(pBytes);
        
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        }


   /* Setup lighting  and material properties */
   glEnable(GL_LIGHT0);
   GLfloat light_position[] = {0.0, 1.0, 0.0, 0.0}; 
   glLightfv(GL_LIGHT0, GL_POSITION, light_position); 
   GLfloat ambient[] = { 0.15, 0.15, 0.15, 1.0};
   glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);

   glMaterialfv (GL_FRONT, GL_AMBIENT_AND_DIFFUSE, diffuse);
   
   is_lit = 1;
}

void deinit(void)
{
   glDeleteTextures(NUM_TEXTURES, textureObjects);
}


void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   glPushMatrix ();

   /* Set up the rotations and translations */
   glTranslatef(0.0, 0.0, ztrans);
   glRotatef (clockwise, 0.0,0.0,1.0);
   glRotatef(leftright,0.0,1.0,0.0);
   //gluLookAt(0.0, 20.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);
   
   /* Turn on lighting if needed */
   if(is_lit)
     glEnable(GL_LIGHTING);
   else
     glDisable(GL_LIGHTING);

   /* Draw */
   gluSphere(gqu, 5.0, 15, 15);

   glPopMatrix ();
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
	leftright = 0.0;
	clockwise = 0.0;
	ztrans = 0.0;
	glutPostRedisplay();
	break;
      case 'l':
	is_lit = is_lit?0:1;
	glutPostRedisplay();
	break;
	case 'n':
	is_nout = is_nout?0:1;
	glutPostRedisplay();
	break;
      case 'q':
         exit(0);
         break;
      case 'w':
	 clockwise += 10.0;
	 glutPostRedisplay();
	 break;
      case 'x':
	 clockwise -= 10.0;
         glutPostRedisplay();
	 break;
      case 'a':
	 leftright += 10;
	 glutPostRedisplay();
	 break;
      case 'd':
	 leftright -= 10;
	 glutPostRedisplay();
	 break;
      default:
         break;
   }
}

// LoadTGA.c
// Loads a Targa file for OpenGL
// Richard S. Wright Jr.
// OpenGL SuperBible
// This really only works with 24/32/8 bit targas


// Define targa header.
#pragma pack(1)
typedef struct
    {
    GLbyte	identsize;              // Size of ID field that follows header (0)
    GLbyte	colorMapType;           // 0 = None, 1 = paletted
    GLbyte	imageType;              // 0 = none, 1 = indexed, 2 = rgb, 3 = grey, +8=rle
    unsigned short	colorMapStart;          // First colour map entry
    unsigned short	colorMapLength;         // Number of colors
    unsigned char 	colorMapBits;   // bits per palette entry
    unsigned short	xstart;                 // image x origin
    unsigned short	ystart;                 // image y origin
    unsigned short	width;                  // width in pixels
    unsigned short	height;                 // height in pixels
    GLbyte	bits;                   // bits per pixel (8 16, 24, 32)
    GLbyte	descriptor;             // image descriptor
    } TGAHEADER;
#pragma pack(8)



////////////////////////////////////////////////////////////////////
// Allocate memory and load targa bits. Returns pointer to new buffer,
// height, and width of texture, and the OpenGL format of data.
// Call free() on buffer when finished!
// This only works on pretty vanilla targas... 8, 24, or 32 bit color
// only, no palettes, no RLE encoding.
GLbyte *gltLoadTGA(const char *szFileName, GLint *iWidth, GLint *iHeight, GLint *iComponents, GLenum *eFormat)
    {
    FILE *pFile;			// File pointer
    TGAHEADER tgaHeader;		// TGA file header
    unsigned long lImageSize;		// Size in bytes of image
    short sDepth;			// Pixel depth;
    GLbyte	*pBits = NULL;          // Pointer to bits
    
    // Default/Failed values
    *iWidth = 0;
    *iHeight = 0;
    *eFormat = GL_BGR_EXT;
    *iComponents = GL_RGB8;
    
    // Attempt to open the fil
    pFile = fopen(szFileName, "rb");
    if(pFile == NULL)
        return NULL;
        
    // Read in header (binary)
    fread(&tgaHeader, 18/* sizeof(TGAHEADER)*/, 1, pFile);
    
    // Do byte swap for big vs little endian
#ifdef __APPLE__
    BYTE_SWAP(tgaHeader.colorMapStart);
    BYTE_SWAP(tgaHeader.colorMapLength);
    BYTE_SWAP(tgaHeader.xstart);
    BYTE_SWAP(tgaHeader.ystart);
    BYTE_SWAP(tgaHeader.width);
    BYTE_SWAP(tgaHeader.height);
#endif

        
    // Get width, height, and depth of texture
    *iWidth = tgaHeader.width;
    *iHeight = tgaHeader.height;
    sDepth = tgaHeader.bits / 8;
    
    // Put some validity checks here. Very simply, I only understand
    // or care about 8, 24, or 32 bit targa's.
    if(tgaHeader.bits != 8 && tgaHeader.bits != 24 && tgaHeader.bits != 32)
        return NULL;

    // Calculate size of image buffer
    lImageSize = tgaHeader.width * tgaHeader.height * sDepth;
    
    // Allocate memory and check for success
    pBits = malloc(lImageSize * sizeof(GLbyte));
    if(pBits == NULL)
        return NULL;
    
    // Read in the bits
    // Check for read error. This should catch RLE or other 
    // weird formats that I don't want to recognize
    if(fread(pBits, lImageSize, 1, pFile) != 1)
        {
        free(pBits);
        return NULL;
        }
    
    // Set OpenGL format expected
    switch(sDepth)
        {
        case 3:     // Most likely case
            *eFormat = GL_BGR_EXT;
            *iComponents = GL_RGB8;
            break;
        case 4:
            *eFormat = GL_BGRA_EXT;
            *iComponents = GL_RGBA8;
            break;
        case 1:
            *eFormat = GL_LUMINANCE;
            *iComponents = GL_LUMINANCE8;
            break;
        };
        
    
    // Done with File
    fclose(pFile);
        
    // Return pointer to image data
    return pBits;
    }

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize(400, 400);
   glutInitWindowPosition(100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   deinit();
   return 0;
}

