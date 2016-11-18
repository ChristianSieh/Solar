/*
    ***** Objects3D *****

Display rotating 3-D objects (GLU quadrics and GLUT objects).
This file (display.cpp) contains the display and reshape callbacks.

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

/******************************************************************************/

// window resizing callback
// stretch objects to window, but retain aspect ratio
void reshape( int w, int h )
{
    glViewport( 0, 0, w, h );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    if ( w <= h )
        glOrtho( -2.0, 2.0,
                 -2.0 * ( GLfloat ) h / ( GLfloat ) w, 2.0 * ( GLfloat ) h / ( GLfloat ) w,
                 -10.0, 10.0 );
    else
        glOrtho( -2.0 * ( GLfloat ) w / ( GLfloat ) h, 2.0 * ( GLfloat ) w / ( GLfloat ) h,
                 -2.0, 2.0,
                 -10.0, 10.0 );
    glMatrixMode( GL_MODELVIEW );
}

/******************************************************************************/

// display callback
void display( void )
{
    // clear frame buffer and z buffer
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    // rotate object
    glLoadIdentity();
    glRotatef( theta[0], 1.0, 0.0, 0.0 );
    glRotatef( theta[1], 0.0, 1.0, 0.0 );
    glRotatef( theta[2], 0.0, 0.0, 1.0 );

    // redraw object
    switch ( objtype )
    {
        // GLU quadrics
        case SPHERE:
            gluSphere( object, 1.0, 32, 32 );
            break;
        case CYLINDER:
            gluCylinder( object, 1.1, 1.2, 0.0, 32, 32 );
            break;
        case DISK:
            gluDisk( object, 0.2, 0.8, 32, 32 );
            break;
            
        // GLUT objects
        case WIRE_SPHERE:
            glutWireSphere( 1.0, 32, 32 );
            break;
        case SOLID_SPHERE:
            glutSolidSphere( 1.0, 32, 32 );
            break;
        case WIRE_CONE:
            glutWireCone( 1.0, 1.0, 32, 32 );
            break;
        case SOLID_CONE:
            glutSolidCone( 1.0, 1.0, 32, 32 );
            break;
        case WIRE_TORUS:
            glutWireTorus( 0.2, 0.8, 32, 32 );
            break;
        case SOLID_TORUS:
            glutSolidTorus( 0.2, 0.8, 32, 32 );
            break;
        case WIRE_TETRAHEDRON:
            glutWireTetrahedron();
            break;
        case SOLID_TETRAHEDRON:
            glutSolidTetrahedron();
            break;
        case WIRE_OCTAHEDRON:
            glutWireOctahedron();
            break;
        case SOLID_OCTAHEDRON:
            glutSolidOctahedron();
            break;
        case WIRE_DODECAHEDRON:
            glutWireDodecahedron();
            break;
        case SOLID_DODECAHEDRON:
            glutSolidDodecahedron();
            break;
        case WIRE_ICOSAHEDRON:
            glutWireIcosahedron();
            break;
        case SOLID_ICOSAHEDRON:
            glutSolidIcosahedron();
            break;
            
        // front facing polygons should have vertices that wind counter clockwise
        // apparently the Utah Teapot has vertices winding clockwise
        case WIRE_TEAPOT:
            glFrontFace( GL_CW );
            glutWireTeapot( 1.0 );
            glFrontFace( GL_CCW );
            break;
        case SOLID_TEAPOT:
            glFrontFace( GL_CW );
            glutSolidTeapot( 1.0 );
            glFrontFace( GL_CCW );
            break;
    }

    // double buffering for animation (implicitly calls glFlush)
    glutSwapBuffers();
}
