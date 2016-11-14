/*
    ***** Objects3D *****

Display rotating 3-D objects (GLU quadrics and GLUT objects).
This file (lighting.cpp) contains the material properties and lighting models.

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

// set up light and material properties
void lightModel()
{
    // specify material reflectivity
    GLfloat mat_ambient[] = { 0.0, 0.0, 1.0, 1.0 };     // blue ambient reflectivity
    GLfloat mat_diffuse[] = { 0.0, 1.0, 0.0, 1.0 };     // green diffuse reflectivity
    GLfloat mat_specular[] = { 1.0, 0.0, 0.0, 1.0 };    // red highlights
    GLfloat mat_shininess = { 100.0 };
    
    glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient );
    glMaterialfv( GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse );
    glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular );
    glMaterialf( GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess );
    
    // specify light source properties
    GLfloat light_position[] = { 10.0, 10.0, 10.0, 1.0 };
    GLfloat light_ambient[] = { 0.4, 0.4, 0.4, 1.0 };       // ambient light
    GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };       // diffuse light
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };      // highlights

    glEnable( GL_LIGHT0 );      // enable one light source
    glLightfv( GL_LIGHT0, GL_POSITION, light_position );
    glLightfv( GL_LIGHT0, GL_AMBIENT, light_ambient );
    glLightfv( GL_LIGHT0, GL_DIFFUSE, light_diffuse );
    glLightfv( GL_LIGHT0, GL_SPECULAR, light_specular );

    glShadeModel( GL_FLAT );    // start with flat shading (smooth is default)

    glEnable( GL_DEPTH_TEST );  // enable depth buffer for hidden-surface elimination
    glEnable( GL_NORMALIZE );   // automatic normalization of normals
    glEnable( GL_CULL_FACE );   // eliminate backfacing polygons
    glCullFace( GL_BACK );
    // glLightModeli( GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE );   // render back faces

    glClearColor( 0.0, 0.0, 0.0, 1.0 );     // black background
    glColor3f ( 0.8, 0.8, 0.0 );            // draw in yellow
}
