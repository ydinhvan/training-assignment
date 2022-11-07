INCLUDE = -I/usr/X11R6/include/
LIBDIR  = -L/usr/lib -L/usr/X11R6/lib

COMPILERFLAGS = -Wall
CC = gcc
CFLAGS = $(COMPILERFLAGS) $(INCLUDE)
LIBRARIES = -lX11 -lXi -lXmu -lglut -lGL -lGLU -lm

All:rotatesphere

rotatesphere:rotatesphere.o
	$(CC) $(CFLAGS) -o $@ $(LIBDIR) $< $(LIBRARIES)

#gcc -o app main.c -lXmu -lX11 -lXi -lGL -lGLU -lglut -lm
