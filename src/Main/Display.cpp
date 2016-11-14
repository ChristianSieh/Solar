#include "Main.h"

// Animate() handles the animation and the redrawing of the graphics window contents.
void Animate( void )
{
    // Clear the redering window
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    if ( spinMode )
    {
        // Update the animation state
        HourOfDay += AnimateIncrement;
        currDay += AnimateIncrement / 24.0;

        HourOfDay = HourOfDay - ( ( int ) ( HourOfDay / 24 ) ) * 24;
        currDay = currDay - ( ( int ) ( currDay / 365 ) ) * 365;
    }

    // Clear the current matrix (Modelview)
    glLoadIdentity();

    // Back off eight units to be able to view from the origin.
    glTranslatef ( 0.0, 0.0, -18.0 );

    // Rotate the plane of the elliptic
    // (rotate the model's plane about the x axis by fifteen degrees)
    glRotatef( theta[0], 1.0, 0.0, 0.0 );
    glRotatef( theta[1], 0.0, 1.0, 0.0 );
    glRotatef( theta[2], 0.0, 0.0, 1.0 );

    for(auto & obj: shapeList)
    {
	obj->drawWireFrame();
    }
    // Flush the pipeline, and swap the buffers
    glFlush();
    glutSwapBuffers();

    if ( singleStep )
    {
        spinMode = GL_FALSE;
    }

    glutPostRedisplay();		// Request a re-draw for animation purposes
}

void ResizeWindow( int w, int h )
{
    float aspectRatio;
    h = ( h == 0 ) ? 1 : h;
    w = ( w == 0 ) ? 1 : w;
    glViewport( 0, 0, w, h );	// View port uses whole window
    aspectRatio = ( float ) w / ( float ) h;

    // Set up the projection view matrix (not very well!)
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective( 60.0, aspectRatio, 1.0, 30.0 );

    // Select the Modelview matrix
    glMatrixMode( GL_MODELVIEW );
}
