 /************************************************************************
   Program: Solar
   Author: Charles Bonn and Christian Sieh
   Class: CSC433 Computer Graphics
   Instructor: John Weiss
   Date: 11/18/16
   Description:   Events handles all keyboard and mouse presses of the
	program
 ************************************************************************/
#include "Main.h"

int mouseX = ScreenWidth / 2.0;
int mouseY = ScreenHeight / 2.0;
int xOffset;
int yOffset;
GLfloat yaw;
GLfloat pitch;

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
	case 'c':
	case 'C':
	    Key_c();
	    break;
	case 'v':
	case 'V':
	    Key_v();
	    break;
        case 'z':
	case 'Z':
            Key_z();
	    break;
        case 'x':
	case 'X':
	    Key_x();
	    break;
        case 32:
	    Key_space();
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
   Function: key_r
   Author: Charles BOnn
   Description: Starts and stops animation
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
  /************************************************************************
   Function: key_a
   Author: Charles Bonn and Christian Sieh
   Description: changes wireframe
   Parameters:
 ************************************************************************/
void Key_v( void )
{
   if( wireframe < 50 )
   {
       wireframe += 1.0; // half amimation step
   }
}

/************************************************************************
   Function: key_c
   Author: Charles Bonn and Christian Sieh
   Description: changes wireframe
   Parameters:
 ************************************************************************/
void Key_c( void )
{
   if( wireframe > 2 )
   {
   	wireframe -= 1.0; // half amimation step
   }
}


 /************************************************************************
   Function: key_z
   Author: charles bonn and christian Sieh
   Description: changes animation speed
   Parameters:
 ************************************************************************/
void Key_z( void )
{
   AnimateIncrement /= 2.0; // half amimation step
}

/************************************************************************
   Function: key_x
   Author: Charles Bonn and Christian Sieh
   Description: changes animation speed
   Parameters:
 ************************************************************************/
void Key_x( void )
{
    AnimateIncrement *= 2.0; // double animation step
}
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
   Function:
   Author:
   Description:
   Parameters:
 ************************************************************************/
void Key_space( void )
{
    for( int i = 0; i < 9; i++ )
    {
        lookat[i].value = lookat[i].reset;
    }
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
    float y = lookat[1].value - (lookat[1].step * lookat[2].value);
    update(&lookat[1], y);
    //update camra target
    y = lookat[4].value - ( lookat[4].step * lookat[2].value );
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
    //update camera target
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

 /************************************************************************
   Function: mouseclick
   Author: Charles Bonn and Christian Sieh
   Description: handles mouse clicks   
   Parameters: 
        int button - Which mouse button was pressed
		int state - The state of mouse button
		int x - The x coordinate of where the mouse was clicked
		int y - The y coordinate of where the mouse was clicked
 ************************************************************************/
void mouseclick( int button, int state, int x, int y )
{
    // correct for upside-down screen coordinates
    y = ScreenHeight - y;

    // handle mouse click events
    switch ( button )
    {
        case GLUT_LEFT_BUTTON:
            if ( state == GLUT_DOWN )
            {
                mouseX = x;
                mouseY = y;		    
            }
            else if ( state == GLUT_UP )
            {
                mouseX = 0;
                mouseY = 0;
            }
            break;

        case GLUT_RIGHT_BUTTON:
            break;
    }
}

 /************************************************************************
   Function: mousedrag
   Author: Christian Sieh
   Description: GLUT motionfunc that handles when the mouse is clicked and 
                dragged across the screen to get the mouse position.
   Parameters: 
		int x - The x coordinate of where the mouse is currently
		int y - The y coordinate of where the mouse is currently
 ************************************************************************/
void mousedrag(int x, int y)
{
    y = ScreenHeight - y;

    xOffset = x - mouseX;
    yOffset = y - mouseY;

    GLfloat sensitivity = 0.5f;
    xOffset *= sensitivity;
    yOffset *= sensitivity;

    yaw = xOffset;
    pitch = yOffset;

    if(pitch > 89.0f)
      pitch =  89.0f;
    if(pitch < -89.0f)
      pitch = -89.0f;

    GLfloat dir[3];

    dir[0] = cos(pitch * (M_PI / 180)) * cos(yaw * (M_PI / 180));
    dir[1] = sin(pitch * (M_PI / 180));
    dir[2] = cos(pitch * (M_PI / 180)) * sin(yaw * (M_PI / 180));

    normalize(dir);

    x = lookat[3].value + (xOffset * dir[0]);
    update(&lookat[3], x);

    y = lookat[4].value + (yOffset * dir[1]);
    update(&lookat[4], y);

    GLfloat z = lookat[5].value + dir[2];
    update(&lookat[5], z);

    glutPostRedisplay();
}

 /************************************************************************
   Function: normalize
   Author: Christian Sieh
   Description: Function that normalizes a vector
   Parameters: 
		GLfloat dir[3] - An array that contains the x, y, and z of a
                            vector
 ************************************************************************/
void normalize(GLfloat (&dir)[3])
{
    GLfloat xSqr = dir[0] * dir[0];
    GLfloat ySqr = dir[1] * dir[1];
    GLfloat zSqr = dir[2] * dir[2];

    GLfloat total = xSqr + ySqr + zSqr;

    total = sqrt(total);

    dir[0] = dir[0] / total;
    dir[1] = dir[1] / total;
    dir[2] = dir[2] / total;
}
