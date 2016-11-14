/*
    ***** Objects3D *****

Display rotating 3-D objects (GLU quadrics and GLUT objects).
This file (main.cpp) contains the main function.

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

#include "objects.h"

ObjType objtype = SPHERE;
GLUquadricObj* object;

// global rotation info
GLfloat theta[] = { 0.0, 0.0, 0.0 };
GLint axis = 2;

// animation timer interval (msec)
int interval = 16;

/******************************************************************************/

// main function
int main( int argc, char **argv )
{
    // GLUT inits: need both double buffering and z buffer
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );
    glutInitWindowSize( 500, 500 );
    glutCreateWindow( "OpenGL 3-D Objects" );

    // callbacks
    glutReshapeFunc( reshape );
    glutDisplayFunc( display );
    glutKeyboardFunc( key );
    glutSpecialFunc( special );             // how to handle "special" key presses
    glutMouseFunc( mouse );

    // set up illumination-reflectance model
    lightModel();

    // generate GLU quadric object with surface normals
    object = gluNewQuadric( );
    gluQuadricNormals( object, GLU_SMOOTH );
    gluQuadricDrawStyle( object, GLU_LINE );

    // handle animation
    // glutIdleFunc( spinObject );
    if ( argc > 1 ) interval = atoi( argv[1] );
    glutTimerFunc( interval, spinTimer, 0 );               // timer callback

    // event loop
    glutMainLoop();
}
