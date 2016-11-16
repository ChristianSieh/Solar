#include "Main.h"

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
    glutAddMenuEntry("Flat Shaded Models", value++);
    glutAddMenuEntry("Smooth Shaded Models", value++);
    glutAddSubMenu("Planets", planetMenu);
    glutAddMenuEntry("Reset Camera", value++);
    glutAddMenuEntry("Reset Planets", value++);
    glutAddMenuEntry("Exit Program", value++);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void MainMenuHandler( int item )
{
    switch ( item )
    {
        // Switch to wireframe
        case 1:
            
            break;

        // Switch to flat shading
        case 2:
            
            break;

        // Switch to smooth shading
        case 3:
            
            break;

        // Reset Camera
        case 4:
            
            break;

        // Reset Planets
        case 5:
            
            break;

        // Exit
        case 6:
            exit( 0 );
            break;

        default:    // should not occur
            cout << "Invalid Menu Selection" << item << endl;
            break;
    }
}

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
