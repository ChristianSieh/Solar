/*
    ***** Objects3D *****

Display rotating 3-D objects (GLU quadrics and GLUT objects).
This file (events.cpp) contains the user input event callbacks (keyboard and mouse).

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

// keyboard callback (spacebar to toggle animation, +/- to change shape, etc.)
void key( unsigned char ch, int x, int y )
{
    static bool anim = true, lighting = false, shading = false, solid = false;

    switch ( ch )
    {
        // toggle animation (spacebar)
        case ' ':
        case 'a':
            // ( anim = !anim ) ? glutIdleFunc( spinObject ) : glutIdleFunc( NULL );
            if ( anim = !anim )
                glutTimerFunc( interval, spinTimer, 0 );
            else
                glutTimerFunc( 1000000, spinTimer, -1 );
            break;

        // select axis of rotation
        case 'x': case 'X': axis = 0; break;
        case 'y': case 'Y': axis = 1; break;
        case 'z': case 'Z': axis = 2; break;

        // animation speed
        case '+': case '=':
            interval /= 2;
            // if ( interval < 0 ) interval = 0;
            break;
        case '-':
            if ( interval <= 0 )
                interval = 1;
            else
                interval *= 2;
            break;

        // toggle lighting model
        case 'l': case 'L':
            ( lighting = !lighting ) ? glEnable( GL_LIGHTING ) : glDisable( GL_LIGHTING );
            break;

        // flat vs. smooth shading
        case 's': case 'S':
            ( shading = !shading ) ? glShadeModel( GL_SMOOTH ) : glShadeModel( GL_FLAT );
            break;

        // wireframe vs. solid object
        case 'w': case 'W':
            solid = !solid;
            if ( solid )
            {
                glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
                gluQuadricDrawStyle( object, GLU_FILL );
            }
            else
            {
                glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
                gluQuadricDrawStyle( object, GLU_LINE );
           }
            break;

        // Esc key exits
        case 27:
            exit( 0 );
            break;
    }

    glutPostRedisplay();
}

// special key callback (arrow keys to change shape, etc.)
void special( int key, int x, int y )
{
    int nObjType = int( SOLID_TEAPOT );     // last shape

    // process keypresses
    switch ( key )
    {
        case GLUT_KEY_LEFT:
        case GLUT_KEY_DOWN:
            objtype = ObjType( int( objtype ) - 1 );
            if ( objtype < 0 ) objtype = ObjType( nObjType );
            break;
        case GLUT_KEY_RIGHT:
        case GLUT_KEY_UP:
            objtype = ObjType( int( objtype ) + 1 );
            if ( objtype > nObjType ) objtype = ObjType( 0 );
            break;
    }
    glutPostRedisplay();
}

// mouse callback, selects axis of rotation (not currently enabled)
void mouse( int btn, int state, int x, int y )
{
    if ( btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN ) axis = 0;
    if ( btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN ) axis = 1;
    if ( btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN ) axis = 2;
}
