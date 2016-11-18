 /************************************************************************
   Program: Solar
   Author: Charles Bonn and Christian Sieh
   Class: CSC433 Computer Graphics
   Instructor: John Weiss
   Date:
   Description:   Events handles all keyboard and mouse presses of the
	program
   Known bugs/missing features:
   Modifications:
   Date                Comment            
   ----    ------------------------------------------------
 ************************************************************************/
#include "Main.h"

 /************************************************************************
   Function: KeyPressFunc
   Author: Charles Bonn and Christian Sieh
   Description: reads normal key presses and handles them
   Parameters:
	unsigned char Key - the key that is pressed
	int x - x position of where the key was pressed
	int y - y position of where the key was pressed
 ************************************************************************/
void KeyPressFunc( unsigned char Key, int x, int y )
{
    switch ( Key )
    {
        case 'R':
        case 'r':
            Key_r();
            break;
        case 's':
        case 'S':
            Key_s();
            break;
        case 27: 	// Escape key
            exit( 1 );
    }
}

// glutSpecialFunc is called to set this function to handle all special key presses
// See glut.h for the names of special keys.
 /************************************************************************
   Function:
   Author:
   Description: glutSpecialFunc is called to set this function to handle 
	all special key presses
   Parameters:
	int Key - key that was pressed
	int x - x position of where the key was pressed
	int y - y position of where the key was pressed
 ************************************************************************/
void SpecialKeyFunc( int Key, int x, int y )
{
    switch ( Key )
    {
        case GLUT_KEY_UP:
            Key_up();
            break;
        case GLUT_KEY_DOWN:
            Key_down();
            break;
	case GLUT_KEY_LEFT:
	    Key_left();
	    break;
	case GLUT_KEY_RIGHT:
	    Key_right();
	    break;
    }

    glutPostRedisplay();
}

// restart animation
 /************************************************************************
   Function:
   Author:
   Description:
   Parameters:
 ************************************************************************/
void Key_r( void )
{
    if ( singleStep )
    {			// If ending single step mode
        singleStep = GL_FALSE;
        spinMode = GL_TRUE;		// Restart animation
    }
    else
    {
        spinMode = !spinMode;	// Toggle animation on and off.
    }
}

// single step animation
 /************************************************************************
   Function:
   Author:
   Description:
   Parameters:
 ************************************************************************/
void Key_s( void )
{
    singleStep = GL_TRUE;
    spinMode = GL_TRUE;
}

 /************************************************************************
   Function: Key_up
   Author: Charles Bonn and Christian Sieh
   Description: handes right key press by moving the camra 
   Parameters: void
 ************************************************************************/
void Key_up( void )
{
    AnimateIncrement *= 2.0;			// Double the animation time step
}

 /************************************************************************
   Function: Key_down
   Author: Charles Bonn and Christian Sieh
   Description: handes right key press by moving the camra 
   Parameters: void
 ************************************************************************/
void Key_down( void )
{
    AnimateIncrement /= 2.0;			// Halve the animation time step
}

 /************************************************************************
   Function: Key_left
   Author: Charles Bonn and Christian Sieh
   Description: handes right key press by moving the camra 
   Parameters: void
 ************************************************************************/
void Key_left( void )
{
    //update camera position
    float y = lookat[0].value - lookat[0].step;
    update(&lookat[0], y);
    //update camra target
    y = lookat[3].value - lookat[3].step;
    update(&lookat[3], y);
}

 /************************************************************************
   Function: Key_right
   Author: Charles Bonn and Christian Sieh
   Description: handes right key press by moving the camra 
   Parameters: void
 ************************************************************************/
void Key_right( void )
{
    //update camra position
    float y =  lookat[0].value  + lookat[0].step;
    update(&lookat[0], y);
    //update camra target
    y =  lookat[3].value   +  lookat[3].step;
    update(&lookat[3], y);
}

 /************************************************************************
   Function: update
   Author: Charles Bonn and Christian Sieh
   Description: Updates cells making sure they are within there specified
	min and max values
   Parameters:
	cell* cell - current cell being miniplated
	flaot y - change value for cell
 ************************************************************************/
void update(cell* cell, float y)
{
    if( cell->value < cell->min )
    {
	cell->value = cell->min;
    }
    else if( cell->value > cell->max )
    {
	cell->value = cell->max;
    }
    else
    {
	cell->value = y;
    }
}
