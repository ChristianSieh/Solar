# Makefile for OpenGL/GLUT programs.

# Author: John M. Weiss, Ph.D.
# Written Fall 2016 for CSC433/533 Computer Graphics.

# Usage:  make target1 target2 ...

#-----------------------------------------------------------------------

# GNU C/C++ compiler and linker:
CC = gcc
CXX = g++
LINK = g++

# Turn on optimization and warnings (add -g for debugging with gdb):
# CPPFLAGS = 		# preprocessor flags
CFLAGS = -O -Wall
CXXFLAGS = -O -Wall

# OpenGL/Mesa libraries for Linux:
GL_LIBS = -lglut -lGLU -lGL -lm

# OpenGL libraries for Windows (MinGW):
# GL_LIBS = -lfreeglut -lglu32 -lopengl32
# GL_LIBS = -lglut32 -lglu32 -lopengl32

# OpenGL libraries for Windows (MSVS):
# GL_LIBS = opengl32.lib glu32.lib freeglut.lib
# GL_LIBS = opengl32.lib glu32.lib glut32.lib

SRC = display.cpp events.cpp lighting.cpp main.cpp timer.cpp
OBJ = display.o events.o lighting.o main.o timer.o

#-----------------------------------------------------------------------

# MAKE allows the use of "wildcards", to make writing compilation instructions
# a bit easier. GNU make uses $@ for the target and $^ for the dependencies.

# specific targets
Object3D:	$(OBJ)
	$(LINK) -o $@ $^ $(GL_LIBS)

# generic C and C++ targets for OpenGL programs consisting of only one file
# type "make filename" (no extension) to build
.c:
	$(CC) -o $@ $@.c $(CFLAGS) $(GL_LIBS)

.cpp:
	$(CXX) -o $@ $@.cpp $(CXXFLAGS) $(GL_LIBS)

# utility targets
clean:
	rm -f *.o *~ core
