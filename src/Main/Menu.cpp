 /************************************************************************
   Program: Solar 
   Author: Charles Bonn and Christian Sieh
   Date:
   Description:   Handles the menu creation for the program
   Known bugs/missing features:
   Modifications:
   Date                Comment            
   ----    ------------------------------------------------
 ************************************************************************/
#include "Main.h"

 /************************************************************************
   Function: createMenu
   Author: Charles Bonn and Christian Sieh
   Description: creates the right click menu for the program
   Parameters:
 ************************************************************************/
void createMenu()
{       
    int value = 1;
    int planetMenu = glutCreateMenu(PlanetMenuHandler);

    for(auto & obj: shapeList)
    {
	    glutAddMenuEntry(obj->name.c_str(), value++);
    }

    value = 1;
    glutCreateMenu(MainMenuHandler);
    glutAddMenuEntry("Wireframe Models", value++);
    glutAddMenuEntry("Solid Models", value++);
    glutAddMenuEntry("Flat Shadeing", value++);
    glutAddMenuEntry("Smooth Shadeing", value++);
    glutAddMenuEntry("Textures On", value++);
    glutAddMenuEntry("Textures Off", value++);
    glutAddSubMenu("Planets", planetMenu);
    glutAddMenuEntry("Reset Camera", value++);
    glutAddMenuEntry("Reset Solar System", value++);
    glutAddMenuEntry("Exit Program", value++);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

 /************************************************************************
   Function: MainMenuHandler
   Author: Charles Bonn and Christian Sieh
   Description: Handles Menu options
   Parameters:
	int item - the menu option pressed
 ************************************************************************/
void MainMenuHandler( int item )
{
    switch ( item )
    {
        // Switch to wireframe modesl
        case 1:
            solid = false;            
            break;

        // Switch to solid models
        case 2:
            solid = true;
            break;

        // Switch to flat shading
        case 3:
            smooth = false;
            break;

        // Switch to smooth shading
        case 4:
            smooth = true;
            break;

        // Turn textures on
        case 5:
            texture = true;
            break;

        // Turn textures off
        case 6:
            texture = false;
            break;

        // Reset Camera
        case 7:
            
            break;

        // Reset Solar System
        case 8:
            
            break;

        // Exit
        case 9:
            exit( 0 );
            break;

        // should not occur
        default:
            cout << "Invalid Menu Selection" << item << endl;
            break;
    }
}

 /************************************************************************
   Function: PlanetMenuHandler
   Author: Charles Bonn and Christian Sieh
   Description: Handles the planet subment
   Parameters:
	int item - item being selected
 ************************************************************************/
void PlanetMenuHandler( int item )
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
