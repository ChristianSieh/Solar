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

	case 45:
	    Key_minus();
	    break;
	case 61:
 	case 43:
	    Key_plus();
	    break;
        case 27: 	// Escape key
            exit( 1 );
    }

    glutPostRedisplay();
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
    {			
        // If ending single step mode
        singleStep = GL_FALSE;
        // Restart animation
        spinMode = GL_TRUE;		
    }
    else
    {
        // Toggle animation on and off.
        spinMode = !spinMode;	
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
    //update camera position
    float y = lookat[1].value + ( lookat[1].step * lookat[2].value );
    update(&lookat[1], y);
    //update camra target
    y = lookat[4].value + ( lookat[4].step * lookat[2].value );
    update(&lookat[4], y);
}

 /************************************************************************
   Function: Key_down
   Author: Charles Bonn and Christian Sieh
   Description: handes right key press by moving the camra 
   Parameters: void
 ************************************************************************/
void Key_down( void )
{
    //update camera position
    float y = lookat[1].value - lookat[1].step;
    update(&lookat[1], y);
    //update camra target
    y = lookat[4].value - lookat[4].step;
    update(&lookat[4], y);
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
    float y = lookat[0].value - (lookat[0].step * lookat[2].value );
    update(&lookat[0], y);
    //update camra target
    y = lookat[3].value - ( lookat[3].step * lookat[2].value );
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
    float y =  lookat[0].value  + ( lookat[0].step * lookat[2].value );
    update(&lookat[0], y);
    //update camra target
    y =  lookat[3].value   +  ( lookat[3].step * lookat[2].value );
    update(&lookat[3], y);
}

 /************************************************************************
   Function: Key_minus
   Author: Charles Bonn and Christian Sieh
   Description: handles the minues key pres and impliments zoom
   Parameters:
 ************************************************************************/
void Key_minus( void )
{
    float y = lookat[2].value + ( lookat[2].step * lookat[2].value );
    update(&lookat[2], y);
}

 /************************************************************************
   Function: Key_plus
   Author: Charles Bonn and Christian Sieh
   Description: handles the + key press and impliments zoom
   Parameters:
 ************************************************************************/
void Key_plus( void ) 
{
    float y = lookat[2].value - ( lookat[2].step * lookat[2].value );
    update(&lookat[2],y );
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
    if( y < cell->min )
    {
	cell->value = cell->min;
    }
    else if( y > cell->max )
    {
	cell->value = cell->max;
    }
    else
    {
	cell->value = y;
    }
}
