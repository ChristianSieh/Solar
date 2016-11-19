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
    int helpMenu = glutCreateMenu(HelpMenuHandler);

    glutAddMenuEntry("Up Key - Pan Up", value++);
    glutAddMenuEntry("Down Key - Pan Down", value++);
    glutAddMenuEntry("Left Key - Pan Left", value++);
    glutAddMenuEntry("Right Key - Pan Right", value++);
    glutAddMenuEntry("R Key - Start/Stop Animation", value++);
    glutAddMenuEntry("S Key - Single Step Animation", value++);
    glutAddMenuEntry("Space Key - Reset Camera", value++);
    glutAddMenuEntry("- Key - Zoom Out", value++);
    glutAddMenuEntry("+ Key - Zoom In", value++);
    glutAddMenuEntry("V Key - Increase Wireframe Resolution", value++);
    glutAddMenuEntry("C Key - Decrease Wireframe Resolution", value++);

    value = 1;
    glutCreateMenu(MainMenuHandler);
    glutAddMenuEntry("Wireframe Models", value++);
    glutAddMenuEntry("Solid Models", value++);
    glutAddMenuEntry("Flat Shadeing", value++);
    glutAddMenuEntry("Smooth Shadeing", value++);
    glutAddMenuEntry("Textures On", value++);
    glutAddMenuEntry("Textures Off", value++);
    glutAddMenuEntry("Reset Camera", value++);
    glutAddSubMenu("Help", helpMenu);
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
            for( int i = 0; i < 9; i++ )
            {
                lookat[i].value = lookat[i].reset;
            }
            break;

        // Exit
        case 8:
            exit( 0 );
            break;

        // should not occur
        default:
            cout << "Invalid Menu Selection" << item << endl;
            break;
    }
}

 /************************************************************************
   Function: HelpMenuHandler
   Author: Charles Bonn and Christian Sieh
   Description: A submenu to show the keybindings used in the program
   Parameters:
	int item - item being selected
 ************************************************************************/
void HelpMenuHandler( int item )
{
}
