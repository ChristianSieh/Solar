#include "Main.h"

// glutKeyboardFunc is called to set this function to handle normal key presses.
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
void Key_s( void )
{
    singleStep = GL_TRUE;
    spinMode = GL_TRUE;
}

// animation speed
void Key_up( void )
{
    AnimateIncrement *= 2.0;			// Double the animation time step
}

// animation speed
void Key_down( void )
{
    AnimateIncrement /= 2.0;			// Halve the animation time step
}

void Key_left( void )
{
    float y = lookat[0].value - lookat[0].step;
    update(&lookat[0], y);
       
    y = lookat[3].value - lookat[3].step;
    update(&lookat[3], y);
}

void Key_right( void )
{
    
    float y =  lookat[0].value  + lookat[0].step;
    update(&lookat[0], y);
    
    y =  lookat[3].value   +  lookat[3].step;
    update(&lookat[3], y);
}

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
