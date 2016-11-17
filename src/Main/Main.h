#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
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

// View Info
struct cell
{
    int id;
    int x, y;
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

// Display
void Animate( void );
void ResizeWindow( int w, int h);

// Events
void Key_r( void );
void Key_s( void );
void Key_up( void );
void Key_down( void );
void Key_left( void );
void Key_right( void );
void KeyPressFunc( unsigned char Key, int x, int y );
void SpecialKeyFunc( int Key, int x, int y );
void update(cell* cell, float y);

// Menu
void createMenu();
void MainMenuHandler( int item );
void PlanetMenuHandler( int item );

#endif 
