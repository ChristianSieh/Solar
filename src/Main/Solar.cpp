/************************************************************************
   Program: Solar
   Author: Charles Bonn and Christian Sieh
   Class: CSC433 Computer Graphics
   Instructor: John Weiss
   Date:
   Description:    see read.me

Write a solar system simulation program that displays the Sun and the 
eight* planets, plus the Earth’s moon and the rings of Saturn. Animate
 this simulation so that the planets rotate about the Sun with correct 
speed  and  trajectory  relative  to  one  another. The user may zoom 
 in  or  out  of  the  scene, pan in all directions, and speed
 up or slow down the simulation

   Input: None
   Output:
   Compilation instructions: run make
   Usage:  go to builds and run Solar
   Known bugs/missing features: 
	- moon jumps around
	- saturn does not have rings
	- earth does not rotate
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

// Set initial size of display window
GLsizei ScreenWidth = 600, ScreenHeight = 600;

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
    glutMouseFunc( mouseclick );
    glutMotionFunc( mousedrag );
    createMenu();
    lightModel();

    // Start the main loop.  glutMainLoop never returns.
    glutMainLoop( );

    return 0;
}
