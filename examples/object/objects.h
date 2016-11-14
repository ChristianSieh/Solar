/*
    ***** Objects3D *****

Display rotating 3-D objects (GLU quadrics and GLUT objects).
This file (objects.h) contains typical header info (function prototypes etc.).

Key controls:
1) arrow keys: select different objects
2) w: toggle wireframe or solid object rendering
3) l: toggle lighting model
4) s: toggle flat or smooth shading
5) spacebar: should toggle animation :-(
6) +/-: change animation speed
7) x/y/z (also mouse buttons) select axis of rotation


Author: John M. Weiss, Ph.D.
Class:  CSC433/533 Computer Graphics
Date:   Fall 2016
Ref:    Angel, OpenGL Primer, 2008.

*/

#include <stdlib.h>
#include <GL/freeglut.h>

// global object info
enum ObjType { SPHERE, CYLINDER, DISK,
    WIRE_SPHERE, SOLID_SPHERE, WIRE_CONE, SOLID_CONE, WIRE_TORUS, SOLID_TORUS,
    WIRE_TETRAHEDRON, SOLID_TETRAHEDRON, WIRE_OCTAHEDRON, SOLID_OCTAHEDRON,
    WIRE_DODECAHEDRON, SOLID_DODECAHEDRON, WIRE_ICOSAHEDRON, SOLID_ICOSAHEDRON,
    WIRE_TEAPOT, SOLID_TEAPOT };

extern ObjType objtype;
extern GLUquadricObj* object;

// global rotation info
extern GLfloat theta[];
extern GLint axis;

// animation timer interval (msec)
extern int interval;

void reshape( int w, int h );
void display( void );
void spinObject();
void spinTimer( int value );
void key( unsigned char ch, int x, int y );
void special( int key, int x, int y );
void mouse( int btn, int state, int x, int y );
void lightModel();
