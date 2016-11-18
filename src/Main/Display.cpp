 /************************************************************************
   Program: Solar
   Author: Charles Bonn and Christian Sieh
   Date:
   Description:    (program requirements)
   Known bugs/missing features:
   Modifications:
   Date                Comment            
   ----    ------------------------------------------------
 ************************************************************************/

#include "Main.h"

/*********************** global symbolic constants *********************/
// look at controls the camra
cell lookat[9] = {
    { 1, 180, 120, -2300.0, 2300.0, 0.0, 0.5,
    "Specifies the X position of the eye point.", "%.2f" },
    { 2, 240, 120, -2300.0, 2300.0, 0.0, 0.5,
    "Specifies the Y position of the eye point.", "%.2f" },
    { 3, 300, 120, 28.0, 3500.0, 3000.0, 0.5,
    "Specifies the Z position of the eye point.", "%.2f" },
    { 4, 180, 160, -2300.0, 3000.0, 0.0, 0.5,
    "Specifies the X position of the reference point.", "%.2f" },
    { 5, 240, 160, -5.0, 5.0, 0.0, 0.1,
    "Specifies the Y position of the reference point.", "%.2f" },
    { 6, 300, 160, -5.0, 5.0, 0.0, 0.1,
    "Specifies the Z position of the reference point.", "%.2f" },
    { 7, 180, 200, -2.0, 2.0, 0.0, 0.1,
    "Specifies the X direction of the up vector.", "%.2f" },
    { 8, 240, 200, -2.0, 2.0, 1.0, 0.1,
    "Specifies the Y direction of the up vector.", "%.2f" },
    { 9, 300, 200, -2.0, 2.0, 0.0, 0.1,
    "Specifies the Z direction of the up vector.", "%.2f" },
};

// perspective controls the view of the camera
cell perspective[4] = {
    { 10, 180, 80, 60.0, 180.0, 60.0, 1.0,
        "Specifies field of view angle (in degrees) in y direction.", "%.1f" },
    { 11, 240, 80, -3.0, 3.0, 1.0, 0.01,
    "Specifies field of view in x direction (width/height).", "%.2f" },
    { 12, 300, 80, 0.1, 10.0, 1.0, 0.05,
    "Specifies distance from viewer to near clipping plane.", "%.1f" },
    { 13, 360, 80, 0.1, 10.0, 3800.0, 0.05,
    "Specifies distance from viewer to far clipping plane.", "%.1f" },
};

GLdouble projection[16], modelview[16];
//animate booleans
GLenum spinMode = GL_TRUE;
GLenum singleStep = GL_FALSE;
GLenum viewMode = GL_TRUE;

float HourOfDay = 0.0;
float currDay = 0.0;
float AnimateIncrement = 24.0; 

/************************************************************************
   Function: Animate
   Author:
   Description: main display loop of the program. handles redrawing the window
	and the graphical contents
   Parameters: void
 ************************************************************************/
void Animate( void )
{
    glEnable(GL_MULTISAMPLE);

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

   // glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

  
 
    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();

    gluLookAt(lookat[0].value, lookat[1].value, lookat[2].value,
        lookat[3].value, lookat[4].value, lookat[5].value,
        lookat[6].value, lookat[7].value, lookat[8].value); 
     glGetDoublev(GL_MODELVIEW_MATRIX, modelview); 

   // glMatrixMode(GL_MODELVIEW);
   // glLoadIdentity();
   // glEnable(GL_DEPTH_TEST);

    if(smooth)
        glShadeModel(GL_SMOOTH);
    else
        glShadeModel(GL_FLAT);

    if(texture)
    {
        glEnable( GL_TEXTURE_2D );

        for(auto & obj: shapeList)
        {
            int err = obj->drawImg();
            if(err == -1)
            {
                obj->drawSolid();
            }
        }
    }
    else
    {
        if(solid)
        {
            for(auto & obj: shapeList)
            {
                obj->drawSolid();
            }
        }
        else
        {
            for(auto & obj: shapeList)
            {
	            obj->drawWireFrame();
            }
        }
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

 /************************************************************************
   Function: ResizeWindow
   Author: Charles Bonn and Christian Sieh
   Description: Handles the resizing of the graphical window
   Parameters:
	int w - width of the window
	int h - height of the window
 ************************************************************************/
void ResizeWindow( int w, int h )
{
    h = ( h == 0 ) ? 1 : h;
    w = ( w == 0 ) ? 1 : w;
    glViewport( 0, 0, w, h );	// View port uses whole window
    perspective[1].value = ( float ) w / ( float ) h;

    // Set up the projection view matrix (not very well!)
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

    //change the perspective of the camera
    gluPerspective(perspective[0].value, perspective[1].value, 
        perspective[2].value, perspective[3].value);
    glGetDoublev(GL_PROJECTION_MATRIX, projection);

    // Select the Modelview matrix
    glMatrixMode( GL_MODELVIEW );

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0); 
}
 /************************************************************************
   Function: lightModel
   Author: Charles Bonn and Christian Sieh
   Description: set up and handles light and material properties
   Parameters:
 ************************************************************************/
void lightModel()
{    
    // specify light source properties
    GLfloat light_position[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_ambient[] = { 0.4, 0.4, 0.4, 1.0 };       // ambient light
    GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };       // diffuse light
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };      // highlights

    glEnable( GL_LIGHT0 );      // enable one light source
    glLightfv( GL_LIGHT0, GL_POSITION, light_position );
    glLightfv( GL_LIGHT0, GL_AMBIENT, light_ambient );
    glLightfv( GL_LIGHT0, GL_DIFFUSE, light_diffuse );
    glLightfv( GL_LIGHT0, GL_SPECULAR, light_specular );

    glEnable(GL_LIGHTING);
    glCullFace( GL_BACK );
}
