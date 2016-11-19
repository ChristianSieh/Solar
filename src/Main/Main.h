 /************************************************************************
   Program: Solar 
   Author: Charles Bonn and Christian Sieh
   Date: 11/18/16
   Description: Main header file for the program. Contains global variables
            and functions.
 ************************************************************************/
#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <math.h>
#include <vector>
#include <GL/freeglut.h>

//shape classes
#include "../Shape/Shape.h"
#include "../Shape/Orb.h"
#include "../Shape/Sun.h"
#include "../Shape/Planet.h"

// Global variables
extern GLenum spinMode;
extern GLenum singleStep;
extern vector<Shape*> shapeList;
extern bool solid;
extern bool smooth;
extern bool texture;
extern GLsizei ScreenWidth;
extern GLsizei ScreenHeight;

// View Info cell
struct cell
{
    int id;
    float reset;
    float min, max;
    float value;
    float step;
    string info;
    string format;
};

extern cell lookat[9];
extern cell perspective[4];
extern GLenum viewMode;

// These three variables control the animation's state and speed
extern float HourOfDay;
extern float currDay;
extern float AnimateIncrement;  // Time step for animation (hours)
extern float wireframe;

// Display
void Animate( void );
void ResizeWindow( int w, int h);
void lightModel();

// Events
void Key_c( void );
void Key_v( void );
void Key_z( void );
void Key_x( void );
void Key_r( void );
void Key_s( void );
void Key_up( void );
void Key_down( void );
void Key_left( void );
void Key_right( void );
void Key_minus( void );
void Key_plus( void );
void Key_space( void );
void KeyPressFunc( unsigned char Key, int x, int y );
void SpecialKeyFunc( int Key, int x, int y );
void update(cell* cell, float y);
void mouseclick( int button, int state, int x, int y );
void mousedrag(int x, int y);
void normalize(GLfloat (&dir)[3]);

// Menu
void createMenu();
void MainMenuHandler( int item );
void HelpMenuHandler( int item );

#endif 
