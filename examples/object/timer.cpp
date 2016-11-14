/*
    ***** Objects3D *****

Display rotating 3-D objects (GLU quadrics and GLUT objects).
This file (timer.cpp) contains the idle and timer callbacks.

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

// idle callback, spins object about selected axis
void spinObject()
{
    theta[axis] += 1.0;
    if ( theta[axis] > 360.0 ) theta[axis] -= 360.0;
    glutPostRedisplay();
}

// timer callback, spins object about selected axis at specified rate
void spinTimer( int value )
{
    // animation callback
    spinObject();

    // call spinTimer() again in 'interval' milliseconds
    if ( value >= 0 )
        glutTimerFunc( interval, spinTimer, 0 );
    else
        glutTimerFunc( 1000000, spinTimer, -1 );
}
