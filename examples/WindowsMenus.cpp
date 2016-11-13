/*
                    ***** WindowsMenus.cpp *****

Example of multiple windows and submenus in OpenGL.
Draws rubberbanded rectangle with left mouse button.
Pops up menu with right mouse button.
Echos keystrokes and menu selections to stdout.

Note that there is only one set of rectangle coordinates,
so resizing only one window give funky results in the other.

Author: John M. Weiss, Ph.D.
Course: CSC433/533 Computer Graphics - Fall 2016

Modifications:
*/

/******************************************************************************/

// include files
#include <iostream>
using namespace std;

// use OpenGL graphics and the GLUT graphical user interface
#include <GL/freeglut.h>

// constants
const int EscapeKey = 27;

/******************************************************************************/

// global vars (rectangle corners)
int startx, starty, endx, endy;
int WindowHeight = 400;

// function prototypes
void DrawRectangle( int x1, int y1, int x2, int y2, const float color[] );
void MainMenuHandler( int item );
void SubMenuHandler( int item );
void CreateMenus();

// GLUT callbacks
void display1();
void display2();
void reshape( int w, int h );
void keyboard1( unsigned char key, int x, int y );
void keyboard2( unsigned char key, int x, int y );
void mouseclick( int button, int state, int x, int y );
void mousedrag( int x, int y );

/******************************************************************************/

// main() function
int main( int argc, char *argv[] )
{
    // initialize OpenGL and GLUT
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );

    // create first window
    glutInitWindowSize( 400, 400 );
    glutInitWindowPosition( 0, 100 );
    int win1 = glutCreateWindow( "Window 1" );

    // window 1 callbacks
    glutDisplayFunc( display1 );
    glutReshapeFunc( reshape );
    glutKeyboardFunc( keyboard1 );
    glutMouseFunc( mouseclick );
    glutMotionFunc( mousedrag );

    // create menus
    CreateMenus();

    // create second window
    glutInitWindowSize( 400, 400 );
    glutInitWindowPosition( 500, 100 );
    int win2 = glutCreateWindow( "Window 2" );

    // window 2 callbacks
    glutDisplayFunc( display2 );
    glutReshapeFunc( reshape );
    glutKeyboardFunc( keyboard2 );
    glutMouseFunc( mouseclick );
    glutMotionFunc( mousedrag );

    // create menus
    CreateMenus();

    // use black as clear color
    glClearColor( 0.0, 0.0, 0.0, 1.0 );

    // go into OpenGL/GLUT main loop, never to return
    glutMainLoop(  );

    return 0;
}

/******************************************************************************/
/*                          OpenGL callback functions                         */
/******************************************************************************/

// callback function that tells OpenGL how to redraw window 1
void display1()
{
    // redraw the rectangle in yellow
    glClear( GL_COLOR_BUFFER_BIT );
    glColor3f( 1.0, 1.0, 0.0 );
    glRecti( startx, starty, endx, endy );
    glFlush();
    glutSwapBuffers();
}

// callback function that tells OpenGL how to redraw window 2
void display2()
{
    // redraw the rectangle in cyan
    glClear( GL_COLOR_BUFFER_BIT );
    glColor3f( 0.0, 1.0, 1.0 );
    glRecti( startx, starty, endx, endy );
    glFlush();
    glutSwapBuffers();
}

// callback function that tells OpenGL how to resize either window
void reshape( int w, int h )
{
    glViewport( 0, 0, w, h );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D( 0.0, w, 0.0, h );
    
    WindowHeight = h;
}

// callback function that tells OpenGL how to handle keystrokes in window 1
void keyboard1( unsigned char key, int x, int y )
{
    switch ( key )
    {
        case EscapeKey:
            exit( 0 );
            break;
        default:
            cout << "You pressed key " << key << " in window 1\n";
            break;
    }
}

// callback function that tells OpenGL how to handle keystrokes in window 2
void keyboard2( unsigned char key, int x, int y )
{
    switch ( key )
    {
        case 'q':
            exit( 0 );
            break;
        default:
            cout << "You pressed key " << key << " in window 2\n";
            break;
    }
}

// callback function for mouse button click events in either window
// left button press starts drawing a rectangle in selected window
void mouseclick( int button, int state, int x, int y )
{
    // handle mouse clicks
    switch ( button )
    {
        case GLUT_LEFT_BUTTON:				    // left button: create objects
            if ( state == GLUT_DOWN )			// press - new start point
            {
                startx = x;				        // store start coordinates
                starty = WindowHeight - y;		// correct for upside-down screen coordinates
            }
            break;

        case GLUT_MIDDLE_BUTTON:			    // middle button: not used
            break;

        case GLUT_RIGHT_BUTTON:				    // right button: not used
            break;
    }
}

// callback function for mouse dragging events in either window
// left button drag rubberbands a rectangle in selected window
void mousedrag( int x, int y )
{
    endx = x;
    endy = WindowHeight - y;				    // correct for upside-down screen coordinates
    glutPostRedisplay();
}

// CreateMenus() creates the right mouse button menu
void CreateMenus()
{
    // create submenu
    int value = 1;
    int submenu = glutCreateMenu( SubMenuHandler );
    cout << "submenu id = " << submenu << endl;
    glutAddMenuEntry( "sub 1", value++ );
    glutAddMenuEntry( "sub 2", value++ );
    glutAddMenuEntry( "sub 3", value++ );
    glutAddMenuEntry( "sub 4", value++ );

    // create main menu
    value = 1;
    int mainmenu = glutCreateMenu( MainMenuHandler );
    cout << "mainmenu id = " << mainmenu << endl;
    glutAddMenuEntry( "main 1", value++ );
    glutAddMenuEntry( "main 2", value++ );
    glutAddMenuEntry( "main 3", value++ );
    glutAddMenuEntry( "main 4", value++ );
    glutAddSubMenu( "submenu", submenu );
    glutAddMenuEntry( "Exit (Esc)", value++ );

    // right button click activates menu
    glutAttachMenu( GLUT_RIGHT_BUTTON );
}

// MainMenuHandler() controls the main menu
// only action is to print selected menu entry
void MainMenuHandler( int item )
{
    switch ( item )
    {
        case 1:
        case 2:
        case 3:
        case 4:
            cout << "you selected main menu item " << item << endl;
            break;
        case 5:
            exit( 0 );
            break;
        default:    // should not occur
            cout << "invalid main menu item " << item << endl;
            break;
    }
}

// SubMenuHandler() controls the submenu
// only action is to print selected submenu entry
void SubMenuHandler( int item )
{
    switch ( item )
    {
        case 1:
        case 2:
        case 3:
        case 4:
            cout << "you selected submenu item " << item << endl;
            break;
        default:    // should not occur
            cout << "invalid submenu item " << item << endl;
            break;
    }
}
