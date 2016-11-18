/************************************************************************
   Program: Solar
   Author: Charles Bonn and Christian Sieh
   Class: CSC433 Computer Graphics
   Instructor: John Weiss
   Date:
   Description:    (program requirements)
   Input: None
   Output:
   Compilation instructions:
   Usage:
   Known bugs/missing features:
   Modifications:
   Date                Comment            
   ----    ------------------------------------------------
 ************************************************************************/


#include "Gen.h"
#include "Main.h"

#include <typeinfo>

/*********************** global symbolic constants *********************/
//shape 
vector<Shape*> shapeList;

//global rotation info
GLfloat theta[] = { 0.0, 0.0, 0.0 };
GLint axis = 2;

bool solid = false;
bool smooth = false;
bool texture = false;

/*********************** function prototypes ***************************/
void OpenGLInit( void );


/************************************************************************
   Function: OpenGLInit
   Author: Charles Bonn and Christian Sieh
   Description: initilization of opengl
   Parameters:
 ************************************************************************/
void OpenGLInit( void )
{
    glShadeModel( GL_FLAT );
    glClearColor( 0.0, 0.0, 0.0, 0.0 );
    glClearDepth( 1.0 );
    glEnable( GL_DEPTH_TEST );
    glEnable( GL_NORMALIZE );
    glEnable( GL_CULL_FACE );
    glCullFace( GL_BACK );

}

/************************************************************************
   Function: main
   Author: Charles Bonn and Christian Sieh
   Description: main loop and set up of opengl function call backs
   Parameters: 
	argc - number of arguments
	argv - argument list
 ************************************************************************/
int main( int argc, char** argv )
{
    // Need to double buffer for animation
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_MULTISAMPLE );

    // Create and position the graphics window
    glutInitWindowPosition( 0, 0 );
    glutInitWindowSize( 600, 360 );
    glutCreateWindow( "Solar System Demo" );

    //set planets
    generate(shapeList);

    // Initialize OpenGL.
    OpenGLInit();

    // Set up callback functions f
    glutKeyboardFunc( KeyPressFunc );
    glutSpecialFunc( SpecialKeyFunc );
    glutReshapeFunc( ResizeWindow );
    glutDisplayFunc( Animate );
    createMenu();
    lightModel();

    // Start the main loop.  glutMainLoop never returns.
    glutMainLoop( );

    return 0;
}
